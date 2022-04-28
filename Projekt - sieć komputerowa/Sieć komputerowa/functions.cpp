/** @file */
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

#include "structs.h"
#include "functions.h"

int checkArguments(int argc, char**& argv, std::string& coorName, std::string& tabName, std::string& outName) {
	if (argc != 7) {
		std::cerr << "Not enough arguments to run program, it must look like that: -coor name.txt -tab name.txt -out name.txt";
		return EXIT_FAILURE;
	}
	else {
		int i = 1;
		do {
			std::string arg = argv[i];
			std::string name = argv[i + 1];

			if (arg == "-coor") {
				if (coorName != "") {
					std::cerr << "You cant inicialize two the same arguments!!!";
					return EXIT_FAILURE;
				}
				coorName = argv[i + 1];
				i += 2;
			}
			else if (arg == "-tab") {
				if (tabName != "") {
					std::cerr << "You cant inicialize two the same arguments!!!";
					return EXIT_FAILURE;
				}
				tabName = argv[i + 1];
				i += 2;
			}
			else if (arg == "-out") {
				if (outName != "") {
					std::cerr << "You cant inicialize two the same arguments!!!";
					return EXIT_FAILURE;
				}
				outName = argv[i + 1];
				i += 2;
			}
			else {
				std::cerr << "Wrong use of arguments it must look like that: -coor name.txt -tab name.txt -out name.txt";
				return EXIT_FAILURE;
			}
		} while (i < 7);
	}

	if (!std::ifstream(coorName)) {
		std::cerr << "File " << coorName << " can't be opened!!!";
		return EXIT_FAILURE;
	}
	if (!std::ifstream(tabName)) {
		std::cerr << "File " << tabName << " can't be opened!!!";
		return EXIT_FAILURE;
	}
	if (!std::ifstream(coorName, std::ios::ate).tellg()) {
		std::cerr << "File " << coorName << " is empty" << std::endl;
		return EXIT_FAILURE;
	}
	if (!std::ifstream(tabName, std::ios::ate).tellg()) {
		std::cerr << "File " << tabName << " is empty" << std::endl;
		return EXIT_FAILURE;
	}
}

void readCoorName(const std::string& coorName, coorList*& head) {
	int _index = 0, _v = 0, _w = 0;
	std::string _surname;
	int i = 0;

	std::ifstream file(coorName);

	std::stringstream allFile;
	std::string line;

	while (std::getline(file, line)) { //wczytywanie ca³ego pliku do buffora allFile
		allFile << line << '\n';
	}
	file.close();

	while (allFile >> line) { //sprawdzenie która dana zosta³a wczytana
		switch (i) {
		case 0: _index = std::stoi(line);
			i++;
			break;
		case 1: _surname = line;
			i++;
			break;
		case 2: _v = std::stoi(line);
			i++;
			break;
		case 3: _w = std::stoi(line);
			i++;
			break;
		default: std::cout << "Some error in switch in function readCoorName!!!";
		}
		if (i == 4) {
			{
				addToCoorList(head, _index, _surname, _v, _w);
				i = 0;
			}
		}
	}
}

void addToCoorList(coorList*& head, int _index, std::string _surname, int _v, int _w) {
	if (head == nullptr) {
		head = new coorList{ new coordinates(_v, _w, _index, _surname), nullptr };
	}
	else {
		coorList* tempC_Head = head;
		while (tempC_Head->next) {
			tempC_Head = tempC_Head->next;
		}
		tempC_Head->next = new coorList{ new coordinates(_v, _w, _index, _surname), nullptr };
	}
}

void  readTabName(const std::string& tabName, std::vector <std::pair<int, int>>& tabVector) {
	int size = 0;

	std::ifstream file(tabName);

	std::stringstream allFile;
	std::string line;
	std::string line2;

	while (std::getline(file, line)) {
		allFile << line << '\n';
		size++;
	}
	file.close();

	tabVector.reserve(size);
	while (allFile >> line >> line2) { //wczytanie z buforu obu mieszkañ
		if (std::stoi(line) < std::stoi(line2))
		{
			addToTabVector(tabVector, std::stoi(line), std::stoi(line2));
		}
		else {
			addToTabVector(tabVector, std::stoi(line2), std::stoi(line));
		}
	}
	std::sort(tabVector.begin(), tabVector.end());
}

void addToTabVector(std::vector <std::pair<int, int>>& tabVector, int _x, int _y) {
	tabVector.push_back(std::pair<int, int>(_x, _y));
}

void fillQueque(std::vector < std::pair<int, std::pair<int, int> > >& Q, coorList* cHead, std::vector <std::pair<int, int>> tabVector) {
	coorList* tempMainElement = cHead;
	coorList* tempSecondaryElement = cHead->next;
	int main = 1;
	int secondary = 2;
	int i = 0;
	int N = 0;
	int isTab = 1;

	while (tempMainElement->next) {	//dopóki nie jest to przedostatni element
		while (tempSecondaryElement) {	//dopóki nie jest to ostatni element
			isTab = 1;
			i = N;
			while (i < tabVector.size() && main >= tabVector[i].first) {	//przechodzenie przez vector z niemo¿liwymi po³¹czeniami
				if (secondary == tabVector[i].second) {
					i++;
					isTab = 0;
					N = i;	//vector jest posortowany wiêc przeszukiwanie jego mniejszej czêœci mo¿na pomin¹æ przy dalszych indeksach mieszkania
					break;
				}
				i++;
			}
			if (isTab) {
				Q.push_back(std::pair<int, std::pair<int, int>>(howFar(tempMainElement->coords, tempSecondaryElement->coords), std::make_pair(main, secondary)));
			}
			tempSecondaryElement = tempSecondaryElement->next;
			secondary++;
		}
		tempMainElement = tempMainElement->next; //przesuniêcie g³ównego mieszkania o jeden element
		tempSecondaryElement = tempMainElement->next;	//wybranie podrzêdnego mieszkania o jeden element dalej ni¿ g³ówne (reszte pomijamy gdy¿ ju¿ jest utworzona z nich kolejka)
		main++;
		secondary = main + 1;
	}
	std::sort(Q.rbegin(), Q.rend());	//posortowanie kolejki Q malej¹co
}

int howFar(coordinates* mainElement, coordinates* secondaryElement) {
	int road;

	road = abs(mainElement->sendV() - secondaryElement->sendV());
	road += abs(mainElement->sendW() - secondaryElement->sendW());

	return road;
}

void makeTheWeeb(std::vector < std::set< int > >& sets, std::vector<std::pair <int, std::pair<int, int> > >& Q, const std::string& outName) {
	std::ofstream filed(outName);	//wyczyszczenie pliku
	filed.close();
	std::ofstream file(outName, std::ios::app);

	int sum = 0;
	int ind = 1;
	int N = Q.size() - 1;
	int isInSet = 1;
	int firstIs = 0;
	int secondIs = 0;

	while (Q.size() != 0) {	//dopóki kolejka nie jest pusta
		isInSet = 1;
		firstIs = 0;
		secondIs = 0;

		for (int i = 0; i < sets.size(); i++) {
			if ((sets[i].find(Q[N].second.first) != sets[i].end()) && (sets[i].find(Q[N].second.second) != sets[i].end())) { //czy oba mieszkania s¹ w tym samym zbiorze
				isInSet = 0;
				break;
			}
		}
		if (isInSet) {
			for (int i = 0; i < sets.size(); i++) {
				if (sets[i].find(Q[N].second.first) != sets[i].end()) firstIs += 1;	//sprawdzenie czy mieszkanie jest w zbiorze
				if (sets[i].find(Q[N].second.second) != sets[i].end()) secondIs += 1;
			}
			if (firstIs && secondIs) { //gdy oba mieszkania maj¹ zbiory
				int s = 0;
				int m = 0;
				while (s < sets.size() && sets[s].find(Q[N].second.first) == sets[s].end()) {	//sprawdzenie w którym zbiorze jest mieszkanie
					s++;
				}
				while (m < sets.size() && sets[m].find(Q[N].second.second) == sets[m].end()) {
					m++;
				}
				std::set <int> temp;
				std::merge(sets[s].begin(), sets[s].end(), sets[m].begin(), sets[m].end(), std::inserter(temp, temp.begin()));	//po³¹czenie zbiorów
				sets.erase(sets.begin() + s);	//usuniêcie zbioru z vectora
				m = 0;
				while (m < sets.size() && sets[m].find(Q[N].second.second) == sets[m].end()) {	//po usuniêciu jednego z mieszkañ drugi zbiór mo¿e zmieniæ swoje miejsce, wiêc wyszukujemy go na nowo
					m++;
				}
				sets.erase(sets.begin() + m);
				sets.push_back(temp);	//dodanie po³¹czonego zbioru
			}
			else if (firstIs) {	//gdy pierwsze mieszkanie jest w zbiorze
				int s = 0;
				while (s < sets.size() && sets[s].find(Q[N].second.first) == sets[s].end()) {
					s++;
				}
				sets[s].insert(Q[N].second.second);
			}
			else if (secondIs) {	//gdy drugie mieszkanie jest w zbiorze
				int s = 0;
				while (s < sets.size() && sets[s].find(Q[N].second.second) == sets[s].end()) {
					s++;
				}
				sets[s].insert(Q[N].second.first);
			}
			else {	//gdy ¿adne z mieszkañ nie jest w zbiorze -> dodanie nowego zbioru
				std::set <int> temp;
				temp.insert(Q[N].second.first);
				temp.insert(Q[N].second.second);
				sets.push_back(temp);
			}

			sum += Q[N].first;	//suma d³ugoœci po³¹czeñ
			file << ind << ".  " << Q[N].second.first << " <-> " << Q[N].second.second << "  sum: " << sum << '\n';	//wpisanie do pliku
			ind++;
		}

		N--;	//usuwamy ostatni element -> przesuwamy siê na kolejny
		Q.pop_back();	//usuniêcie ostatniego (najmniejszego) elementu z kolejki
	}
	file.close();
}

void eraseList(coorList* cHead) {	//rekurencyjne usuwanie listy i obiektów
	while (cHead) {
		eraseList(cHead->next);
		delete cHead->coords;
		cHead->coords = nullptr;
		delete cHead;
		cHead = nullptr;
	}
}
/** @file */
/*
Projekt PK3 - Sie� komputerowa
*/
//projekt uruchamiany z komend� -coor wsp.txt -tab blok.txt -out out.txt  ->ustawion� we w�a�ciwo�ciach projektu
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <vector>
#include <set>

#include "structs.h"
#include "functions.h"

int main(int argc, char** argv) {
	std::string coorName = "";
	std::string tabName = "";
	std::string outName = "";

	checkArguments(argc, argv, coorName, tabName, outName); //sprawdzenie argument�w podanych z konsoli

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	coorList* cHead = nullptr;
	std::vector <std::pair<int, int>> tabVector;

	readCoorName(coorName, cHead);	//wczytanie mieszka�c�w i ich po�o�enia do listy jednokierunkowej
	readTabName(tabName, tabVector);	//wczytywanie zablokowanych po��cze�

	std::vector < std::pair<int, std::pair<int, int> > >  Q;

	fillQueque(Q, cHead, tabVector);	//zape�nianie kolejki Q odcinkami z wykluczeniem niemo�liwych do zrealizowania i posortowanie jej malej�co

	std::vector < std::set< int > > sets;

	makeTheWeeb(sets, Q, outName);		//wypisanie po��cze� tworz�cych najlepsze po��czenie sieci komputerowej w bloku

	eraseList(cHead);					//zwalnianie pami�ci (usuwanie listy)

	return 0;
}
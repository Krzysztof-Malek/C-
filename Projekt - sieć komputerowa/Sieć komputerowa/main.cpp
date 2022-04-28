/** @file */
/*
Projekt PK3 - Sieæ komputerowa
*/
//projekt uruchamiany z komend¹ -coor wsp.txt -tab blok.txt -out out.txt  ->ustawion¹ we w³aœciwoœciach projektu
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

	checkArguments(argc, argv, coorName, tabName, outName); //sprawdzenie argumentów podanych z konsoli

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	coorList* cHead = nullptr;
	std::vector <std::pair<int, int>> tabVector;

	readCoorName(coorName, cHead);	//wczytanie mieszkañców i ich po³o¿enia do listy jednokierunkowej
	readTabName(tabName, tabVector);	//wczytywanie zablokowanych po³¹czeñ

	std::vector < std::pair<int, std::pair<int, int> > >  Q;

	fillQueque(Q, cHead, tabVector);	//zape³nianie kolejki Q odcinkami z wykluczeniem niemo¿liwych do zrealizowania i posortowanie jej malej¹co

	std::vector < std::set< int > > sets;

	makeTheWeeb(sets, Q, outName);		//wypisanie po³¹czeñ tworz¹cych najlepsze po³¹czenie sieci komputerowej w bloku

	eraseList(cHead);					//zwalnianie pamiêci (usuwanie listy)

	return 0;
}
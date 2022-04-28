/** @file */
#include <iostream>

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

/** Funkcja sprawdza argumenty podane w konsoli przy uruchomieniu programu
@param argc iloœæ wyrazów pobrana z konsoli
@param argv wyrazy pobrane z konsoli
@param coorName nazwa pliku ze wspó³rzêdnymi
@param tabName nazwa pliku z niemo¿liwymi po³¹czeniami
@param outName nazwa pliku wyjœciowego
@return int
*/
int checkArguments(int argc, char**& argv, std::string& coorName, std::string& tabName, std::string& outName);

/** Funkcja wczytuj¹ca plik ze wspó³rzêdnymi do listy
@param coorName nazwa pliku
@param head g³owa listy na wspó³rzêdne mieszkañców (pocz¹tkowo nullptr)
@return void
*/
void readCoorName(const std::string& coorName, coorList*& head);

/** Funkcja tworz¹ca obiekt coordinates i dodajaca go do listy
@param head g³owa listy
@param _index dana index do utworzenia obiektu
@param _surname nazwisko
@param _v wpó³rzêdna v
@param _w wspó³rzêdna w
@return void
*/
void addToCoorList(coorList*& head, int _index, std::string _surname, int _v, int _w);

/** Fubnkcja wczytuj¹ca plik z niemo¿liwymi po³¹czeniami wpisuj¹ca je do vectora par intów i sortuj¹ca go malej¹ca
@param tabName nazwa pliku z niemo¿liwymi po³¹czeniami
@param tabVector vector z par¹ intów niemo¿liwych do po³¹czenia mieszkañ
@return void
*/
void readTabName(const std::string& tabName, std::vector <std::pair<int, int>>& tabVector);

/** Funkcja dodaj¹ca element do vectora z niemo¿liwymi po³¹czeniami
@param tabVector vector par intów
@param _x mieszkanie 1
@param _y mieszkanie 2
@return void
*/
void addToTabVector(std::vector <std::pair<int, int>>& tabVector, int _x, int _y);

/** Funkcja zape³niaj¹ca i sortuj¹ca kolejkê Q wykorzystywan¹ przez algorytm kruskala
@param Q vector par int par intów reprezentuj¹cy odleg³oœæ i mieszkania miêdzy którymi mo¿emy zrobiæ po³¹czenie
@param cHead g³owa listy na kolejne obiekty coordinates
@return void
*/
void fillQueque(std::vector < std::pair<int, std::pair<int, int> > >& Q, coorList* cHead, std::vector <std::pair<int, int>> tabVector);

/** Funkcja licz¹ca odleg³oœæ miêdzy mieszkaniami id¹c po prostych
@param mainElement wska¿nik na obiekt 1 mieszkania
@param secondaryElement wska¿nik na obiekt 2 mieszkania
@return int
*/
int howFar(coordinates* mainElement, coordinates* secondaryElement);

/** Funkcja wpisuj¹ca do pliku kolejne po³¹czenia miêdzy mieszkaniami wraz z sumaryczn¹ d³ugoœci¹ kabli przy ka¿dym nowym po³¹czeniu
@param sets vector zbiorów mieszkañ dziêki którym eliminujemy pêtle
@param Q vector par int par intów reprezentuj¹cy odleg³oœæ i mieszkania miêdzy którymi mo¿emy zrobiæ po³¹czenie
@param outName nazwa pliku wyjœciowego
@return void
*/
void makeTheWeeb(std::vector < std::set< int > >& sets, std::vector<std::pair <int, std::pair<int, int> > >& Q, const std::string& outName);

/** Funkcja zwalniaj¹ca pamiêæ z listy wska¿ników na obiekty
@param cHead wska¿nik na kolejne elementy listy
@return void
*/
void eraseList(coorList* cHead);

#endif
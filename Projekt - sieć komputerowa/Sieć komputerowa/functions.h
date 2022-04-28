/** @file */
#include <iostream>

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

/** Funkcja sprawdza argumenty podane w konsoli przy uruchomieniu programu
@param argc ilo�� wyraz�w pobrana z konsoli
@param argv wyrazy pobrane z konsoli
@param coorName nazwa pliku ze wsp�rz�dnymi
@param tabName nazwa pliku z niemo�liwymi po��czeniami
@param outName nazwa pliku wyj�ciowego
@return int
*/
int checkArguments(int argc, char**& argv, std::string& coorName, std::string& tabName, std::string& outName);

/** Funkcja wczytuj�ca plik ze wsp�rz�dnymi do listy
@param coorName nazwa pliku
@param head g�owa listy na wsp�rz�dne mieszka�c�w (pocz�tkowo nullptr)
@return void
*/
void readCoorName(const std::string& coorName, coorList*& head);

/** Funkcja tworz�ca obiekt coordinates i dodajaca go do listy
@param head g�owa listy
@param _index dana index do utworzenia obiektu
@param _surname nazwisko
@param _v wp�rz�dna v
@param _w wsp�rz�dna w
@return void
*/
void addToCoorList(coorList*& head, int _index, std::string _surname, int _v, int _w);

/** Fubnkcja wczytuj�ca plik z niemo�liwymi po��czeniami wpisuj�ca je do vectora par int�w i sortuj�ca go malej�ca
@param tabName nazwa pliku z niemo�liwymi po��czeniami
@param tabVector vector z par� int�w niemo�liwych do po��czenia mieszka�
@return void
*/
void readTabName(const std::string& tabName, std::vector <std::pair<int, int>>& tabVector);

/** Funkcja dodaj�ca element do vectora z niemo�liwymi po��czeniami
@param tabVector vector par int�w
@param _x mieszkanie 1
@param _y mieszkanie 2
@return void
*/
void addToTabVector(std::vector <std::pair<int, int>>& tabVector, int _x, int _y);

/** Funkcja zape�niaj�ca i sortuj�ca kolejk� Q wykorzystywan� przez algorytm kruskala
@param Q vector par int par int�w reprezentuj�cy odleg�o�� i mieszkania mi�dzy kt�rymi mo�emy zrobi� po��czenie
@param cHead g�owa listy na kolejne obiekty coordinates
@return void
*/
void fillQueque(std::vector < std::pair<int, std::pair<int, int> > >& Q, coorList* cHead, std::vector <std::pair<int, int>> tabVector);

/** Funkcja licz�ca odleg�o�� mi�dzy mieszkaniami id�c po prostych
@param mainElement wska�nik na obiekt 1 mieszkania
@param secondaryElement wska�nik na obiekt 2 mieszkania
@return int
*/
int howFar(coordinates* mainElement, coordinates* secondaryElement);

/** Funkcja wpisuj�ca do pliku kolejne po��czenia mi�dzy mieszkaniami wraz z sumaryczn� d�ugo�ci� kabli przy ka�dym nowym po��czeniu
@param sets vector zbior�w mieszka� dzi�ki kt�rym eliminujemy p�tle
@param Q vector par int par int�w reprezentuj�cy odleg�o�� i mieszkania mi�dzy kt�rymi mo�emy zrobi� po��czenie
@param outName nazwa pliku wyj�ciowego
@return void
*/
void makeTheWeeb(std::vector < std::set< int > >& sets, std::vector<std::pair <int, std::pair<int, int> > >& Q, const std::string& outName);

/** Funkcja zwalniaj�ca pami�� z listy wska�nik�w na obiekty
@param cHead wska�nik na kolejne elementy listy
@return void
*/
void eraseList(coorList* cHead);

#endif
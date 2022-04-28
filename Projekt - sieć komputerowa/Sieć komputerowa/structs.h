/** @file */
#include <iostream>
#include <vector>

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

//Classes

/** Klasa przechowuj¹ca index, oraz nazwisko mieszkañców */
class inhabitants {
	int index;				///< index mieszkañca
	std::string surname;	///< nazwisko mieszkañca

public:
	inhabitants() :index(0), surname("x") {}	///< konstruktor bezargumentowy
	inhabitants(int _index, std::string _surname) :index(_index), surname(_surname) {} ///< konstruktor 2 argumentowy
	~inhabitants() {}	///< destruktor
};

/** Klasa przechowuj¹ca wspó³rzêdne mieszkañców - pochodna klasy inhabitants */
class coordinates :public inhabitants {
	int v, w;			///< wspó³rzêdne mieszkañców

public:
	coordinates() :v(0), w(0), inhabitants() {}	///< konstruktor bezargumentowy
	coordinates(int _v, int _w, int _index, std::string _surname) :v(_v), w(_w), inhabitants(_index, _surname) {}	///< konstruktor 4 argumentowy
	~coordinates() {}		///< destruktor

	int sendV() {	///< metoda zwracaj¹ca wspó³rzêdn¹ v
		return v;
	}

	int sendW() {	///< metoda zwracaj¹ca wspó³rzêdn¹ w
		return w;
	}
};

//Structures

/** Lista przechowujaca wska¿niki na obiekty coordinations */
struct coorList {
	coordinates* coords;	///< wska¿nik na obiekt coordinations
	coorList* next;			///< wska¿nik na nastêpny element listy
};

//Functions

#endif
/** @file */
#include <iostream>
#include <vector>

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

//Classes

/** Klasa przechowuj�ca index, oraz nazwisko mieszka�c�w */
class inhabitants {
	int index;				///< index mieszka�ca
	std::string surname;	///< nazwisko mieszka�ca

public:
	inhabitants() :index(0), surname("x") {}	///< konstruktor bezargumentowy
	inhabitants(int _index, std::string _surname) :index(_index), surname(_surname) {} ///< konstruktor 2 argumentowy
	~inhabitants() {}	///< destruktor
};

/** Klasa przechowuj�ca wsp�rz�dne mieszka�c�w - pochodna klasy inhabitants */
class coordinates :public inhabitants {
	int v, w;			///< wsp�rz�dne mieszka�c�w

public:
	coordinates() :v(0), w(0), inhabitants() {}	///< konstruktor bezargumentowy
	coordinates(int _v, int _w, int _index, std::string _surname) :v(_v), w(_w), inhabitants(_index, _surname) {}	///< konstruktor 4 argumentowy
	~coordinates() {}		///< destruktor

	int sendV() {	///< metoda zwracaj�ca wsp�rz�dn� v
		return v;
	}

	int sendW() {	///< metoda zwracaj�ca wsp�rz�dn� w
		return w;
	}
};

//Structures

/** Lista przechowujaca wska�niki na obiekty coordinations */
struct coorList {
	coordinates* coords;	///< wska�nik na obiekt coordinations
	coorList* next;			///< wska�nik na nast�pny element listy
};

//Functions

#endif
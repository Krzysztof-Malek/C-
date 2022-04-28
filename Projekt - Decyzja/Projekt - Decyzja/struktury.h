/** @file */
#include <iostream>

#ifndef _STRUKTURY_H_
#define _STRUKTURY_H_

/** Lista przechowuj¹ca wêz³y drzewa decyzji binarnej */
struct treeList {
	struct tree* root;		///< adres drzewa
	treeList* nextTree;		///< adres nastêpnego drzewa w liœcie
};

/** Drzewo decyzji binarnej */
struct tree
{
	int index;			///< wartoœæ indeksu wejœcia
	std::string attribute;		///< nazwa attrybutu do porównania
	char comp_sign;			///< znak porównania
	float requirement;		///< wartoœæ decyzyjna atrybutu
	std::string if_false;		///< indeks wyjœcia NIE
	std::string if_true;		///< indeks wyjœcia TAK
	tree* left;			///< adres lewego potomka
	tree* right;			///< adres prawego potomka
};

/** Lista etykiet ze wska¿nikami na listê wartoœci atrybutów  */
struct labelList
{
	std::string label;			///< nazwa etykiety
	struct measureList* measureHead;	///< adres pocz¹tku listy wartoœci atrybutów
	labelList* nextLabel;			///< adres nastêpnego elementu listy
};

/** Lista wartoœci atrybutów */
struct measureList
{
	std::string measure;	///< wartoœci atrybutów
	measureList* next;	///< adres nastêpnego elementu listy
};

#endif
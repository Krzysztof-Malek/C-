/** @file */
#include <iostream>

#ifndef _FUNKCJE_H_
#define _FUNKCJE_H_

/** Funkcja tworzy listê w której przechowywane bêd¹ wêz³y drzewa z pliku
@param headTreeList g³owa listy (pocz¹tkowo jest nullptr)
@param root korzeñ drzewa (pocz¹tkowo jest nullptr)
@param nameTreeStructFile nazwa pliku struktury drzewa
@return void
*/
void getTreeList(treeList*& headTreeList, tree*& root, std::string nameTreeStructFile);

/** Funkcja tworzy drzewo decyzji binarnej z drzew z listy
@param headTreeList g³owa listy
@param mainHead kopia g³owy listy (pocz¹tkowo ten sam adres co headTreeList)
@param root korzeñ drzewa decyzji binarnej
@param index wartoœæ indeksu liœcia do pobrania (na pocz¹tku wywo³ujemy z indeksem  0)
@return void
*/
void getTreeStruct(treeList*& headTreeList, treeList*& mainHead, tree*& root, int index);

/** Funkcja przyporz¹dkowuje wartoœci atrybutów pod etykiety i wypisuje je do pliku
@param root korzen drzewa decyzji binarnej
@param labelHead g³owa listy etykiet (pocz¹tkowo jest nullptr)
@param measureHead g³owa listy wartoœci atrybutów (pocz¹tkowo jest nullptr)
@param nameDataFile nazwa pliku z danymi
@param nameOutputFile nazwa pliku wyjœciowego
@return void
*/
void sortData(tree* root, labelList*& labelHead, measureList*& measureHead, std::string nameDataFile, std::string nameOutputFile);

/** Funkcja usuwa listê drzew razem z wêz³ami drzew
@param headTreeList g³owa listy drzew
@param root korzen drzewa decyzyjnego
@return void
*/
void destroyTreeList(treeList*& headTreeList, tree*& root);

/** Funkcja usuwa listê etykiet i listê wartoœci atrybutów
@param labelHead g³owa listy etykiet
@param measureHead g³owa listy wartoœci atrybutów
@return void
*/
void destroyList(labelList*& labelHead, measureList*& measureHead);

#endif
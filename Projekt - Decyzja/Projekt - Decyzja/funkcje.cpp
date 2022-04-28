/** @file */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <ios>
#include <climits>
#include <random>
#include <chrono>
#include <iomanip>
#include <deque>

#include "struktury.h"
#include "funkcje.h"

void getTreeList(treeList*& headTreeList, tree*& root, std::string nameTreeStructFile) {
	std::ifstream treeFile(nameTreeStructFile);

	std::string temp = {};
	std::string line;
	std::stringstream ssline;

	int index = NULL;
	std::string a = {};
	char b = {};
	float c = NULL;
	std::string d = {};
	std::string e = {};
	size_t possition = {};

	treeList* mainHead;
	int if_ft;

	while (std::getline(treeFile, line)) {
		ssline.clear();
		ssline.str(line);
		ssline >> temp;
		index = std::stof(temp);
		ssline >> a;

		if ((possition = a.find('<')) != std::string::npos) {
			temp = a.substr(possition + 1);
			c = std::stof(temp);
			a = a.substr(0, possition);
			b = '<';
		}
		else if ((possition = a.find('>')) != std::string::npos) {
			temp = a.substr(possition + 1);
			c = std::stof(temp);
			a = a.substr(0, possition);
			b = '>';
		}

		ssline >> d;
		ssline >> e;

		headTreeList = new treeList{ new tree{ index, a, b, c, d, e, nullptr, nullptr }, headTreeList };
	}
	treeFile.close();
}

void getTreeStruct(treeList*& headTreeList, treeList*& mainHead, tree*& root, int index) {
	if (!root) {
		while (headTreeList->root->index != index) {
			headTreeList = headTreeList->nextTree;
		}
		root = headTreeList->root;
		headTreeList = mainHead;
	}
	if (isdigit(root->if_false[0])) {
		index = std::stoi(root->if_false);
		getTreeStruct(headTreeList, mainHead, root->left, index);
	}
	if (isdigit(root->if_true[0])) {
		index = std::stoi(root->if_true);
		getTreeStruct(headTreeList, mainHead, root->right, index);
	}
}

void sortData(tree* root, labelList*& labelHead, measureList*& measureHead, std::string nameDataFile, std::string nameOutputFile) {
	std::ifstream dataFile(nameDataFile);
	std::fstream outputFile(nameOutputFile, std::ios::out);

	std::stringstream sStreamAttributes;
	std::stringstream sStream;
	std::string attributeLine;
	std::string line;
	std::string a;
	float b = NULL;
	int doWhile;

	std::getline(dataFile, attributeLine);

	tree* mainRoot = root;
	labelList* mainLabel = nullptr;
	while (std::getline(dataFile, line))
	{
		doWhile = 1;
		root = mainRoot;
		do {
			a = "";
			b = NULL;
			sStreamAttributes.clear();
			sStream.clear();
			sStreamAttributes.str(attributeLine);
			sStream.str(line);
			labelHead = mainLabel;

			do {
				sStream >> b;
			} while (sStreamAttributes >> a && a != root->attribute);

			if (root->comp_sign == '<') {
				if (b < root->requirement) {
					if (isdigit(root->if_true[0])) {
						root = root->right;
					}
					else {
						do {
							if (!labelHead) {
								labelHead = mainLabel;
								labelHead = new labelList{ root->if_true, measureHead = new measureList {line, nullptr}, labelHead };
								mainLabel = labelHead;

								doWhile = 0;
							}
							else {
								if (root->if_true != labelHead->label) {
									labelHead = labelHead->nextLabel;
								}
								else {
									labelHead->measureHead = measureHead = new measureList{ line, labelHead->measureHead };
									doWhile = 0;
								}
							}
						} while (doWhile);
					}
				}
				else {
					if (isdigit(root->if_false[0])) {
						root = root->left;
					}
					else {
						do {
							if (!labelHead) {
								labelHead = mainLabel;
								labelHead = new labelList{ root->if_false, measureHead = new measureList {line, nullptr}, labelHead };
								mainLabel = labelHead;

								doWhile = 0;
							}
							else {
								if (root->if_false != labelHead->label) {
									labelHead = labelHead->nextLabel;
								}
								else {
									labelHead->measureHead = measureHead = new measureList{ line, labelHead->measureHead };
									doWhile = 0;
								}
							}
						} while (doWhile);
					}
				}
			}
			else {
				if (b > root->requirement) {
					if (isdigit(root->if_true[0])) {
						root = root->right;
					}
					else {
						do {
							if (!labelHead) {
								labelHead = mainLabel;
								labelHead = new labelList{ root->if_true, measureHead = new measureList {line, nullptr}, labelHead };
								mainLabel = labelHead;

								doWhile = 0;
							}
							else {
								if (root->if_true != labelHead->label) {
									labelHead = labelHead->nextLabel;
								}
								else {
									labelHead->measureHead = measureHead = new measureList{ line, labelHead->measureHead };
									doWhile = 0;
								}
							}
						} while (doWhile);
					}
				}
				else {
					if (isdigit(root->if_false[0])) {
						root = root->left;
					}
					else {
						do {
							if (!labelHead) {
								labelHead = mainLabel;
								labelHead = new labelList{ root->if_false, measureHead = new measureList {line, nullptr}, labelHead };
								mainLabel = labelHead;
								doWhile = 0;
							}
							else {
								if (root->if_false != labelHead->label) {
									labelHead = labelHead->nextLabel;
								}
								else {
									labelHead->measureHead = measureHead = new measureList{ line, labelHead->measureHead };
									doWhile = 0;
								}
							}
						} while (doWhile);
					}
				}
			}
		} while (doWhile);
	}
	labelHead = mainLabel;
	while (labelHead) {
		outputFile << labelHead->label << '\n';
		measureList* mainMeasureHead = labelHead->measureHead;
		while (labelHead->measureHead) {
			outputFile << labelHead->measureHead->measure << '\n';
			labelHead->measureHead = labelHead->measureHead->next;
		}
		outputFile << '\n';

		labelHead->measureHead = mainMeasureHead;
		labelHead = labelHead->nextLabel;
	}
	labelHead = mainLabel;
	outputFile.close();
	dataFile.close();
}

void destroyList(labelList*& labelHead, measureList*& measureHead) {
	if (labelHead) {
		destroyList(labelHead->nextLabel, labelHead->nextLabel->measureHead);
		do {
			if (!labelHead->measureHead->next) {
				delete labelHead->measureHead;
				labelHead->measureHead = nullptr;
			}
			else {
				measureList* temp = labelHead->measureHead->next;
				delete labelHead->measureHead;
				labelHead->measureHead = nullptr;
				labelHead->measureHead = temp;
			}
		} while (labelHead->measureHead != nullptr);
		delete labelHead;
		labelHead = nullptr;
	}
}

void destroyTreeList(treeList*& headTreeList, tree*& root) {
	if (headTreeList) {
		destroyTreeList(headTreeList->nextTree, headTreeList->root);
		delete headTreeList->root;
		headTreeList->root = nullptr;
		delete headTreeList;
		headTreeList = nullptr;
	}
}
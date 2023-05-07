#pragma once
#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "Setting.h"
#include <vector>
#include "Common.h"
#include <fstream>

using namespace std;

class Setting;

enum category {
	DISPLAY, SOUND, GENERAL, ALL
};
struct Node {
	Setting* value;
	Node* left;
	Node* right;
};

class BST {
	Node* root;
	int index;
	Node* createNode(Setting* data);
	void InsertToTree(Setting* data, Node* node);
	Node* SearchInTree(Setting* Key, Node* node);
	//void OverWriteNode(Setting* data, Node* node);
	void Print_Display(Node* node);
	void Print_Sound(Node* node);
	void Print_General(Node* node);
	void Print_All(Node* node);
	void SaveData(Node* node);
public:
	BST();
	void Insert(Setting* data);
	Node* Search(Setting* Key);
	//void OverWrite(Setting* data);
	int Size();
	Node* getNode();
	void Print(category type);
	void SaveData();
};
#endif

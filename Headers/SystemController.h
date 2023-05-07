#pragma once
#ifndef SYSTEM_CONTROLLER_H_
#define SYSTEM_CONTROLLER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "BinaryTree.h"
#include "Setting.h"
#include "Common.h"

using namespace std;

class SystemController {
public:
	// START CAR
	void Start();

	//SCREEN 1:	GENERAL SCREEN
	void Main_Screen();

	//SCREEN 2: INPUT SCREEN
	void Input_Screen();
	void Input_Screen_Display();
	void Input_Screen_Sound();
	void Input_Screen_General();

	//SCREEN 3: PRINT SCREEN
	void Print_Screen();
	void Print_Screen_Display();
	void Print_Screen_Sound();
	void Print_Screen_General();
	void Print_Screen_All();

	//DATA PROCESSING
	void isExisted(Setting* Data);
	void LoadDataFromStorage();	//Load user data from text file
	void WriteDataToStorage();	//Write user data to text file
	void AddToList(Node* position, Setting* data, int type);
};
#endif //SYSTEM_CONTROLLER_H_
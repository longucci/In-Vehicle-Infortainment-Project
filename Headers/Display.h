#pragma once
#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "Common.h"
#include <iostream>
#include <string>
using namespace std;

class Display {
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
public:
	Display();
	~Display();
	int getLightLevel();
	int getScreenLightLevel();
	int getTaploLightLevel();
	void setLightLevel(int data);
	void setScreenLightLevel(int data);
	void setTaploLightLevel(int data);

	void enterDisplayInfo();
	void printDisplayInfo();
};

#endif //DISPLAY_H_
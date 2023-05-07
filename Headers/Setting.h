#pragma once
#ifndef _SETTING_H_
#define _SETTING_H_
#include <iostream>
#include "Car.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"
#include "Common.h"
using namespace std;
class Setting : public Car {
private:
	Display* display;
	Sound* sound;
	General* general;
public:
	Setting();
	~Setting();
	void setDisplay(Display* data);
	Display* getDisplay();
	void setSound(Sound* data);
	Sound* getSound();
	void setGeneral(General* data);
	General* getGeneral();
	void OverWrite(Setting* data, int inputtype);

	void enterCommonInfo();
	void printCommonInfo();
};

#endif
#pragma once
#ifndef GENERAL_H_
#define GENERAL_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
class General {
private:
	string time_zone;
	string language;
public:
	General();
	~General();
	string getTimeZone();
	string getLanguage();
	void setTimezone(string data);
	void setLanguage(string data);

	void printGeneralInfo();
};

#endif //GENERAL_H_
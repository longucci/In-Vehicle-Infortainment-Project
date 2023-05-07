#pragma once
#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include <string>
#include <regex>
using namespace std;
class Car {
private:
	string name;
	string email;
	string id;
	int odo;
	int service_remind;
public:
	Car();
	//Car(string, string, int, int, int);
	~Car();
	virtual void enterCommonInfo() = 0;
	virtual void printCommonInfo() = 0;
	void setOwnerName(string data);
	void setEmail(string data);
	void setOwnerID(string data);
	void setOdoNumber(int data);
	void setServiceRemind(int data);
	string getOwnerName();
	string getEmail();
	string getOwnerID();
	int getOdoNumber();
	int getServiceRemind();
};

#endif
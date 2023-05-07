#include "Car.h"
Car::Car() {
	name = "";
	email = "";
	id = "";
	odo = 0;
	service_remind = 0;
}
Car::~Car() {
}
string Car::getOwnerName() {
	return name;
}
string Car::getOwnerID() {
	return id;
}
string Car::getEmail() {
	return email;
}
int Car::getOdoNumber() {
	return odo;
}
int Car::getServiceRemind() {
	return service_remind;
}
void Car::setOwnerName(string data) {
	name = data;
}
void Car::setEmail(string data) {
	email = data;
}
void Car::setOwnerID(string data) {
	id = data;
}
void Car::setOdoNumber(int data) {
	odo = data;
}
void Car::setServiceRemind(int data) {
	service_remind = data;
}
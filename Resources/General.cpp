#include "General.h"

General::General() {
	time_zone = "None";
	language = "None";
}
General::~General() {
	//cout << "General function destruction" << endl;
}
string General::getTimeZone() {
	return time_zone;
}
string General::getLanguage() {
	return language;
}
void General::setTimezone(string data) {
	time_zone = data;
}
void General::setLanguage(string data) {
	language = data;
}
void General::printGeneralInfo() {
	cout << setw(70) << getTimeZone() << setw(30) << getLanguage() << endl;
}
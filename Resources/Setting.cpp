#include "Setting.h"

Setting::Setting() {
	display = new Display;
	sound = new Sound;
	general = new General;
}

Setting::~Setting() {
	delete display;
	delete sound;
	delete general;
}

void Setting::setDisplay(Display* data) {
	display = data;
}
Display* Setting::getDisplay() {
	return display;
}
void Setting::setSound(Sound* data) {
	sound = data;
}
Sound* Setting::getSound() {
	return sound;
}
void Setting::setGeneral(General* data) {
	general = data;
}
General* Setting::getGeneral() {
	return general;
}

void Setting::OverWrite(Setting* data, int inputtype) {
	setOwnerName(data->getOwnerName());
	setOwnerID(data->getOwnerID());
	setEmail(data->getEmail());
	setOdoNumber(data->getOdoNumber());
	setServiceRemind(data->getServiceRemind());
	if (inputtype == 1) {
		setDisplay(data->getDisplay());
	}
	else if (inputtype == 2) {
		setSound(data->getSound());
	}
	else {
		setGeneral(data->getGeneral());
	}
}

void Setting::enterCommonInfo() {
	string name, email, id, odo, sv;
	//cin.ignore();	//Xóa bộ nhớ đệm trước khi getline để bò qua ký tự '\n'

	/*				ENTER OWNER NAME			*/
	do {
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner name: ";
		getline(cin, name);
	} while (!ValidateInput(name, VALIDATE_NAME));
	setOwnerName(name);


	/*				ENTER PRIVATE ID			*/
	do {
		system("cls");
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner: " << name << endl;
		cout << "Private ID: ";
		getline(cin, id);
	} while (!ValidateInput(id, VALIDATE_ID));	//Nếu ID nhập vào không hợp lệ thì nhập lại, các thông tin đã lưu
	setOwnerID(id);

	/*				ENTER OWNER EMAIL			*/
	do {
		system("cls");
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email: ";
		getline(cin, email);
	} while (!ValidateInput(email, VALIDATE_EMAIL));
	setEmail(email);

	/*				ENTER CAR ODO NUMBER			*/
	do {
		system("cls");
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email: " << email << endl;
		cout << "Odo number: ";
		getline(cin, odo);
	} while (!ValidateInput(odo, VALIDATE_INPUT_NUMBER));
	setOdoNumber(stoi(odo));

	/*				ENTER SERVICE REMIND NUMBER			  */
	do {
		system("cls");
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email: " << email << endl;
		cout << "Odo number: " << odo << endl;
		cout << "Remind service number (km): ";
		getline(cin, sv);
	} while (!ValidateInput(sv, VALIDATE_INPUT_NUMBER));
	setServiceRemind(stoi(sv));
}


void Setting::printCommonInfo() {
	cout << setw(25) << left << getOwnerName() << setw(20) << getEmail() << setw(20) << getOwnerID() << setw(15) << getOdoNumber() << setw(25) << getServiceRemind();
}
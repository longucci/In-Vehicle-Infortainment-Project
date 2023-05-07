#include "SystemController.h"
BST tree;

					/* ####################### DATA PROCESSING ######################## */
void SystemController::isExisted(Setting* Data) {
	//cout << tree.Search(Data) << endl;
	//Nếu không tìm thấy data ở trong cây thì trả về NULL, còn tìm thấy thì trả về vị trí của node trùng đó để ghi đè giá trị
	if (tree.Search(Data) != NULL) {
		cout << "This car already existed, data will be overwritten" << endl;
		system("pause");
	}
	else {	
		cout << "This is new car, data will be append to your list" << endl;
		system("pause");
	}
}
void SystemController::AddToList(Node* position,Setting* data, int type) {
	if (position != NULL) {
		position->value->OverWrite(data, type);
	}
	else {
		tree.Insert(data);
	}
}
							
void SystemController::LoadDataFromStorage() {
	vector<string> user;
	ifstream file(STORAGE_PATH);
	try {
		if (file.is_open()) {
			if (file.peek() == ifstream::traits_type::eof()) {	//Kiểm tra xem file Setting.txt có empty hay không
				cout << "\nNO DATA TO READ..." << endl;
				Sleep(2000);
				return;
			}
			else {
				cout << "\nSAVING DATA TO STORAGE..." << endl;
				Sleep(2000);
			}
			string line;
			//Setting* temp = new Setting;
			while (getline(file, line)) {
				Setting* temp = new Setting;
				user = explode(line);

				//Common information
				temp->setOwnerName(user[0]);
				temp->setEmail(user[1]);
				temp->setOwnerID(user[2]);
				temp->setOdoNumber(stoi(user[3]));
				temp->setServiceRemind(stoi(user[4]));

				//Display information
				temp->getDisplay()->setLightLevel(stoi(user[5]));
				temp->getDisplay()->setScreenLightLevel(stoi(user[6]));
				temp->getDisplay()->setTaploLightLevel(stoi(user[7]));

				//Sound information
				temp->getSound()->setMediaVolume(stoi(user[8]));
				temp->getSound()->setCallVolume(stoi(user[9]));
				temp->getSound()->setNavigationVolume(stoi(user[10]));
				temp->getSound()->setNotificationVolume(stoi(user[11]));

				//General information
				temp->getGeneral()->setTimezone(user[12]);
				temp->getGeneral()->setLanguage(user[13]);

				tree.Insert(temp);
				//Xóa hết các phần tử trong vector user để cập nhật thông tin cho owner mới
				while (!user.empty()) {
					user.pop_back();
				}
			}
		}
		else {
			throw "Open file fail";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		file.close();
	}
	//Xóa nội dung file sau khi đọc để ghi dữ liệu mới vào
	ofstream file1(STORAGE_PATH, ios::trunc);
	try {
		if (!file1.is_open()) {
			throw "Open file fail";
		}
		else {
			file1 << "";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		file1.close();
	}
}
void SystemController::WriteDataToStorage() {
	tree.SaveData();
}


					/* ####################### STARTING VEHICLE ####################### */
void SystemController::Start() {
	cout << " =========================================" << endl;
	cout << " |                WELCOME                |" << endl;
	cout << " =========================================" << endl;
	cout << "CHECKING DATA FROM STORAGE..." << endl;
	Sleep(2000);
	cout << endl;
	cout << "Loading: ";
	for (int i = 0; i < 33; i++) {
		cout << "#";
		Sleep(100);
	}
	cout << endl;
	cout << "SUCCESSFULLY..." << endl;
	Sleep(2000);
	LoadDataFromStorage();
	cout << "\nLOADING MAIN SCREEN..." << endl;
	Sleep(2000);
	Main_Screen();
}
						/* ####################### MAIN SCREEN ####################### */
void SystemController::Main_Screen() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. INPUT SETTING INFORMATION" << endl;
		cout << "2. PRINT SETTING INFORMATION" << endl;
		cout << "3. EXIT" << endl;
		cout << "Your selection: ";
		getline(cin,inputkey);
	} while (!ValidateInput(inputkey, VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		Input_Screen();
		break;
	case 2:
		Print_Screen();
		break;
	case 3:
		cout << endl;
		cout << "GOOD BYE !!!" << endl;
		return;
	default:
		cout << "Invalid choice, please enter again" << endl;
		system("pause");
		Main_Screen();
		break;
	}
}

					/* ######################## INPUT SCREEN ####################### */
void SystemController::Input_Screen() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. DISPLAY SETTING" << endl;
		cout << "2. SOUND SETTING" << endl;
		cout << "3. GENERAL SETTING" << endl;
		cout << "4. RETURN" << endl;
		cout << "Your selection: ";
		getline(cin,inputkey);
	} while (!ValidateInput(inputkey, VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		Input_Screen_Display();
		break;
	case 2:
		Input_Screen_Sound();
		break;
	case 3:
		Input_Screen_General();
		break;
	case 4:
		Main_Screen();
		break;
	default:
		cout << "Invalid choice, please enter again" << endl;
		system("pause");
		Input_Screen();
		break;
	}
}
void SystemController::Input_Screen_Display() {
	string inputkey;
	do{
		system("cls");
		Setting* display = new Setting;
		cout << "----- Input Display Setting ------" << endl;
		cout << "Car Index: " << tree.Size() + 1 << endl;
		display->enterCommonInfo();
		//Kiểm tra phần tử đã tồn tại trong mảng chưa
		isExisted(display);
		display->getDisplay()->enterDisplayInfo();
		AddToList(tree.Search(display), display, 1);
		
		cout << "Will you input for car " << tree.Size() + 1 << " (y/n): ";
		getline(cin,inputkey);
		while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO))
		{
			system("cls");
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << tree.Size() + 1 << endl;
			cout << "Owner: " << display->getOwnerName() << endl;
			cout << "Private ID: " << display->getOwnerID() << endl;
			cout << "Email: " << display->getEmail() << endl;
			cout << "Odo number: " << display->getOdoNumber() << endl;
			cout << "Remind service number (km): " << display->getServiceRemind() << endl;
			cout << "Light level: " << display->getDisplay()->getLightLevel() << endl;
			cout << "Screen light level: " << display->getDisplay()->getScreenLightLevel() << endl;
			cout << "Taplo light level: " << display->getDisplay()->getTaploLightLevel() << endl;
			cout << "Will you input for car " << tree.Size() + 1 << " (y/n): ";
			cout << "Please enter y or n: ";
			getline(cin,inputkey);
		}
	} while (inputkey == "y" || inputkey == "Y"); //Nếu người dùng chọn yes thì tiếp tục nhập phần tử cho mảng Display
	Input_Screen();
}

void SystemController::Input_Screen_Sound() {
	string inputkey;
	do {
		system("cls");
		Setting* sound = new Setting;
		cout << "----- Input Sound Setting ------" << endl;
		cout << "Car Index: " << tree.Size() + 1 << endl;
		sound->enterCommonInfo();
		isExisted(sound);
		sound->getSound()->enterSoundInfo();
		AddToList(tree.Search(sound), sound, 2);
	
		cout << "Will you input for car " << tree.Size() + 1 << " (y/n): ";
		getline(cin, inputkey);
		while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO))
		{
			system("cls");
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << tree.Size() + 1 << endl;
			cout << "Owner: " << sound->getOwnerName() << endl;
			cout << "Private ID: " << sound->getOwnerID() << endl;
			cout << "Email: " << sound->getEmail() << endl;
			cout << "Odo number: " << sound->getOdoNumber() << endl;
			cout << "Remind service number (km): " << sound->getServiceRemind() << endl;
			cout << "Media volume: " << sound->getSound()->getMediaVolume() << endl;
			cout << "Call volume: " << sound->getSound()->getCallVolume() << endl;
			cout << "Navigation volume: " << sound->getSound()->getNavigationVolume() << endl;
			cout << "Notification volume: " << sound->getSound()->getNotificationVolume() << endl;
			cout << "Will you input for car " << tree.Size() + 1 << " (y/n)" << endl;
			cout << "Please enter y or n: ";
			getline(cin, inputkey);
		}
	} while (inputkey == "y" || inputkey == "Y");
	//sort_list();
	Input_Screen();
}
void SystemController::Input_Screen_General() {
	string inputkey;
	do {
		system("cls");
		Setting* general = new Setting;
		cout << "----- Input General Setting ------" << endl;
		cout << "Car Index: " << tree.Size() + 1 << endl;
		general->enterCommonInfo();
		isExisted(general);
		
		//DOWNLOAD TIMEZONE + LANGUAGE
		vector<string> list_time = downloadTimezone();
		vector<string> list_language = downloadLanguage();
		
		string input_time;
		//SETTING TIMEZONE
		do {
			do {
				system("cls");
				cout << "--- SELECT TIMEZONE DATA ---" << endl;
				for (int i = 0; i < list_time.size(); i++) {
					cout << i + 1 << ": " << list_time[i] << endl;
				}
				cout << "YOUR SELECTION: ";
				getline(cin,input_time);
			} while (!ValidateInput(input_time, VALIDATE_INPUT_NUMBER));
			if (stoi(input_time) > 32 || stoi(input_time) <= 0) {
				cout << "Error! Out of range" << endl;
				system("pause");
			}
		} while (stoi(input_time) > 32); //Chỉ có 32 giá trị timezone nên người dùng không nhập vào quá 32
		
		string input_language;
		//SETTING LANGUAGE
		do {
			do {
				system("cls");
				cout << "--- SELECT LANGUAGE DATA ---" << endl;
				for (int i = 0; i < list_language.size(); i++) {
					cout << i + 1 << ": " << list_language[i] << endl;
				}
				cout << "YOUR SELECTION: ";
				getline(cin,input_language);
			} while (!ValidateInput(input_language, VALIDATE_INPUT_NUMBER));
			if (stoi(input_language) > 30 || stoi(input_time) <= 0) {
				cout << "Error! Out of range" << endl;
				system("pause");
			}
		} while (stoi(input_language) > 30);	//Chỉ có 30 language nên giá trị nhập vào không được vượt quá 30

		general->getGeneral()->setTimezone(list_time[stoi(input_time) - 1]);
		general->getGeneral()->setLanguage(list_language[stoi(input_language) - 1]);
		AddToList(tree.Search(general), general, 3);

		cout << "Will you input for car " << tree.Size() + 1 << " (y/n): ";
		getline(cin, inputkey);
		while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "----- Input General Setting ------" << endl;
			cout << "Car Index: " << tree.Size() + 1 << endl;
			cout << "Owner: " << general->getOwnerName() << endl;
			cout << "Private ID: " << general->getOwnerID() << endl;
			cout << "Email: " << general->getEmail() << endl;
			cout << "Odo number: " << general->getOdoNumber() << endl;
			cout << "Remind service number (km): " << general->getServiceRemind() << endl;
			cout << "Timezone: " << general->getGeneral()->getTimeZone() << endl;
			cout << "Language: " << general->getGeneral()->getLanguage() << endl;
			cout << "Will you input for car " << tree.Size() + 1 << " (y/n): ";
			cout << "Please enter y or n: ";
			getline(cin,inputkey);
			cin.clear();
		}
	} while (inputkey == "y" || inputkey == "Y");
	Input_Screen();
}

						/* ####################### PRINT SCREEN ######################## */
void SystemController::Print_Screen() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. PRINT DISPLAY SETTING INFORMATION" << endl;
		cout << "2. PRINT SOUND SETTING INFORMATION" << endl;
		cout << "3. PRINT GENERAL SETTING INFORMATION" << endl;
		cout << "4. PRINT ALL SETTING INFORMATION" << endl;
		cout << "5. RETURN" << endl;
		cout << "Your selection: ";
		getline(cin,inputkey);
		cin.clear();
	} while (!ValidateInput(inputkey, VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		Print_Screen_Display();
		break;
	case 2:
		Print_Screen_Sound();
		break;
	case 3:
		Print_Screen_General();
		break;
	case 4:
		Print_Screen_All();
		break;
	case 5:
		Main_Screen();
		break;
	default:
		cout << "Invalid choice, please enter again" << endl;
		system("pause");
		Print_Screen();
		break;
	}
}

void SystemController::Print_Screen_Display() {
	system("cls");
	tree.Print(DISPLAY);
	system("pause");
	Print_Screen();
}

void SystemController::Print_Screen_Sound() {
	system("cls");
	tree.Print(SOUND);
	system("pause");
	Print_Screen();
}

void SystemController::Print_Screen_General() {
	system("cls");
	tree.Print(GENERAL);
	system("pause");
	Print_Screen();
}
void SystemController::Print_Screen_All() {
	system("cls");
	tree.Print(ALL);
	system("pause");
	Print_Screen();
}
					/* ############################ END ############################### */
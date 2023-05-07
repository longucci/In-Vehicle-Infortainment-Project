#include "Common.h"
bool ValidateInput(string str, const char* regExp) {
	regex regexInput(regExp);
	if (regex_match(str, regexInput))	//Kiem tra giá trị nhập từ bàn phím có match với định dạng cho sẵn hay không
		return true;
	cout << "Invalid input, please enter again" << endl;
	system("pause");
	return false;
}
vector<string> downloadTimezone() {
	vector<string> list_time_zone;
	fstream file1(TIMEZONE_PATH, ios::in | ios::out);
	try {
		if (file1.is_open()) {
			string line;
			while (getline(file1, line)) {	//Lấy thông tin từ file timezone.txt và lưu vào vector time_zone
				list_time_zone.push_back(line);
			}
		}
		else {
			throw "FAIL TO OPEN FILE";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		file1.close();
	}
	//sort(list_time_zone.begin(), list_time_zone.end());	
	return list_time_zone;
}

vector<string> downloadLanguage() {
	vector<string> list_language;
	fstream file(LANGUAGE_PATH, ios::in | ios::out);
	try {
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {	//Lấy giá trị trong language.txt và lưu vào vector list_language
				list_language.push_back(line);
			}
		}
		else {
			throw "FAIL TO OPEN FILE";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		file.close();
	}
	sort(list_language.begin(), list_language.end());	//Sắp xếp các giá trị trong list_language theo thứ tự Alphabet
	return list_language;
}
						/* ############ HÀM TÁCH CHỮ TỪ 1 CHUỖI ############## */
const vector<string> explode(const string& s)
{
	vector<string> res;
	string buff{ "" };
	for (auto n : s)
	{
		if (n != ',' && n != ';') {
			buff += n;
			if (buff == "Common:" || buff == "Display:" || buff == "Sound:" || buff == "General:") {
				buff = "";
			}
		}
		else if ((n == ',' || n == ';') && buff != "")	//Nếu gặp phải các kí tự này thì ghi biến buff vào vector và reset biến buff để ghi dữ liệu mới
		{
			res.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")	//Ghi những giá trị sau dấu phẩy cuối cùng vào vector
		res.push_back(buff);
	return res;
}


#pragma once
#ifndef _COMMON_H_
#define _COMMON_H_
#include <regex>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const auto TIMEZONE_PATH = "timezone.txt";
const auto LANGUAGE_PATH = "language.txt";
const auto STORAGE_PATH = "E:\\All files\\Workspace\\C++ Programming\\CPP201x_asm04_longthFX18348@funix.edu.vn\\CPP201x_asm04_longthFX18348@funix.edu.vn\\Setting.txt";

const auto VALIDATE_NAME = "^\\D*$";
const auto VALIDATE_EMAIL = "^\\w+\\@\\w+\\.\\w+(\\.\\w+)*$";	//Định dạng email là: name@abc.xyz(.vn)
const auto VALIDATE_ID = "^\\d{8}$";	//MSCN phải bao gồm 8 số
const auto VALIDATE_INPUT_NUMBER = "^[1-9]\\d*$";
const auto VALIDATE_INPUT_DISPLAY_SOUND = "^[1-5]$";
const auto VALIDATE_INPUT_SCREEN = "^[1-9]+";	//input nhập vào phải là số (không có số 0 ở đầu E.g: 01 -> sai, 1 -> đúng)
const auto VALIDATE_INPUT_YES_NO = "^y$|^n$|^Y$|^N$";	//Các câu hỏi yes/no chỉ nhập vào y or n

typedef struct {
	//Common Info
	string name;
	string email;
	string id;
	int odo;
	int service_remind;
	//Display
	int light_level;
	int screen_light_level;
	int taplo_light_level;
	//Sound
	int media_volume_level;
	int call_volume_level;
	int navigation_volume_level;
	int notification_volume_level;
	//General
	string time_zone;
	string language;
} USER_DATA;

bool ValidateInput(string str, const char* regExp);	//Xét tính hợp lệ của input
vector<string> downloadTimezone();
vector<string> downloadLanguage();
const vector<string> explode(const string& s);	//export string from text file

#endif
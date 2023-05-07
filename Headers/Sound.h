#pragma once
#ifndef SOUND_H_
#define SOUND_H_
#include <iostream>
#include <string>
#include "Common.h"
using namespace std;

class Sound {
private:
	int media_volume_level;
	int call_volume_level;
	int navigation_volume_level;
	int notification_volume_level;
public:
	Sound();
	~Sound();
	int getMediaVolume();
	int getCallVolume();
	int getNavigationVolume();
	int getNotificationVolume();
	void setMediaVolume(int data);
	void setCallVolume(int data);
	void setNavigationVolume(int data);
	void setNotificationVolume(int data);

	void enterSoundInfo();
	void printSoundInfo();
};

#endif //SOUND_H_

#pragma once

#include "..\repository\MainRepository.h"
#include "..\activity\SmokeActivity.h"
#include "..\activity\PirActivity.h"
#include "..\activity\VoltageActivity.h"

class GarageBusinessLayer{
public:
	GarageBusinessLayer();
	bool canOpenTheDoor(MainRepository& mainRepository, SmokeActivity* smokeActivity, PirActivity* pirActivity);
	char* getBatteryGrapfLevel(MainRepository& mainRepository,VoltageActivity* voltageActivity,uint8_t analogPortPin);
private:
};





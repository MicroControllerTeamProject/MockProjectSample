#pragma once

#include "..\repository\MainRepository.h"
#include "..\activity\SmokeActivity.h"
#include "..\activity\PirActivity.h"
#include "..\activity\VoltageActivity.h"

class GarageBusinessLayer{
public:
	GarageBusinessLayer();
	bool canOpenTheDoor(AvrMicroRepository& avrMicroRepository, SmokeActivity* smokeActivity, PirActivity* pirActivity);
	char* getBatteryGrapfLevel(AvrMicroRepository& avrMicroRepository,VoltageActivity* voltageActivity,uint8_t analogPortPin);
private:
};





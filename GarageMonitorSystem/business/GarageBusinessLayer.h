#pragma once

#include "..\repository\AvrMicroRepository.h"
#include "..\activity\SmokeActivity.h"
#include "..\activity\PirActivity.h"
#include "..\activity\VoltageActivity.h"
#include "..\activity\SimModuleActivity.h"
#include <stdint.h>
#include <string.h>

class GarageBusinessLayer{
public:
	GarageBusinessLayer();
	bool canOpenTheDoor(AvrMicroRepository& avrMicroRepository, SmokeActivity* smokeActivity, PirActivity* pirActivity);
	char* getBatteryGrapfLevel(AvrMicroRepository& avrMicroRepository,VoltageActivity* voltageActivity,uint8_t analogPortPin);
	void checkSystem(AvrMicroRepository& avrMicroRepository, SmokeActivity* smokeActivity, SimModuleActivity* simModuleActivity);
private:
};





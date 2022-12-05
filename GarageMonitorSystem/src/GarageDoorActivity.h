#pragma once
//#include "modules/microInterface.h"

#include "modules/WatherSensor.h"
#include "programStates.h"

class GarageDoorActivity
{
public:
	GarageDoorActivity(programStates& programStates);
	bool isGarageDoorToOpen(MainRepository& MainRepository, WaterSensor& waterSensor);
	char* getBatteryGrafBarLevel(MainRepository& mainRepository, uint8_t portNumber);
private:
};


#pragma once
//#include "modules/microInterface.h"
#include "../GarageDoorRepository.h"
#include "modules/WatherSensor.h"
#include "programStates.h"

class GarageDoorActivity
{
public:
	GarageDoorActivity(programStates& programStates);
	bool isGarageDoorToOpen(GarageDoorRepository& MainRepository, WaterSensor& waterSensor);
private:
};


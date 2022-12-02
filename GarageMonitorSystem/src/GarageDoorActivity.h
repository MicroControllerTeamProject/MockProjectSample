#pragma once
//#include "modules/microInterface.h"
#include "../GarageDoorRepository.h"
#include "modules/WatherSensor.h"
#include "programStates.h"

class GarageDoorActivity
{
public:
	GarageDoorActivity();
	bool isGarageDoorOpening(GarageDoorRepository& MainRepository, WaterSensor& waterSensor, programStates& programStates);
private:
};


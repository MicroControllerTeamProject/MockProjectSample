#pragma once
//#include "modules/microInterface.h"
#include "../microInterfaceWaterSensor.h"
#include "modules/waterSensor.h"
#include "programStates.h"

class waterSensorActivity
{
public:
	waterSensorActivity();
	void start(microInterfaceWaterSensor& microInterface, programStates& programStates);
private:
};


#pragma once
//#include "modules/microInterface.h"
#include "../microInterfaceGarageSystem.h"
#include "modules/waterSensor.h"
#include "programStates.h"

class waterSensorActivity
{
public:
	waterSensorActivity();
	void start(microInterfaceGarageSystem& microInterface, programStates& programStates);
private:
};


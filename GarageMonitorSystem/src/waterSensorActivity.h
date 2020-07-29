#pragma once
#include "modules/microInterface.h"
#include "modules/waterSensor.h"
#include "programStates.h"

class waterSensorActivity
{
public:
	waterSensorActivity();
	void start(microInterface& microInterface, programStates& programStates);
private:
};


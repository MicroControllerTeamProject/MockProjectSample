#pragma once
#include "modules/microInterface.h"
#include "modules/waterSensor.h"
#include "programStates.h"

class waterSensorActivity
{
public:
	waterSensorActivity();
	bool isWaterDetect(waterSensor ws, microInterface& sr, programStates& ps);
private:
};


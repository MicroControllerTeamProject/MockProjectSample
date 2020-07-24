#pragma once
#include "modules/sensorInterface.h"
#include "modules/waterSensor.h"
#include "programStates.h"

class waterSensorActivity
{
public:
	waterSensorActivity(waterSensor ws, sensorInterface& sr, programStates& ps);
private:
};


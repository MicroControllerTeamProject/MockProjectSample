#pragma once
#include "sensor.h"

class waterSensor
{
public:
	waterSensor(float vref);
	/*bool areValuesOK();*/
	virtual bool isThereWater(sensor& sr);
public:
	
};


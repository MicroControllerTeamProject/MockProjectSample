#pragma once
#include "sensorInterface.h"

class waterSensor
{
public:
	waterSensor(float vref);
	/*bool areValuesOK();*/
	virtual bool isThereWater(sensorInterface& sr);
	float analogVrefRead(sensorInterface& sr);
	float getVref();
private:
	float _vref;

};


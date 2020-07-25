#pragma once

#include "sensorInterface.h"

class waterSensor
{
public:
	waterSensor(float vref,const char* uid);
	/*bool areValuesOK();*/
	virtual bool isThereWater(sensorInterface& sr);
	float analogVrefRead(sensorInterface& sr);
	float getVref();
	const char* getUid();

private:
	float _vref;
	const char* _uid;
};


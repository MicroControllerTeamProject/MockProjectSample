#pragma once

#include "microInterface.h"

class waterSensor
{
public:
	waterSensor(float vref,const char* uid);
	/*bool areValuesOK();*/
	virtual bool isThereWater(microInterface& sr);
	float analogVrefRead(microInterface& sr);
	float getVref();
	const char* getUid();

private:
	float _vref;
	const char* _uid;
};


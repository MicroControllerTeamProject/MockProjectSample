#pragma once

#include "microInterface.h"

class waterSensor
{
public:
	waterSensor(float vref,const char* uid,float analogMinValue, float analogMaxValue);
	bool isThereWater(microInterface& sr);
	bool isSensorWorking(microInterface& sr);
	float analogVrefRead(microInterface& sr);
	float getAnalogMinValue();
	float getAnalogMaxValue();
	float getVref();
	const char* getUid();

private:
	float _vref;
	const char* _uid;
	float _analogMinValue;
	float _analogMaxValue;
};


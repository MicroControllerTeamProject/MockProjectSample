#pragma once

#include "..\..\microInterfaceWaterSensor.h"
#include "..\sensor.h"

class waterSensor : public sensor
{
public:
	waterSensor(float vref,const char* uid,float analogMinValue, float analogMaxValue);
	virtual bool isThereWater(microInterfaceWaterSensor& sr);
	/*bool isSensorWorking(microInterface& sr);
	float analogVrefRead(microInterface& sr);
	float getAnalogMinValue();
	float getAnalogMaxValue();
	float getVref();
	const char* getUid();*/

private:
	/*float _vref;
	const char* _uid;
	float _analogMinValue;
	float _analogMaxValue;*/
};


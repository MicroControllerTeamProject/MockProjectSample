#pragma once
#include "sensor.h"

class waterSensor : public sensor
{
public:
	waterSensor(uint8_t analogicSegnalPinIn,
		float analogicAllarmMaxValue,
		float analogicAllarmMinValue, 
		float vref,
		char* uid);
	/*bool areValuesOK();*/
	bool isThereWater();
};


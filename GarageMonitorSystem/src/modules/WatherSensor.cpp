#include "WatherSensor.h"
#include <string.h>

WaterSensor::WaterSensor(float vref,const char* uid,uint16_t analogMinValue, uint16_t analogMaxValue)
	: analogSensor(vref, uid, analogMinValue, analogMaxValue){	
}

uint16_t WaterSensor::getAnalogMinValue()
{
	return this->_analogMinValue;
}




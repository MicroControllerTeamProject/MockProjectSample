#include "WatherSensor.h"
#include <string.h>

WaterSensor::WaterSensor(float vref,const char* uid,uint16_t analogMinValue, uint16_t analogMaxValue)
	: analogSensor(vref, uid, analogMinValue, analogMaxValue){	
}

bool WaterSensor::isThereWather(GarageDoorRepository& sr)
{
	if (analogVrefRead(sr) < _analogMinValue){
		
		return true;
	}
	else{
		return false;
	}
}




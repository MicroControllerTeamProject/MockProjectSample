#include "waterSensor.h"



waterSensor::waterSensor(float vref,const char* uid,float analogMinValue, float analogMaxValue) 
	: sensor(vref, uid, analogMinValue, analogMaxValue){
}

bool waterSensor::isThereWater(microInterfaceWaterSensor& sr)
{
	
	if (analogVrefRead(sr) < _analogMinValue){
		return true;
	}
	else{
		return false;
	}
}




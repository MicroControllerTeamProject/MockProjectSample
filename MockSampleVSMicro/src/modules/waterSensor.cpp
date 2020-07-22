#include "waterSensor.h"

waterSensor::waterSensor(uint8_t analogicSegnalPin,
	float analogicAllarmMaxValue,
	float analogicAllarmMinValue, 
	float vref,
	char* uid) 
	:sensor(analogicSegnalPin, analogicAllarmMaxValue, analogicAllarmMinValue,vref,uid){
}


bool waterSensor::isThereWater()
{
	if (analogicRead() > getMaxValue())
	{
		//setLastComunication("Water max level");
		return true;
	}
	else
	{
		//setLastComunication("No Water found");
		return false;
	}
}

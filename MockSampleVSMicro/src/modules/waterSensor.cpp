#include "waterSensor.h"

waterSensor::waterSensor(float vref) {
}

bool waterSensor::isThereWater(sensor& sr)
{
	if (sr.analogicRead() > sr.getAlarmMaxValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

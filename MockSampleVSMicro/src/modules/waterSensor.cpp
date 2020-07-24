#include "waterSensor.h"

waterSensor::waterSensor(float vref) {
	_vref = vref;

}

float waterSensor::getVref()
{
	return _vref;
}


float waterSensor::analogVrefRead(sensorInterface& sr)
{
	return (_vref / 1024) * sr.analogicRead();
}

bool waterSensor::isThereWater(sensorInterface& sr)
{
	if (analogVrefRead(sr) > sr.getAlarmMaxValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

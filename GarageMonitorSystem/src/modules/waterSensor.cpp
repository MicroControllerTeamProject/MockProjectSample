#include "waterSensor.h"

waterSensor::waterSensor(float vref,const char* uid) {
	_vref = vref;
	_uid = uid;
}

float waterSensor::getVref()
{
	return _vref;
}

const char* waterSensor::getUid()
{
	return _uid;
}

float waterSensor::analogVrefRead(microInterface& sr)
{
	return (_vref / 1024) * sr.analogicRead();
}

bool waterSensor::isThereWater(microInterface& sr)
{
	if (analogVrefRead(sr) < sr.getAlarmMinValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool waterSensor::isSensorWorking(microInterface& sr)
{
	if (analogVrefRead(sr) < sr.getAlarmMaxValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}



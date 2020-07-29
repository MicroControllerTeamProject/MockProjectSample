#include "waterSensor.h"

waterSensor::waterSensor(float vref,const char* uid,float analogMinValue, float analogMaxValue) {
	_vref = vref;
	_uid = uid;
	_analogMinValue = analogMinValue;
	_analogMaxValue = analogMaxValue;
}

float waterSensor::getVref()
{
	return _vref;
}

const char* waterSensor::getUid(){
	return _uid;
}

float waterSensor::analogVrefRead(microInterface& sr)
{
	return (_vref / 1024) * sr.analogicRead();
}

bool waterSensor::isThereWater(microInterface& sr)
{
	if (analogVrefRead(sr) < _analogMinValue)
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
	if (analogVrefRead(sr) < _analogMaxValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float waterSensor::getAnalogMinValue()
{
	return _analogMinValue;
}

float waterSensor::getAnalogMaxValue()
{
	return _analogMaxValue;
}



#include "sensor.h"

analogSensor::analogSensor(float vref, const char* uid, float analogMinValue, float analogMaxValue) {
	_vref = vref;
	_uid = uid;
	_analogMinValue = analogMinValue;
	_analogMaxValue = analogMaxValue;
}

float analogSensor::getVref()
{
	return _vref;
}

const char* analogSensor::getUid() {
	return _uid;
}

uint16_t analogSensor::analogVrefRead(microInterface& sr)
{
	return (_vref / 1024) * sr.analogicRead();
}

bool analogSensor::isSensorWorking(microInterface& sr)
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

float analogSensor::getAnalogMinValue()
{
	return _analogMinValue;
}

float analogSensor::getAnalogMaxValue()
{
	return _analogMaxValue;
}

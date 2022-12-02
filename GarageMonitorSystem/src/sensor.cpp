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

uint16_t analogSensor::analogVrefRead(MainRepository& mainRepository)
{
	return (_vref / 1024) * mainRepository.analogicRead();
}

bool analogSensor::isSensorWorking(MainRepository& sr)
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

uint16_t analogSensor::getAnalogMinValue()
{
	return _analogMinValue;
}

uint16_t analogSensor::getAnalogMaxValue()
{
	return _analogMaxValue;
}

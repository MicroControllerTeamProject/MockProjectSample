
#include "sensor.h"

sensor::sensor(float vref, const char* uid, float analogMinValue, float analogMaxValue) {
	_vref = vref;
	_uid = uid;
	_analogMinValue = analogMinValue;
	_analogMaxValue = analogMaxValue;
}

float sensor::getVref()
{
	return _vref;
}

const char* sensor::getUid() {
	return _uid;
}

float sensor::analogVrefRead(microInterface& sr)
{
	return (_vref / 1024) * sr.analogicRead();
}

bool sensor::isSensorWorking(microInterface& sr)
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

float sensor::getAnalogMinValue()
{
	return _analogMinValue;
}

float sensor::getAnalogMaxValue()
{
	return _analogMaxValue;
}

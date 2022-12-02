#pragma once

#include "..\..\GarageDoorRepository.h"
#include "..\sensor.h"

class WaterSensor : public analogSensor
{
public:
	WaterSensor(float vref,const char* uid, uint16_t analogMinValue, uint16_t analogMaxValue);
	//virtual bool isThereWather(GarageDoorRepository& sr);
	/*bool isSensorWorking(microInterface& sr);
	float analogVrefRead(microInterface& sr);
	float getAnalogMinValue();
	float getAnalogMaxValue();
	float getVref();
	const char* getUid();*/
	uint16_t getAnalogMinValue();
	uint16_t getAnalogMaxValue();
	float getVref();
	const char* getUid();

private:
	float _vref;
	const char* _uid;
	uint16_t _analogMinValue;
	uint16_t _analogMaxValue;
};


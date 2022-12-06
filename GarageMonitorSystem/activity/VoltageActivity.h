#pragma once
#include "DeviceActivity.h"

class VoltageActivity : public DeviceActivity
{
public:
	VoltageActivity(AnalogPort** analogPort, float vref, uint8_t analogPortsNumber);
	bool isVoltageOutOfRange(MainRepository& mainRepository);
	char* getLipoBatteryGrafBarLevel(MainRepository& mainRepository, uint8_t analogPortPin);

	float  getAnalogPortVrefVoltage(MainRepository& mainRepository, uint8_t analogPin);
};


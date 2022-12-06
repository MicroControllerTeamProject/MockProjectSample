#include "VoltageActivity.h"
#include "..\repository\MainRepository.h"

VoltageActivity::VoltageActivity(AnalogPort** analogPort, float vref, uint8_t analogPortsNumber) : DeviceActivity(analogPort, vref, analogPortsNumber) {
}


bool VoltageActivity::isVoltageOutOfRange(MainRepository& mainRepository) {
	if (!(this->isThereAnyAnalogPortOnAlarm(mainRepository))) return false;
	return true;
}

float  VoltageActivity::getAnalogPortVrefVoltage(MainRepository& mainRepository, uint8_t analogPin)
{
	return (this->getVref() / 1024) * mainRepository.analogReadm(analogPin);
}

char* VoltageActivity::getLipoBatteryGrafBarLevel(MainRepository& mainRepository, uint8_t analogPortPin)
{
	for (int i = 0; i < this->_analogPortsNumber; i++)
	{
		if (this->analogPort[i]->getPin() == analogPortPin)
		{
			float batteryVoltageLevel = getAnalogPortVrefVoltage(mainRepository, analogPortPin);
			if (batteryVoltageLevel <= 3.25f)
				return "[    ]o";
			if (batteryVoltageLevel <= 3.30f)
				return "[|   ]o";
			if (batteryVoltageLevel <= 3.40f)
				return "[||  ]o";
			if (batteryVoltageLevel <= 3.60f)
				return "[||| ]o";
			if (batteryVoltageLevel <= 5.50f)
				return "[||||]o";
		}
	}
	return "";
}
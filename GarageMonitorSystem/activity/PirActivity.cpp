#include "PirActivity.h"
#include "..\repository\MainRepository.h"

PirActivity::PirActivity(DigitalPort** digitalPirPorts, uint8_t digitalPirPortsNumber) : DeviceActivity(digitalPirPorts, digitalPirPortsNumber)
{
}

bool PirActivity::isThereAnyOne(MainRepository& mainRepository)
{
	return this->isThereAnyDigitalPortOnAlarm(mainRepository);
}
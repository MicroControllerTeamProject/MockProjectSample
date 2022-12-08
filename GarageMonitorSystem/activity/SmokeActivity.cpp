#include "SmokeActivity.h"
#include "..\repository\AvrMicroRepository.h"

SmokeActivity::SmokeActivity(AnalogPort** analogPort,float vref,uint8_t analogPortsNumber)  : DeviceActivity(analogPort,vref,analogPortsNumber){
}

bool SmokeActivity::isThereSmoke(AvrMicroRepository& avrMicroRepository)
{
	return this->isThereAnyAnalogPortOnAlarm(avrMicroRepository);
}
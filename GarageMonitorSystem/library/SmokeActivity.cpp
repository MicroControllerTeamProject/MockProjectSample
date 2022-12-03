#include "SmokeActivity.h"
#include "..\src\modules\MainRepository.h"

SmokeActivity::SmokeActivity(AnalogPort** analogPort,float vref,uint8_t analogPortsNumber)  : DeviceActivity(analogPort,vref,analogPortsNumber){
}

bool SmokeActivity::isThereSmoke(MainRepository& a)
{
	return this->isThereAnyAnalogPortOnAlarm(a);
}
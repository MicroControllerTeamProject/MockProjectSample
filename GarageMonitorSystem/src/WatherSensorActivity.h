#pragma once
//#include "modules/microInterface.h"
#include "../WatherSensorRepository.h"
#include "modules/WatherSensor.h"
#include "programStates.h"

class WatherSensorActivity
{
public:
	WatherSensorActivity();
	void start(WatherSensorRepository& MainRepository, programStates& programStates);
private:
};


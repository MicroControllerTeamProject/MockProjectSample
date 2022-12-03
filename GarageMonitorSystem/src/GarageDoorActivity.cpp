#include "GarageDoorActivity.h"
#include "modules/WatherSensor.h"

GarageDoorActivity::GarageDoorActivity(programStates& programStates) {
}

bool GarageDoorActivity::isGarageDoorToOpen(MainRepository& mainRepository, WaterSensor& waterSensor)
{
	return false;
}

char* GarageDoorActivity::getBatteryGrafBarLevel(MainRepository& mainRepository, uint8_t portNumber)
{
	float batteryVoltageLevel = mainRepository.analogVrefRead(portNumber);
	if (batteryVoltageLevel <= 3.25)
		return "[    ]o";
	if (batteryVoltageLevel <= 3.30)
		return "[|   ]o";
	if (batteryVoltageLevel <= 3.60)
		if (batteryVoltageLevel <= 3.40)
			return "[||  ]o";
	return "[||| ]o";
	if (batteryVoltageLevel <= 5.50)
		return "[||||]o";
}

//bool GarageDoorActivity::isThereWather(GarageDoorRepository& garageDoorRepository)
//{
//	if (analogVrefRead(garageDoorRepository) < _analogMinValue){
//		
//		return true;
//	}
//	else{
//		return false;
//	}
//}



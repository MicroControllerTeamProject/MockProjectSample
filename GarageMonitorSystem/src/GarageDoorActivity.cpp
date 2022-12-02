#include "GarageDoorActivity.h"
#include "modules/WatherSensor.h"

GarageDoorActivity::GarageDoorActivity(){
}

bool GarageDoorActivity::isGarageDoorOpening(GarageDoorRepository& WatherSensorRepository, WaterSensor& waterSensor,
	programStates& programStates)
{
	return waterSensor.isThereWather(WatherSensorRepository);
}





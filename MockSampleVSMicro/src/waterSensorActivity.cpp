#include "waterSensorActivity.h"

waterSensorActivity::waterSensorActivity(){
}

bool waterSensorActivity::isWaterDetect(waterSensor ws, sensorInterface& sr, programStates& ps)
{
	ps._isWaterDetected  = ws.isThereWater(sr);
	return ps._isWaterDetected;
}




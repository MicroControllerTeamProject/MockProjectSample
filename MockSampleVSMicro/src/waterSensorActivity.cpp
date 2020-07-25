#include "waterSensorActivity.h"

waterSensorActivity::waterSensorActivity(){
}

void waterSensorActivity::start(waterSensor ws, microInterface& sr, programStates& ps)
{
	ps._isWaterDetected  = ws.isThereWater(sr);
	ps._isWaterDetected;
	if (ps._isWaterDetected){
		sr.printData("water is detected",true);
	}
}




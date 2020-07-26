#include "waterSensorActivity.h"

waterSensorActivity::waterSensorActivity(){
}

void waterSensorActivity::start(waterSensor ws, microInterface& microInterface, programStates& programStates)
{
	programStates._isWaterDetected  = ws.isThereWater(microInterface);
	programStates._isWaterDetected;
	if (programStates._isWaterDetected){
		microInterface.printData("water is detected",true);
	}
}




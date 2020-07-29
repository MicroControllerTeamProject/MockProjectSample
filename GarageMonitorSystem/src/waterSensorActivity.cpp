#include "waterSensorActivity.h"

waterSensorActivity::waterSensorActivity(){
}

void waterSensorActivity::start(waterSensor ws, microInterface& microInterface, programStates& programStates)
{
	microInterface.print(ws.analogVrefRead(microInterface), true);
	programStates._isWaterDetected = ws.isThereWater(microInterface);
	if (programStates._isWaterDetected){
		microInterface.print("water is detected",true);
		int a = 5;
	}
}




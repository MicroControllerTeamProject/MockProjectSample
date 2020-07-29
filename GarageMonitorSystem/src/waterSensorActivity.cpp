#include "waterSensorActivity.h"

waterSensorActivity::waterSensorActivity(){
}

void waterSensorActivity::start(waterSensor waterSensor, microInterface& microInterface, programStates& programStates)
{
	microInterface.print(waterSensor.analogVrefRead(microInterface), true);
	programStates._isWaterDetected = waterSensor.isThereWater(microInterface);
	if (programStates._isWaterDetected){
		microInterface.print("water is detected",true);
		int a = 5;
	}
}




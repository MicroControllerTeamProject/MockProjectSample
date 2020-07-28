#include "waterSensorActivity.h"

waterSensorActivity::waterSensorActivity(){
}

void waterSensorActivity::start(waterSensor ws, microInterface& microInterface, programStates& programStates)
{
	programStates._isWaterDetected  = ws.isThereWater(microInterface);
	if (programStates._isWaterDetected){
		microInterface.printData("water is detected",true);
		bool s = microInterface.printTest(10);
		int a = 5;
	}
}




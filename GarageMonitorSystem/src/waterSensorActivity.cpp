#include "waterSensorActivity.h"
#include "modules/waterSensor.h"

waterSensorActivity::waterSensorActivity(){
}

void waterSensorActivity::start(microInterfaceGarageSystem& microInterface, programStates& programStates)
{
	waterSensor waterSensor(5.00, "x01", 2, 5);
	microInterface.blink();
	microInterface.print(waterSensor.analogVrefRead(microInterface));
	programStates._isWaterDetected = waterSensor.isThereWater(microInterface);
	if (programStates._isWaterDetected){
		microInterface.print("water is detected");
		int a = 5;
	}
}




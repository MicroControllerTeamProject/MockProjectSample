#include "waterSensorActivity.h"
#include "modules/waterSensor.h"

waterSensorActivity::waterSensorActivity(){
}

void waterSensorActivity::start(microInterfaceWaterSensor& microInterfaceWaterSensor, programStates& programStates)
{
	waterSensor waterSensor(5.00, "x01", 2, 5);
	microInterfaceWaterSensor.serial_begin(9600);
	microInterfaceWaterSensor.print(waterSensor.analogVrefRead(microInterfaceWaterSensor));
	programStates._isWaterDetected = waterSensor.isThereWater(microInterfaceWaterSensor);
	if (programStates._isWaterDetected){
		microInterfaceWaterSensor.print("water is detected");
		int a = 5;
	}
}




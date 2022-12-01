#include "WatherSensorActivity.h"
#include "modules/WatherSensor.h"

WatherSensorActivity::WatherSensorActivity(){
}

void WatherSensorActivity::start(WatherSensorRepository& WatherSensorRepository, 
	programStates& programStates)
{
	WaterSensor WaterSensor(5.00, "x01", 2, 5);
	/*microInterfaceWaterSensor.print(waterSensor.analogVrefRead(microInterfaceWaterSensor));*/
	programStates._isWaterSensor01Detected = WaterSensor.isThereWather(WatherSensorRepository);
	if (programStates._isWaterSensor01Detected){
		/*microInterfaceWaterSensor.print("water is detected");*/
		int a = 5;
	}
}





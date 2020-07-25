#include "waterSensorActivity.h"

waterSensorActivity::waterSensorActivity(waterSensor ws, sensorInterface& sr, programStates& ps)
{
	float a = ws.analogVrefRead(sr);
	bool a2 = ps.test();
	sr.print(a,true);
}
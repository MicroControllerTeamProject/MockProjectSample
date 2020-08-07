#include "simActivity.h"

simActivity::simActivity(){
}

void simActivity::start(microInterfaceSimDevice& microInterfaceSimDevice, programStates& programStates){
	microInterfaceSimDevice.serial_begin(19200);
	SimDevice* simDevice = new SimDevice("SIM01");
	simDevice->dialPhone("+393202445649",microInterfaceSimDevice);
	microInterfaceSimDevice.delay_m(1000);
	if (simDevice->available(microInterfaceSimDevice))
	{
		microInterfaceSimDevice.consoleWrite(microInterfaceSimDevice.readBuffer());
	}
	delete simDevice;
}
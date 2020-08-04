#include "SerialDevice.h"

SerialDevice::SerialDevice(uint8_t rx, uint8_t tx, bool invers_logic)
{
	
}

bool SerialDevice::begin(microInterface& m,unsigned long baud)
{
	m.serial_begin(baud);
}
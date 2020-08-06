#pragma once

#include "SerialDevice.h"
#include "stdint.h"
#include "microInterfaceSimDevice.h"

class SimDevice : public SerialDevice
{
public:
	SimDevice(const char* uid);
	char* dialPhone(char* phoneNumber, microInterfaceSimDevice microInterfaceSimDevice);
};




#pragma once

#include "SerialDevice.h"
#include "stdint.h"

class SimDevice : public SerialDevice
{
public:
	SimDevice(const char* uid);
};




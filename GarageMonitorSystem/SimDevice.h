#pragma once

#include "SerialDevice.h"
#include "stdint.h"

class SimDevice : public SerialDevice
{
public:
	SimDevice(uint8_t rx, uint8_t tx, bool invers_logic);
};


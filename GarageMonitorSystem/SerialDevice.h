#pragma once
#include "stdint.h"
#include "src\modules\microInterface.h"


class SerialDevice
{
public:
	SerialDevice(uint8_t rx, uint8_t tx, bool invers_logic);
	virtual bool begin(microInterface& m,unsigned long baud);
private:
};


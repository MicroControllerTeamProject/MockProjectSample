#pragma once
#include "stdint.h"
#include "src\modules\microInterface.h"


class SerialDevice
{
public:
	SerialDevice(const char* uid);
	virtual bool begin(microInterface& m,unsigned long baud);
	virtual bool SerialDevice::available(microInterface& m);
	virtual int SerialDevice::read(microInterface& m);
	virtual bool SerialDevice::println(microInterface& m, const char* data);
private:
};


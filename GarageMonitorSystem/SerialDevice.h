#pragma once
#include "stdint.h"
#include "src\modules\MainRepository.h"


class SerialDevice
{
public:
	SerialDevice(const char* uid);
	virtual bool begin(MainRepository& m,unsigned long baud);
	virtual bool SerialDevice::available(MainRepository& m);
	virtual int SerialDevice::read(MainRepository& m);
	virtual bool SerialDevice::println(MainRepository& m, const char* data);
private:
};


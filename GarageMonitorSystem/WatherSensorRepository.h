#pragma once
#include "src/modules/MainRepository.h"

class WatherSensorRepository : public MainRepository
{
public:
	WatherSensorRepository(char analogPin, uint8_t digitalPin);
	bool blink();
private:

};


#pragma once
#include "src/modules/microInterface.h"

class microInterfaceWaterSensor : public microInterface
{
public:
	microInterfaceWaterSensor(char analogPin, uint8_t digitalPin);
	bool blink();
private:

};


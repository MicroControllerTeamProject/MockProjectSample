#pragma once
#include "src/modules/microInterface.h"

class microInterfaceGarageSystem : public microInterface
{
public:
	microInterfaceGarageSystem(uint8_t analogPin, uint8_t digitalPin,uint8_t rx = 255,  uint8_t tx = 255);
	virtual bool blink();
private:

};


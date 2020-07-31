#pragma once
#include "src/modules/microInterface.h"

class microInterfaceGarageSystem : public microInterface
{
public:
	microInterfaceGarageSystem(uint8_t analogPin, uint8_t digitalPin);
	virtual bool blink();
private:

};


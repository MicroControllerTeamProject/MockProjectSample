#pragma once
#include "src/modules/microInterface.h"

class microInterfaceSimDevice : public microInterface
{
public:
	microInterfaceSimDevice(uint8_t rx, uint8_t tx, bool invers_logic);
	microInterfaceSimDevice();
	//void serial_Write(char* message);
};


#pragma once
#include "src/modules/MainRepository.h"

class microInterfaceSimDevice : public MainRepository
{
public:
	microInterfaceSimDevice(uint8_t rx, uint8_t tx, bool invers_logic);
	microInterfaceSimDevice();
	//void serial_Write(char* message);
};


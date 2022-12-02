#pragma once
#include "src/modules/MainRepository.h"

class GarageDoorRepository : public MainRepository
{
public:
	GarageDoorRepository(char analogPin, uint8_t digitalPin);
private:

};


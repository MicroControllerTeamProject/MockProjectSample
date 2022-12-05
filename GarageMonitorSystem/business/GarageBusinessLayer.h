#pragma once

#include "..\repository\MainRepository.h"
#include "..\activity\SmokeActivity.h"
#include "..\activity\PirActivity.h"

class GarageBusinessLayer
{
public:
	GarageBusinessLayer();
	bool canOpenTheDoor(MainRepository& m, SmokeActivity* s, PirActivity* p);
};


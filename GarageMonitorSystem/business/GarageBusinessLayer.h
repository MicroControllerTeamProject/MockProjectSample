#pragma once

#include "modules\MainRepository.h"
#include "..\library\SmokeActivity.h"
#include "..\library\PirActivity.h"

class GarageBusinessLayer
{
public:
	GarageBusinessLayer();
	bool canOpenTheDoor(MainRepository& m, SmokeActivity* s, PirActivity* p);
};


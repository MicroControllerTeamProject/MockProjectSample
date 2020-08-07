#pragma once
#include "microInterfaceSimDevice.h"
#include "SimDevice.h"
#include "src\programStates.h"


class simActivity
{
public:
	simActivity();
	void start(microInterfaceSimDevice& microInterfaceSimDevice, programStates& programStates);
private:
};


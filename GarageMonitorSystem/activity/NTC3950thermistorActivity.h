#pragma once
#include "DeviceActivity.h"
class NTC3950thermistorActivity :
    public DeviceActivity
{
    NTC3950thermistorActivity(AnalogPort** analogPort, float vref, analogRefMode mode, uint8_t analogPortsNumber);
    float getTemperature();
};


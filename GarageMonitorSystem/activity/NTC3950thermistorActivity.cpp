#include "NTC3950thermistorActivity.h"

NTC3950thermistorActivity::NTC3950thermistorActivity(AnalogPort** analogPort, float vref, analogRefMode mode, uint8_t analogPortsNumber) : DeviceActivity(analogPort, vref,mode, analogPortsNumber)
{

}

float NTC3950thermistorActivity::getTemperature()
{

}


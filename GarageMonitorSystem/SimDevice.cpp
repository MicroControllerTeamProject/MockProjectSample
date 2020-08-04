#include "SimDevice.h"


SimDevice::SimDevice(const char* data,uint8_t rx, uint8_t tx, bool invers_logic) : SerialDevice(data,rx,tx, invers_logic)
{

}
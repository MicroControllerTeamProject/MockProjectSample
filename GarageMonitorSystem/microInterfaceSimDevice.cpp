#include "microInterfaceSimDevice.h"
//#include "src/modules/microInterface.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

microInterfaceSimDevice::microInterfaceSimDevice(uint8_t rx, uint8_t tx, bool invers_logic) : microInterface(rx,tx, invers_logic) {
}
microInterfaceSimDevice::microInterfaceSimDevice() : microInterface() {
}



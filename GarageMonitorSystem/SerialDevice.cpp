#include "SerialDevice.h"

SerialDevice::SerialDevice(const char* uid, uint8_t rx, uint8_t tx, bool invers_logic){
}

bool SerialDevice::begin(microInterface& m,unsigned long baud){
	m.serial_begin(baud);
}

bool SerialDevice::available(microInterface& m) {
	m.serial_available();
}

int SerialDevice::read(microInterface& m) {
	m.read();
}

bool SerialDevice::println(microInterface& m, const char* data) {
	return m.println(data);
}
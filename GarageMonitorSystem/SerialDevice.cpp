#include "SerialDevice.h"

SerialDevice::SerialDevice(const char* uid){
}

//bool SerialDevice::begin(MainRepository& m,unsigned long baud){
//	m.serial_begin(baud);
//}

bool SerialDevice::available(MainRepository& m) {
	m.serial_available();
}

int SerialDevice::read(MainRepository& m) {
	m.read();
}

bool SerialDevice::println(MainRepository& m, const char* data) {
	return m.println(data);
}
#include "AnalogPort.h"

AnalogPort::AnalogPort(char* uid, uint8_t pin){
	_uid = uid;
	_pin = pin;
}

char* AnalogPort::getUid(){
	return _uid;
}

uint8_t AnalogPort::getPin(){
	return _pin;
}
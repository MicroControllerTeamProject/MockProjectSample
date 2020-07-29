#include "microInterface.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

microInterface::microInterface() {}


microInterface::microInterface(uint8_t analogPin, uint8_t digitalPin)
{
	if (analogPin != 0)
	{
		_analogPin = analogPin;
	}
	if (digitalPin != 0)
	{
		_digitalPin = digitalPin;
		pinMode(digitalPin, INPUT);
	}
}

microInterface::~microInterface() {}

bool microInterface::isDigitalSignalPinOn() {
	return digitalRead(_digitalPin);
}

void microInterface::setDigitalAlarmPinOut(int alarmPin) {
	pinMode(alarmPin, OUTPUT);
	_alarmPin = alarmPin;
}

void microInterface::switchAlarmPin_On_Off(unsigned long time) {
	digitalWrite(_alarmPin, HIGH);
	delay(time);
	digitalWrite(_alarmPin, LOW);
}

void microInterface::turnAlarmPinOn() {
	digitalWrite(_alarmPin, HIGH);
}

void microInterface::turnAllarmPinOff() {
	digitalWrite(_alarmPin, LOW);
}

bool microInterface::isAllarmPinOn() {
	return digitalRead(_alarmPin);
}

int microInterface::analogicRead() {
	return analogRead(_analogPin);
}

bool microInterface::print(const char* data, bool isCR)
{
	if (isCR) {
		Serial.println(data);
	}
	else
	{
		Serial.print(data);
	}
	return data;
}

bool microInterface::print(float data, bool isCR)
{
	if (isCR) {
		Serial.println(data);
	}
	else
	{
		Serial.print(data);
	}
	return true;
}

bool microInterface::print(float data, bool isCR, uint8_t tx, uint8_t rx)
{
	SoftwareSerial s(rx, tx);
	if (isCR) {
		s.println(data);
	}
	else
	{
		s.print(data);
	}
	return true;
}
















//void sensor::setLastComunication(char* lastComunication)
//{
//	char message[100];   // array to hold the result.
//	/*char* message2;*/
//	strcpy(message, uid()); // copy string one into the result.
//	strcat(message, " "); // append string two to the result.
//	strcat(message, lastComunication);
//	/*message2 = message;*/
//	_lastComunication = message;
//
//
//}
//
//char* sensor::getLastComunication()
//{
//	return _lastComunication;
//}

//float sensor::getSegnalValue()
//{
//	_sensorValue = analogicRead();
//	return _sensorValue;
//}

//float sensor::analogicRead()
//{
//	_sensorValue = (_vref / 1024) * analogRead(_analSignalPin);
//	return _sensorValue;
//}

//bool sensor::isAnalogicValueOutOfRange()
//{
//	if (analogicRead() >= _maxValue || analogicRead() <= _analogicAllarmMinValue)
//	{
//		setLastComunication("could be damaged");
//		return true;
//	}
//	else
//	{
//		setLastComunication("seems ok");
//		return false;
//	}
//}






#include "microInterface.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial* softwareSerial = NULL;

microInterface::microInterface(uint8_t analogPin, uint8_t digitalPin, uint8_t rx, uint8_t tx)
{
	if (rx != 255 || tx != 255)
	{
		softwareSerial = new  SoftwareSerial(rx, tx, true);
	}
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

bool microInterface::print(const char* data)
{
	if (softwareSerial != NULL)
	{
			softwareSerial->print(data);
	}
	else
	{
			Serial.print(data);
	}
	return true;
}

bool microInterface::print(float data)
{
	if (softwareSerial != NULL)
	{
		softwareSerial->print(data);
	}
	else
	{
		Serial.print(data);
	}
	return true;
}

bool microInterface::println(const char* data)
{
	if (softwareSerial != NULL)
	{
		softwareSerial->println(data);
	}
	else
	{
		Serial.println(data);
	}
	return true;
}

bool microInterface::println(float data)
{
	if (softwareSerial != NULL)
	{
		softwareSerial->println(data);
	}
	else
	{
		Serial.println(data);
	}
	return true;
}

bool microInterface::serialBegin(unsigned long baud)
{
	if (softwareSerial != NULL)
	{
		softwareSerial->begin(baud);
	}
	else
	{
		Serial.begin(baud);
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






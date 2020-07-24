#include "sensorInterface.h"
#include <Arduino.h>

sensorInterface::sensorInterface() {}

sensorInterface::sensorInterface(uint8_t analogPin, float analogicAllarmMaxValue, float analogicAllarmMinValue, char* uid)
{
	_analogPin = analogPin;
	_analogicAllarmMaxValue = analogicAllarmMaxValue;
	_analogicAllarmMinValue = analogicAllarmMinValue;
	_uid = uid;
	sensorInterface(analogPin, 0,analogicAllarmMaxValue,_analogicAllarmMinValue, uid);
}

sensorInterface::sensorInterface(char* uid,float analogicAllarmMaxValue, float analogicAllarmMinValue, uint8_t digitalSegnalPin)
{
	_digitalPin = digitalSegnalPin;
	pinMode(digitalSegnalPin, INPUT);
	_uid = uid;
	sensorInterface(0, digitalSegnalPin,analogicAllarmMaxValue,analogicAllarmMinValue, uid);

}

sensorInterface::sensorInterface(uint8_t analogPin, uint8_t digitalPin, float analogicAllarmMaxValue, float analogicAllarmMinValue, char* uid)
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
	_analogicAllarmMaxValue = analogicAllarmMaxValue;
	_analogicAllarmMinValue = analogicAllarmMinValue;
	_uid = uid;
}

sensorInterface::~sensorInterface() {}

float sensorInterface::getAlarmMinValue() { return _analogicAllarmMinValue; }

float sensorInterface::getAlarmMaxValue() { return _analogicAllarmMaxValue; }

bool sensorInterface::isDigitalSignalPinOn() {
	return digitalRead(_digitalPin);
}

void sensorInterface::setDigitalAlarmPinOut(int alarmPin) {
	pinMode(alarmPin, OUTPUT);
	_alarmPin = alarmPin;
}

void sensorInterface::switchAlarmPin_On_Off(unsigned long time) {
	digitalWrite(_alarmPin, HIGH);
	delay(time);
	digitalWrite(_alarmPin, LOW);
}

void sensorInterface::turnAlarmPinOn() {
	digitalWrite(_alarmPin, HIGH);
}

void sensorInterface::turnAllarmPinOff() {
	digitalWrite(_alarmPin, LOW);
}

bool sensorInterface::isAllarmPinOn() {
	return digitalRead(_alarmPin);
}

int sensorInterface::analogicRead() {
	return analogRead(_analogPin);
}

char* sensorInterface::uid()
{
	return _uid;
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





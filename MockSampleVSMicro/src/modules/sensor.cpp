#include "sensor.h"
#include <Arduino.h>


sensor::sensor(uint8_t analSignalPin, float analogicAllarmMaxValue, float analogicAllarmMinValue, char* uid)
{
	_analSignalPin = analSignalPin;
	_analogicAllarmMaxValue = analogicAllarmMaxValue;
	_analogicAllarmMinValue = analogicAllarmMinValue;
	_uid = uid;
	sensor(analSignalPin, 0,analogicAllarmMaxValue,_analogicAllarmMinValue, uid);
}

sensor::sensor(char* uid,float analogicAllarmMaxValue, float analogicAllarmMinValue, uint8_t digitalSegnalPin)
{
	_digitalSignalPin = digitalSegnalPin;
	pinMode(digitalSegnalPin, INPUT);
	_uid = uid;
	sensor(0, digitalSegnalPin,analogicAllarmMaxValue,analogicAllarmMinValue, uid);

}

sensor::sensor(uint8_t analSignalPin, uint8_t digitalSegnalPinIn, float analogicAllarmMaxValue, float analogicAllarmMinValue, char* uid)
{
	if (analSignalPin != 0)
	{
		_analSignalPin = analSignalPin;
	}
	if (digitalSegnalPinIn != 0)
	{
		_digitalSignalPin = digitalSegnalPinIn;
		pinMode(digitalSegnalPinIn, INPUT);
	}
	_analogicAllarmMaxValue = analogicAllarmMaxValue;
	_analogicAllarmMinValue = analogicAllarmMinValue;
	_uid = uid;
}

sensor::~sensor() {}

float sensor::getAlarmMinValue() { return _analogicAllarmMinValue; }

float sensor::getAlarmMaxValue() { return _analogicAllarmMaxValue; }

bool sensor::isDigitalSignalPinOn() {
	return digitalRead(_digitalSignalPin);
}

void sensor::setDigitalAlarmPinOut(int alarmPin) {
	pinMode(alarmPin, OUTPUT);
	_alarmPin = alarmPin;
}

void sensor::switchAlarmPin_On_Off(unsigned long time) {
	digitalWrite(_alarmPin, HIGH);
	delay(time);
	digitalWrite(_alarmPin, LOW);
}

void sensor::turnAlarmPinOn() {
	digitalWrite(_alarmPin, HIGH);
}

void sensor::turnAllarmPinOff() {
	digitalWrite(_alarmPin, LOW);
}

bool sensor::isAllarmPinOn() {
	return digitalRead(_alarmPin);
}


int sensor::analogicRead() {
	return analogRead(_analSignalPin);
}


char* sensor::uid()
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






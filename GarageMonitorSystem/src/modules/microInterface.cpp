#include "microInterface.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial* softwareSerial;

microInterface::microInterface(){
	softwareSerial = NULL;
}

microInterface::microInterface(uint8_t rx, uint8_t tx, bool invers_logic)
{
	softwareSerial = new  SoftwareSerial(rx, tx, invers_logic);
}

microInterface::microInterface(char analogPin, uint8_t digitalPin)
{
	_analogPin = analogPin;
	_digitalPin = digitalPin;
	pinMode(digitalPin, INPUT);
	softwareSerial = NULL;
}

microInterface::~microInterface() 
{
	delete softwareSerial;
}

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

//bool microInterface::print(const char* data)
//{
//	if (softwareSerial != NULL)
//	{
//		softwareSerial->print(data);
//	}
//	else
//	{
//		Serial.print(data);
//	}
//	return true;
//}
//
//bool microInterface::print(float data)
//{
//	if (softwareSerial != NULL)
//	{
//		softwareSerial->print(data);
//	}
//	else
//	{
//		Serial.print(data);
//	}
//	return true;
//}
//
//bool microInterface::println(const char* data)
//{
//	if (softwareSerial != NULL)
//	{
//		softwareSerial->println(data);
//	}
//	else
//	{
//		Serial.println(data);
//	}
//	return true;
//}

bool microInterface::consoleWrite(const char* data)
{
	Serial.println(data);
}

//bool microInterface::println(float data)
//{
//	if (softwareSerial != NULL)
//	{
//		softwareSerial->println(data);
//	}
//	else
//	{
//		Serial.println(data);
//	}
//	return true;
//}

//Only used for software serial,initialize Serial in setup program.
bool microInterface::serial_begin(unsigned long baud)
{
	if (softwareSerial != NULL)
	{
		softwareSerial->begin(baud);
	}
}

bool microInterface::serial_available()
{
	if (softwareSerial != NULL)
	{
		if (softwareSerial->available() > 0)
		{
			return true;
		}
	}
	else
	{
		if (Serial.available() > 0)
		{
			return true;
		}
	}
	return false;
}

bool microInterface::delay_m(unsigned long millisencond) {
	delay(millisencond);
}

int microInterface::read() {
	if (softwareSerial != NULL)
	{
		return softwareSerial->read();
	}
		return Serial.read();
}

char* microInterface::readString() {
	char a[250];
	char b[500];
	String c;
	if (softwareSerial != NULL)
	{

		while (softwareSerial->available() > 0) {
			c.concat((char)softwareSerial->read());
		}

		//c = softwareSerial->readString();
		c.toCharArray(a, c.length());
		strcpy(b, a);
		return b;
	}
	else
	{
		String c = Serial.readString();
		c.toCharArray(a, c.length());
		strcpy(b, a);
		return b;
	}
}

char* microInterface::readBuffer()
{
	char a[250];
	char b[500];
	String c;
	if (softwareSerial != NULL)
	{
		c = softwareSerial->readString();
		c.toCharArray(a, c.length());
		strcpy(b, a);
		return b;
	}
	else
	{
		String c = Serial.readString();
		c.toCharArray(a, c.length());
		strcpy(b, a);
		return b;
	}
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






#include "MainRepository.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial* softwareSerial;

MainRepository::MainRepository(){
	softwareSerial = NULL;
}

MainRepository::MainRepository(uint8_t rx, uint8_t tx, bool invers_logic)
{
	softwareSerial = new  SoftwareSerial(rx, tx, invers_logic);
}

MainRepository::MainRepository(char analogPin, uint8_t digitalPin)
{
	_analogPin = analogPin;
	_digitalPin = digitalPin;
	pinMode(digitalPin, INPUT);
	softwareSerial = NULL;
}

MainRepository::~MainRepository() 
{
	delete softwareSerial;
}

void MainRepository::setDigitalAlarmPinOut(int alarmPin) {
	pinMode(alarmPin, OUTPUT);
	_alarmPin = alarmPin;
}

void MainRepository::switchAlarmPin_On_Off(unsigned long time) {
	digitalWrite(_alarmPin, HIGH);
	delay(time);
	digitalWrite(_alarmPin, LOW);
}


int MainRepository::analogicRead() {
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


bool MainRepository::serial_available()
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

int MainRepository::read() {
	if (softwareSerial != NULL)
	{
		return softwareSerial->read();
	}
		return Serial.read();
}

char* MainRepository::readString() {
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

char* MainRepository::readBuffer()
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





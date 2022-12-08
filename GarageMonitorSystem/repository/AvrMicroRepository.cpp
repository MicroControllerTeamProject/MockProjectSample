#include "AvrMicroRepository.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial* softwareSerial;

AvrMicroRepository::AvrMicroRepository(){
	/*this->_vref = _vref;
	this->_referenceMode;*/
	softwareSerial = NULL;
}

//AvrMicroRepository::AvrMicroRepository()
//{
//	softwareSerial = new  SoftwareSerial(rx, tx, invers_logic);
//}

AvrMicroRepository::~AvrMicroRepository() 
{
	delete softwareSerial;
}

void AvrMicroRepository::analogReferencem(uint8_t mode)
{
	analogReference(mode);
}

//float AvrMicroRepository::analogVrefRead(float vref,uint8_t analogPin) {
//	return (vref / 1024) * analogRead(analogPin);
//}

uint16_t AvrMicroRepository::analogReadm(uint8_t analogPin) {
	return analogRead(analogPin);
}

uint8_t AvrMicroRepository::digitalReadm(uint8_t analogPin) {
	return digitalRead(analogPin);
}

bool AvrMicroRepository::print(const char* data)
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

bool AvrMicroRepository::print(float data)
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

bool AvrMicroRepository::println(const char* data)
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

bool AvrMicroRepository::println(float data)
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

bool AvrMicroRepository::serial_available()
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

int AvrMicroRepository::read() {
	if (softwareSerial != NULL)
	{
		return softwareSerial->read();
	}
		return Serial.read();
}

char* AvrMicroRepository::readString() {
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

char* AvrMicroRepository::readBuffer()
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

void AvrMicroRepository::pinModem(uint8_t pin, uint8_t mode)
{
	pinMode(pin, mode);
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






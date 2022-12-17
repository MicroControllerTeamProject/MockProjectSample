#include "AvrMicroRepository.h"
#include <Arduino.h>


AvrMicroRepository::AvrMicroRepository() {
}

void AvrMicroRepository::analogReferencem(uint8_t mode)
{
	analogReference(mode);
}

uint16_t AvrMicroRepository::analogReadm(uint8_t analogPin) {
	return analogRead(analogPin);
}

uint8_t AvrMicroRepository::digitalReadm(uint8_t analogPin) {
	return digitalRead(analogPin);
}

void AvrMicroRepository::print(const char* data)
{
	Serial.print(data);
}

void AvrMicroRepository::print(float data)
{
	Serial.print(data);
}

void AvrMicroRepository::println(const char* data)
{
	Serial.println(data);
}

void AvrMicroRepository::println(float data)
{
	Serial.println(data);
}

bool AvrMicroRepository::serial_available()
{
	if (Serial.available() > 0) return true;
	return false;
}

void AvrMicroRepository::serialBegin(unsigned long baud)
{
	Serial.begin(baud);
}

int AvrMicroRepository::read() {
	return Serial.read();
}

void AvrMicroRepository::readStringm(char* &charsBufferByReference) {
	
	String bufferString = Serial.readString();
	charsBufferByReference = (char*)calloc(bufferString.length(), sizeof(char));
	bufferString.toCharArray(charsBufferByReference, bufferString.length());
}

void AvrMicroRepository::pinModem(uint8_t pin, uint8_t mode)
{
	pinMode(pin, mode);
}

void AvrMicroRepository::delaym(unsigned long delayTime)
{
	delay(delayTime);
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






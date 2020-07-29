#pragma once
#include "stdint.h"

class microInterface
{
public:

	microInterface();

	microInterface(uint8_t analSignalPin, uint8_t digitalSegnalPinIn);
	
	~microInterface();
	
	void setDigitalAlarmPinOut(int alarmPin);

	virtual int analogicRead();

	void switchAlarmPin_On_Off(unsigned long time);

	void turnAlarmPinOn();

	void turnAllarmPinOff();

	virtual bool isAllarmPinOn();

	virtual bool isDigitalSignalPinOn();

	//virtual bool printFloat(float data, bool isCR);

	//virtual bool printFloat(float data, bool isCR, uint8_t tx, uint8_t rx);

	virtual bool print(const char* data, bool isCR);

	//virtual bool printTest(const char* data,int end);

	//virtual bool printTest(int data);

	virtual bool print(float data, bool isCR);

	virtual bool print(float data, bool isCR, uint8_t tx, uint8_t rx);

private :
	int _analogPin;

	uint8_t _digitalPin;

	int _alarmPin;

};


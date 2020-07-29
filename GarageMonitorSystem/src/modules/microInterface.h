#pragma once
#include "stdint.h"

class microInterface
{
public:

	microInterface();

	microInterface(uint8_t analSignalPin, uint8_t digitalSegnalPinIn);
	
	~microInterface();
	
	virtual void setDigitalAlarmPinOut(int alarmPin);

	virtual int analogicRead();

	virtual void switchAlarmPin_On_Off(unsigned long time);

	virtual void turnAlarmPinOn();

	virtual void turnAllarmPinOff();

	virtual bool isAllarmPinOn();

	virtual bool isDigitalSignalPinOn();

	virtual bool print(const char* data, bool isCR);

	virtual bool print(float data, bool isCR);

	virtual bool print(float data, bool isCR, uint8_t tx, uint8_t rx);

private :
	int _analogPin;

	uint8_t _digitalPin;

	int _alarmPin;

};


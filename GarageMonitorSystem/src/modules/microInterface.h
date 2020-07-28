#pragma once
#include "stdint.h"

class microInterface
{
public:

	microInterface();

	microInterface(uint8_t analSignalPin, float analogicAllarmMaxValue, float analogicAllarmMinValue);

	microInterface(float analogicAllarmMaxValue, float analogicAllarmMinValue,uint8_t digitalSegnalPinIn);

	microInterface(uint8_t analSignalPin, uint8_t digitalSegnalPinIn, float analogicAllarmMaxValue, float analogicAllarmMinValue);
	
	~microInterface();

	virtual float getAlarmMinValue();

	virtual float getAlarmMaxValue();
	
	void setDigitalAlarmPinOut(int alarmPin);

	virtual int analogicRead();

	void switchAlarmPin_On_Off(unsigned long time);

	void turnAlarmPinOn();

	void turnAllarmPinOff();

	virtual bool isAllarmPinOn();

	virtual bool isDigitalSignalPinOn();

	virtual bool printFloat(float data, bool isCR);

	virtual bool printFloat(float data, bool isCR, uint8_t tx, uint8_t rx);

	virtual bool printData(const char* data, bool isCR);

	virtual bool printTest(double data,int end);

	virtual bool printTest(int data);


private :

	float _analogicAllarmMinValue;

	float _analogicAllarmMaxValue;

	int _analogPin;

	uint8_t _digitalPin;

	int _alarmPin;

};


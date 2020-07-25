#pragma once
#include "stdint.h"

class sensorInterface
{
public:

	sensorInterface();

	sensorInterface(uint8_t analSignalPin, float analogicAllarmMaxValue, float analogicAllarmMinValue);

	sensorInterface(float analogicAllarmMaxValue, float analogicAllarmMinValue,uint8_t digitalSegnalPinIn);

	sensorInterface(uint8_t analSignalPin, uint8_t digitalSegnalPinIn, float analogicAllarmMaxValue, float analogicAllarmMinValue);
	
	~sensorInterface();

	virtual float getAlarmMinValue();

	virtual float getAlarmMaxValue();
	
	void setDigitalAlarmPinOut(int alarmPin);

	virtual int analogicRead();

	void switchAlarmPin_On_Off(unsigned long time);

	void turnAlarmPinOn();

	void turnAllarmPinOff();

	virtual bool isAllarmPinOn();

	virtual bool isDigitalSignalPinOn();

	void print(float data, bool isCR);

private :

	float _analogicAllarmMinValue;

	float _analogicAllarmMaxValue;

	int _analogPin;

	uint8_t _digitalPin;

	int _alarmPin;

};


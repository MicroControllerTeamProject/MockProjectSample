#pragma once
#include "stdint.h"



class sensor
{
public:

	sensor();

	sensor(uint8_t analSignalPin, float analogicAllarmMaxValue, float analogicAllarmMinValue, char* uid);

	sensor(char* uid, float analogicAllarmMaxValue, float analogicAllarmMinValue,uint8_t digitalSegnalPinIn);

	sensor(uint8_t analSignalPin, uint8_t digitalSegnalPinIn, float analogicAllarmMaxValue, float analogicAllarmMinValue,char* uid);
	
	~sensor();

	virtual float getAlarmMinValue();

	virtual float getAlarmMaxValue();
	
	void setDigitalAlarmPinOut(int alarmPin);

	virtual int analogicRead();

	void switchAlarmPin_On_Off(unsigned long time);

	void turnAlarmPinOn();

	void turnAllarmPinOff();

	virtual bool isAllarmPinOn();

	virtual bool isDigitalSignalPinOn();

	char* uid();


private :

	float _analogicAllarmMinValue;

	float _analogicAllarmMaxValue;

	int _analogPin;

	uint8_t _digitalPin;

	int _alarmPin;

	char* _uid;
};


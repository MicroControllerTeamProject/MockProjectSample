#pragma once
#include "stdint.h"


class MainRepository
{
public:

	MainRepository();

	MainRepository(char analSignalPin, uint8_t digitalSegnalPinIn);

	MainRepository(uint8_t rx, uint8_t tx, bool invers_logic);
	
	~MainRepository();
	
	virtual void setDigitalAlarmPinOut(int alarmPin);

	virtual int analogicRead();

	virtual void switchAlarmPin_On_Off(unsigned long time);

	virtual bool serial_available();

	virtual int read();

	virtual char* readString();

	virtual char* readBuffer();

private :
	int _analogPin;

	uint8_t _digitalPin;

	int _alarmPin;

};


#pragma once
#include "stdint.h"


class microInterface
{
public:

	microInterface();

	microInterface(char analSignalPin, uint8_t digitalSegnalPinIn);

	microInterface(uint8_t rx, uint8_t tx, bool invers_logic);
	
	~microInterface();
	
	virtual void setDigitalAlarmPinOut(int alarmPin);

	virtual int analogicRead();

	virtual void switchAlarmPin_On_Off(unsigned long time);

	virtual void turnAlarmPinOn();

	virtual void turnAllarmPinOff();

	virtual bool isAllarmPinOn();

	virtual bool isDigitalSignalPinOn();

	virtual bool serial_begin(unsigned long baud);

	virtual bool serial_available();

	virtual bool print(const char* data);

	virtual bool print(float data);

	virtual bool println(const char* data);

	virtual bool println(float data);

	virtual bool consoleWrite(const char* data);

	virtual bool delay_m(unsigned long);

	virtual int read();

	virtual char* readString();

	virtual char* readBuffer();

private :
	int _analogPin;

	uint8_t _digitalPin;

	int _alarmPin;

};


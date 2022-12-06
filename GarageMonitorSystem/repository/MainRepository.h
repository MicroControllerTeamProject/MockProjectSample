#pragma once
#include "stdint.h"


class MainRepository
{
public:

	MainRepository();
	
	~MainRepository();

	virtual void analogReferencem(uint8_t mode);
	
	virtual uint16_t analogReadm(uint8_t analogPin);

	virtual uint8_t digitalReadm(uint8_t analogPin);

	/*virtual float analogVrefRead(float vref,uint8_t analogPin);*/

	virtual bool print(const char* data);

	virtual bool print(float data);

	virtual bool println(const char* data);

	virtual bool println(float data);

	virtual bool serial_available();

	virtual int read();

	virtual char* readString();

	virtual char* readBuffer();

	virtual void pinModem(uint8_t pin,uint8_t mode);

private :
	/*float _vref;
	uint8_t _referenceMode;*/
};


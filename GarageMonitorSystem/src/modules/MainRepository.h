#pragma once
#include "stdint.h"


class MainRepository
{
public:

	MainRepository(float vref, uint8_t referenceMod);

	MainRepository(uint8_t rx, uint8_t tx, bool invers_logic);
	
	~MainRepository();

	virtual void analogReferencem(uint8_t mode);
	
	virtual uint16_t analogReadm(uint8_t analogPin);

	virtual float analogVrefRead(uint8_t analogPin);

	virtual bool print(const char* data);

	virtual bool print(float data);

	virtual bool println(const char* data);

	virtual bool println(float data);

	virtual bool serial_available();

	virtual int read();

	virtual char* readString();

	virtual char* readBuffer();

	virtual void pinMode(uint8_t pin,uint8_t mode);

private :
	float _vref;
	uint8_t _referenceMode;
};


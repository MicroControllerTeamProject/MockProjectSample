#pragma once
#include "stdint.h"


class AvrMicroRepository
{
public:

	AvrMicroRepository();
	
	/*~AvrMicroRepository();*/

	virtual void analogReferencem(uint8_t mode);
	
	virtual uint16_t analogReadm(uint8_t analogPin);

	virtual uint8_t digitalReadm(uint8_t analogPin);

	/*virtual float analogVrefRead(float vref,uint8_t analogPin);*/

	virtual void print(const char* data);

	virtual void print(float data);

	virtual void println(const char* data);

	virtual void println(float data);

	virtual bool serial_available();

	virtual void serialBegin(unsigned long baud);

	virtual int read();

	virtual void readStringm(char* &charsBuffer);

	virtual void pinModem(uint8_t pin,uint8_t mode);

	virtual void delaym(unsigned long delayTime);


private :
	/*float _vref;
	uint8_t _referenceMode;*/
};


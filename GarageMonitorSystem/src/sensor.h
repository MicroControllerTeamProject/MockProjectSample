#include "modules/MainRepository.h"

class analogSensor
{
public:
	analogSensor(float vref, const char* uid, float analogMinValue, float analogMaxValue);
	virtual bool isSensorWorking(MainRepository& sr);
	uint16_t analogVrefRead(MainRepository& sr);
	uint16_t getAnalogMinValue();
	uint16_t getAnalogMaxValue();
	float getVref();
	const char* getUid();

protected:
	float _vref;
	const char* _uid;
	uint16_t _analogMinValue;
	uint16_t _analogMaxValue;
};


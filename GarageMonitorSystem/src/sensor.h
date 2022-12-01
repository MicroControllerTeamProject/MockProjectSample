#include "modules/MainRepository.h"

class analogSensor
{
public:
	analogSensor(float vref, const char* uid, float analogMinValue, float analogMaxValue);
	virtual bool isSensorWorking(MainRepository& sr);
	uint16_t analogVrefRead(MainRepository& sr);
	float getAnalogMinValue();
	float getAnalogMaxValue();
	float getVref();
	const char* getUid();

protected:
	float _vref;
	const char* _uid;
	float _analogMinValue;
	float _analogMaxValue;
};


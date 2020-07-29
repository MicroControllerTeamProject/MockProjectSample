#include "src/modules/microInterface.h"

class sensor
{
public:
	sensor(float vref, const char* uid, float analogMinValue, float analogMaxValue);
	bool isSensorWorking(microInterface& sr);
	float analogVrefRead(microInterface& sr);
	float getAnalogMinValue();
	float getAnalogMaxValue();
	float getVref();
	const char* getUid();

private:
	float _vref;
	const char* _uid;
	float _analogMinValue;
	float _analogMaxValue;
};

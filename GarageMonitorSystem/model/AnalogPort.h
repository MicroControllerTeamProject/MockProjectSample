#pragma once
#include"..\repository\MainRepository.h"

class AnalogPort
{
public:
	AnalogPort(char* uid, uint8_t pin);
	bool	isEnable = true;
	float	maxVoltageAlarmValueIn = 0;
	float	minVoltageAlarmValueIn = 0;
	uint16_t	 maxAlarmValueIn = 0;
	uint16_t	 minAlarmValueIn = 0;
	float unitOfMisureFullScale = 0;
	float maxUnitOfMisureAlarmValue = 0;
	float minUnitOfMisureAlarmValue = 0;
	char* getUid();
	uint8_t getPin();
private:
	char* _uid;
	uint8_t _pin;
};

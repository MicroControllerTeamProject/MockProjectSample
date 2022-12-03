#pragma once
//#include "DigitalPort.h"
#include "AnalogPort.h"
#include "..\src\modules\MainRepository.h"


class DeviceActivity
{
public:
	/*DeviceActivity(DigitalPort** digitalPort, uint8_t digitalPortsNumber, MainRepository& mainRepository);*/
	DeviceActivity(AnalogPort** analogPort,float vref, uint8_t digitalPortsNumber);
	//virtual bool isThereAnyPortOnAlarm();
	//virtual String getLastAlarmDescription();
	//bool digitalWriteByName(String portName, uint8_t pinLevel);
	//uint8_t digitalReadByName(String portName);
	/*float analogReadVoltageByName(String portName);
	int analogReadByName(String portName);*/
	//String getLastErrorDescription();
	/*MainRepository& _mainRepository;*/
	bool isThereAnyAnalogPortOnAlarm(MainRepository& mainRepository);
	
private:
	//DigitalPort** digitalPort;
	AnalogPort** analogPort;
	uint8_t digitalPortsNumber = 0;
	uint8_t analogPortsNumber = 0;
	/*String lastAlarmDescription = "";
	String lastErrorDescription = "";*/
	char lastAlarmCode;
	char lastErrorCode;
	float vref = 5;
	//virtual float getUnitOfMisureValue(String portName);
	//virtual  float  getCustomMisureValue();
	//bool isThereAnyCustomMisureOnAlarm();
	//bool isThereAnyDigitalPortOnAlarm();
	

	
	
};


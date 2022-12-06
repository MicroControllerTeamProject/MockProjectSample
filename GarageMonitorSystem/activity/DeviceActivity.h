#pragma once
//#include "DigitalPort.h"
#include "..\model\AnalogPort.h"
#include "..\model\DigitalPort.h"
#include "..\repository\MainRepository.h"


class DeviceActivity
{
public:
	DeviceActivity(DigitalPort** digitalPort, uint8_t digitalPortsNumber);
	DeviceActivity(AnalogPort** analogPort,float _vref, uint8_t analogPortsNumber);
	//virtual bool isThereAnyPortOnAlarm();
	//virtual String getLastAlarmDescription();
	//bool digitalWriteByName(String portName, uint8_t pinLevel);
	//uint8_t digitalReadByName(String portName);
	/*float analogReadVoltageByName(String portName);
	int analogReadByName(String portName);*/
	//String getLastErrorDescription();
	/*MainRepository& _mainRepository;*/
	
	
private:
	/*DigitalPort** digitalPort;*/
	/*AnalogPort** analogPort;*/
	uint8_t digitalPortsNumber = 0;
	/*uint8_t _analogPortsNumber = 0;*/
	char _lastAlarmDescription[10];
	/*String lastAlarmDescription = "";
	String lastErrorDescription = "";*/
	char lastAlarmCode;
	char lastErrorCode;
	float _vref = 5;
	//virtual float getUnitOfMisureValue(String portName);
	//virtual  float  getCustomMisureValue();
	//bool isThereAnyCustomMisureOnAlarm();
	//bool isThereAnyDigitalPortOnAlarm();
	
protected:
	uint8_t _analogPortsNumber = 0;
	AnalogPort** analogPort;
	DigitalPort** digitalPort;
	bool isThereAnyAnalogPortOnAlarm(MainRepository& mainRepository);
	bool isThereAnyDigitalPortOnAlarm(MainRepository& mainRepository);
	float getVref();
};

#pragma once
//#include "DigitalPort.h"
#include "..\model\AnalogPort.h"
#include "..\model\DigitalPort.h"
#include "..\repository\AvrMicroRepository.h"
#include "..\commons\commonsLayer.h"


class DeviceActivity
{

public:
	
	DeviceActivity(DigitalPort** digitalPort, uint8_t digitalPortsNumber);
	DeviceActivity(AnalogPort** analogPort,float _vref ,commonsLayer::analogRefMode mode, uint8_t analogPortsNumber);
	DeviceActivity();
	//virtual bool isThereAnyPortOnAlarm();
	//virtual String getLastAlarmDescription();
	//bool digitalWriteByName(String portName, uint8_t pinLevel);
	//uint8_t digitalReadByName(String portName);
	/*float analogReadVoltageByName(String portName);
	int analogReadByName(String portName);*/
	//String getLastErrorDescription();
	/*AvrMicroRepository& _mainRepository;*/

	//const char* getDeviceOnErrorUID();
	AnalogPort** getAllAnalogPorts();
	DigitalPort** getAllDigitalPorts();
	uint8_t getAnalogPortsNumber();
	uint8_t getDigitalPortsNumber();
	
	
private:

	/*DigitalPort** digitalPort;*/
	/*AnalogPort** analogPort;*/
	
	/*uint8_t _analogPortsNumber = 0;*/
	char _lastAlarmDescription[10];
	/*String lastAlarmDescription = "";
	String lastErrorDescription = "";*/
	char _lastAlarmCode;
	char _lastErrorCode;

	//virtual float getUnitOfMisureValue(String portName);
	//virtual  float  getCustomMisureValue();
	//bool isThereAnyCustomMisureOnAlarm();
	//bool isThereAnyDigitalPortOnAlarm();


protected:
	uint8_t _analogPortsNumber = 0;
	uint8_t digitalPortsNumber = 0;
	AnalogPort** analogPort;
	DigitalPort** digitalPort;
	bool isThereAnyAnalogPortOnAlarm(AvrMicroRepository& mainRepository);
	bool isThereAnyDigitalPortOnAlarm(AvrMicroRepository& mainRepository);
	float analogReadVoltageByPin(uint8_t pin, AvrMicroRepository& mainRepository);
	float getVref();
	commonsLayer::analogRefMode vrefMode = commonsLayer::analogRefMode::DEFAULT_m;
	/*char getLastErrorCode();
	void setLastErrorCode(char errorCode);*/
private:
	/*const char* deviceOnErrorUID = {};
	char* deviceErrorValue = {};*/
	/*char lastErrorCode = 'X';*/
	/*uint8_t deviceErrorPin = {};*/
	float _vref = 5;
};


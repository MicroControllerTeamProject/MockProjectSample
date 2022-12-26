/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/

#include <SoftwareSerial.h>
#include <Ultrasonic.h>
#include <string.h>
#include "business/GarageBusinessLayer.h"
#include "repository/AvrMicroRepository.h"
#include "activity/SimModuleActivity.h"
#include "activity/NTC3950thermistorActivity.h"
#include <stdint.h>


////for some MCUs (i.e. the ATmega2560) there's no definition for RAMSTART
//#ifndef RAMSTART
//extern int __data_start;
//#endif

//extern int __data_end;
////extern int __bss_start;
////extern int __bss_end;
//extern int __heap_start;
//extern int __brkval;
//int temp;


//simActivity _simActivity;
//AvrMicroRepository repo;
SoftwareSerial Serial1(7, 8);
void setup() {
	

	/*AnalogPort** analogSmokePorts = new AnalogPort*[1];
	analogSmokePorts[0] = new AnalogPort("Smoke01", 14);
	analogSmokePorts[0]->maxAlarmValueIn = 150;
	analogSmokePorts[0]->minAlarmValueIn = 1;

	DigitalPort** digitalPirPorts = new DigitalPort*[1];
	digitalPirPorts[0] = new DigitalPort("Pir01", 4);
	digitalPirPorts[0]->alarmTriggerOn = DigitalPort::AlarmOn::high;
	digitalPirPorts[0]->direction = DigitalPort::PortDirection::input;

	SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5, 1);
	PirActivity* pirActivity = new PirActivity(digitalPirPorts, 1);
   
	garageBusinessLayer->canOpenTheDoor(avrMicroRepository, smokeActivity, pirActivity);*/
}
void loop() {
	delay(1000);
	GarageBusinessLayer garageBusinessLayer;
	AvrMicroRepository avrMicroRepository;

	AnalogPort** analogNTC3950Ports = new AnalogPort * [1];
	analogNTC3950Ports[0] = new AnalogPort("NTC01", A0);
	analogNTC3950Ports[0]->maxUnitOfMisureAlarmValue = 25.00f;
	analogNTC3950Ports[0]->minUnitOfMisureAlarmValue = 10.00f;

	AnalogPort** analogSmokePorts = new AnalogPort * [1];
	analogSmokePorts[0] = new AnalogPort("smk01", A1);
	analogSmokePorts[0]->maxAlarmValueIn = 150;
	analogSmokePorts[0]->minAlarmValueIn = 1;

	SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5,analogRefMode::DEFAULT_m,1);

	NTC3950thermistorActivity* nTC3950thermistorActivity = new NTC3950thermistorActivity(analogNTC3950Ports, 3.30f, analogRefMode::INTERNAL_m, 1,200000.00f);

	bool result = nTC3950thermistorActivity->isThereAnyPortsOnAlarm(avrMicroRepository);

	SimModuleActivity* simModuleActivity = new SimModuleActivity();
	simModuleActivity->setBaud(19200);
	simModuleActivity->setPrefixAndphoneNumber("+393202445649;");
	
	garageBusinessLayer.checkSystem(avrMicroRepository, smokeActivity,simModuleActivity);

	delete(simModuleActivity);
	delete(nTC3950thermistorActivity);
	delete(smokeActivity);

	delete(analogSmokePorts[0]);
	delete(analogNTC3950Ports[0]);

	free(analogSmokePorts);
	free(analogNTC3950Ports);

	delay(100);
	

//#if defined(VM_DEBUG)
//	avrMicroRepository.print_m("free ram :"); avrMicroRepository.print_m(avrMicroRepository.getFreeRam(), true);
//	avrMicroRepository.clearBuffer_m();
//#endif
}


//void readMemoryAtRunTime()
//{
//	//this is necessary to wait for the Arduino Leonardo to get the serial interface up and running
//#if defined(__ATmega32U4__)
//	while (!Serial);
//#else
//	delay(2000);
//#endif
//
//#ifndef RAMSTART
//	serialPrint("SRAM and .data space start: ", (int)&__data_start);
//#else
//	serialPrint(F("SRAM and .data space start: "), RAMSTART);
//#endif
//	serialPrint(F(".data space end/.bss start: "), (int)&__data_end); //same as "(int)&__bss_start)"
//	serialPrint(F(".bss space end/HEAP start: "), (int)&__heap_start); //same as "(int)&__bss_end);"
//	serialPrint(F("HEAP end: "), (int)__brkval);
//	int tempRam = freeRam();
//	serialPrint(F("STACK start: "), temp);
//	serialPrint(F("STACK and SRAM end: "), RAMEND);
//	serialPrint(F("Free memory at the moment: "), tempRam);
//
//}

////print_m function
//void serialPrint(String tempString, int tempData) {
//	Serial.print_m(tempString);
//	Serial.print_m(tempData, DEC);
//	Serial.print_m(" $");
//	Serial.println(tempData, HEX);
//}





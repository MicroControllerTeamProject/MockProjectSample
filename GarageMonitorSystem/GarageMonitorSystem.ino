/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/

#include <Ultrasonic.h>
#include <string.h>
#include "business/GarageBusinessLayer.h"
#include "repository/AvrMicroRepository.h"


//simActivity _simActivity;

void setup() {
    Serial.begin(9600);

    GarageBusinessLayer* garageBusinessLayer = new GarageBusinessLayer();

    AvrMicroRepository avrMicroRepository;

	AnalogPort** analogSmokePorts = new AnalogPort*[1];
	analogSmokePorts[0] = new AnalogPort("Smoke01", 14);
	analogSmokePorts[0]->maxAlarmValueIn = 150;
	analogSmokePorts[0]->minAlarmValueIn = 1;

	DigitalPort** digitalPirPorts = new DigitalPort*[1];
	digitalPirPorts[0] = new DigitalPort("Pir01", 4);
	digitalPirPorts[0]->alarmTriggerOn = DigitalPort::AlarmOn::high;
	digitalPirPorts[0]->direction = DigitalPort::PortDirection::input;

	SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5, 1);
	PirActivity* pirActivity = new PirActivity(digitalPirPorts, 1);
   
	garageBusinessLayer->canOpenTheDoor(avrMicroRepository, smokeActivity, pirActivity);
}

void loop() {
 
}



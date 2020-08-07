/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/

#include "microInterfaceWaterSensor.h"
#include "microInterfaceSimDevice.h"
#include "src/waterSensorActivity.h"
#include "simActivity.h"
#include <string.h>

microInterfaceWaterSensor micrInterfaceGarageSystem(A0,0);

microInterfaceSimDevice micrInterfaceSimDevice(7, 8,false);

programStates ps;

waterSensorActivity _waterSensorActivity;

simActivity _simActivity;

void setup() {
    Serial.begin(9600);
    //char* pch;
    //pch = strstr(str, "simple");
    //strcmp(str, "simple");

    //strncpy(pch, "sample", 6);
    Serial.println("start");
    /*strncpy(pch, "sample", 6);
    stack::push(str);*/
}

void loop() {
    //_waterSensorActivity.start(micrInterfaceGarageSystem, ps);
    _simActivity.start(micrInterfaceSimDevice, ps);
    Serial.println("Giro");
    delay(5000);
}



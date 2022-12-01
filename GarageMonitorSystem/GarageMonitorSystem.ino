/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/

#include "WatherSensorRepository.h"
#include "microInterfaceSimDevice.h"
#include "src/WatherSensorActivity.h"
#include "simActivity.h"
#include <string.h>

WatherSensorRepository micrInterfaceGarageSystem(A0,0);
//microInterfaceSimDevice micrInterfaceSimDevice(7, 8,false);
//programStates ps;
WatherSensorActivity _waterSensorActivity;
//simActivity _simActivity;

void setup() {
    Serial.begin(9600);
 /*   Serial.println("start");
    SimDevice s("sim");
    micrInterfaceSimDevice.serial_begin(19200);
    s.waitSMSComing(micrInterfaceSimDevice);*/
}

void loop() {
   /* _waterSensorActivity.start(micrInterfaceGarageSystem, ps);*/
   /* _simActivity.start(micrInterfaceSimDevice, ps);*/
    Serial.println("Giro");
    delay(5000);
}



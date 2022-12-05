/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/

#include "GarageDoorRepository.h"
#include "microInterfaceSimDevice.h"
#include "src/GarageDoorActivity.h"
#include "simActivity.h"
#include <string.h>

programStates ps;

GarageDoorActivity garageDoorActivity(ps);

//simActivity _simActivity;

void setup() {
    Serial.begin(9600);
}

void loop() {


   /* _waterSensorActivity.start(micrInterfaceGarageSystem, ps);*/
   /* _simActivity.start(micrInterfaceSimDevice, ps);*/
   /* Serial.println("Giro");
    delay(5000);*/
}



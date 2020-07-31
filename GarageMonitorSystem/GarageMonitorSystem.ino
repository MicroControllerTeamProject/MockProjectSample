/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/

#include "microInterfaceGarageSystem.h"
#include "src/waterSensorActivity.h"

microInterfaceGarageSystem micrInterface(A0,0);

programStates ps;
//sensor* a = new sensor(5, "", 2, 5);

waterSensorActivity _waterSensorActivity;

void setup() {
    Serial.begin(9600);
}

void loop() {
    _waterSensorActivity.start(micrInterface, ps);

}



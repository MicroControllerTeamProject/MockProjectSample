/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/

#include "src/waterSensorActivity.h"

microInterface micrInterface(A0,0);

programStates ps;
waterSensorActivity _waterSensorActivity;

void setup() {
    Serial.begin(9600);
}

void loop() {
    _waterSensorActivity.start(micrInterface, ps);

}



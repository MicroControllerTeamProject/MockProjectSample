/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/
#include "src/modules/waterSensor.h"
#include "src/waterSensorActivity.h"

void setup() {
    Serial.begin(9600);
    waterSensor  ws(5.00,"x01");
    sensorInterface si(A0, 5.00, 2.00);
    programStates ps;
    waterSensorActivity wsa;
    Serial.println(wsa.isWaterDetect(ws, si, ps));
}

void loop() {
   
}



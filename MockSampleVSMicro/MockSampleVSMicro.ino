/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/
//#include "src/modules/waterSensor.h"
//#include "Arduino.h"

// the setup function runs once when you press reset or power the board
//waterSensor* w;
void setup() {
    Serial.begin(9600);
   /* w = new waterSensor(A0,5.00,2.0,4.80, "w1");*/
}

// the loop function runs over and over again until power down or reset
void loop() {
    //Serial.println("test");
    //Serial.println(w->analogicRead());
    //Serial.println(w->isAnalogicValueOutOfRange());
    //Serial.println(w->getLastComunication());
}

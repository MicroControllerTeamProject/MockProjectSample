/*
 Name:		MockSampleVSMicro.ino
 Created:	7/20/2020 7:10:10 PM
 Author:	luigi.santagada
*/

#include "microInterfaceGarageSystem.h"
#include "src/waterSensorActivity.h"

microInterfaceGarageSystem micrInterfaceGarageSystem(A0,0);

programStates ps;

waterSensorActivity _waterSensorActivity;

void setup() {
    
}

void loop() {
    _waterSensorActivity.start(micrInterfaceGarageSystem, ps);
}



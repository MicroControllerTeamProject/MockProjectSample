#include "microInterfaceWaterSensor.h"
#include "src/modules/microInterface.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

microInterfaceWaterSensor::microInterfaceWaterSensor(char analogPin, uint8_t digitalPin) : 
	microInterface(analogPin, digitalPin){
}

bool microInterfaceWaterSensor::blink(){
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);

}


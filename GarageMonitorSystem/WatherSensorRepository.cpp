#include "WatherSensorRepository.h"
#include "src/modules/MainRepository.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

WatherSensorRepository::WatherSensorRepository(char analogPin, uint8_t digitalPin) : 
	MainRepository(analogPin, digitalPin){
}

bool WatherSensorRepository::blink(){
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);

}


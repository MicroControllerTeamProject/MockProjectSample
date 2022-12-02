#include "GarageDoorRepository.h"
#include "src/modules/MainRepository.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

GarageDoorRepository::GarageDoorRepository(char analogPin, uint8_t digitalPin) : 
	MainRepository(analogPin, digitalPin){
}




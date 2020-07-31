#include "microInterfaceGarageSystem.h"
#include "src/modules/microInterface.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

microInterfaceGarageSystem::microInterfaceGarageSystem(uint8_t analogPin, uint8_t digitalPin) : microInterface(analogPin, digitalPin){

}

bool microInterfaceGarageSystem::blink()
{
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);
}


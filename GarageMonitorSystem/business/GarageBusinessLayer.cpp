#include "GarageBusinessLayer.h"

GarageBusinessLayer::GarageBusinessLayer(){
}

bool GarageBusinessLayer::canOpenTheDoor(AvrMicroRepository& avrMicroRepository,SmokeActivity* smokeActivity,PirActivity* pirActivity){
	if (!(smokeActivity->isThereSmoke(avrMicroRepository)) && (pirActivity->isThereAnyOne(avrMicroRepository))) return true;
	return false;
}

char* GarageBusinessLayer::getBatteryGrapfLevel(AvrMicroRepository& avrMicroRepository, VoltageActivity* voltageActivity,uint8_t analogPortPin){
		return voltageActivity->getLipoBatteryGrafBarLevel(avrMicroRepository, analogPortPin);
}


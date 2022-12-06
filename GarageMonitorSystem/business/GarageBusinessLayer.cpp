#include "GarageBusinessLayer.h"

GarageBusinessLayer::GarageBusinessLayer()
{
	
}

bool GarageBusinessLayer::canOpenTheDoor(MainRepository& mainRepository,SmokeActivity* s,PirActivity* p)
{
	if (!(s->isThereSmoke(mainRepository)) && (p->isThereAnyOne(mainRepository))) return true;
	return false;
}

char* GarageBusinessLayer::getBatteryGrapfLevel(MainRepository& mainRepository, VoltageActivity* voltageActivity,uint8_t analogPortPin)
{
		return voltageActivity->getLipoBatteryGrafBarLevel(mainRepository, analogPortPin);
}


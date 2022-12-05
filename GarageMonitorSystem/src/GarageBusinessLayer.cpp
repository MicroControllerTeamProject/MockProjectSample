#include "GarageBusinessLayer.h"

GarageBusinessLayer::GarageBusinessLayer()
{
	
}

bool GarageBusinessLayer::canOpenTheDoor(MainRepository& m,SmokeActivity* s,PirActivity* p)
{
	if (!(s->isThereSmoke(m)) && (p->isThereAnyOne(m))) return true;
	return false;
}

#include "GarageBusinessLayer.h"

GarageBusinessLayer::GarageBusinessLayer() {
}

bool GarageBusinessLayer::canOpenTheDoor(AvrMicroRepository& avrMicroRepository, SmokeActivity* smokeActivity, PirActivity* pirActivity) {
	if (avrMicroRepository.testMethode())return false;
	if (!(smokeActivity->isThereSmoke(avrMicroRepository)) && (pirActivity->isThereAnyOne(avrMicroRepository))) return true;
	return false;
}

char* GarageBusinessLayer::getBatteryGrapfLevel(AvrMicroRepository& avrMicroRepository, VoltageActivity* voltageActivity, uint8_t analogPortPin) {
	return voltageActivity->getLipoBatteryGrafBarLevel(avrMicroRepository, analogPortPin);
}

void GarageBusinessLayer::checkSystem(AvrMicroRepository& avrMicroRepository,SmokeActivity* smokeActivity, SimModuleActivity* simModuleActivity)
{
	if (smokeActivity->isThereSmoke(avrMicroRepository))
	{
		for (int i = 0; i < smokeActivity->getAnalogPortsNumber(); i++)
		{
			if (smokeActivity->getAllAnalogPorts()[i]->isOnError)
			{
				if (simModuleActivity->makeCall(avrMicroRepository))
				{
				}
			}
		}
		
	}

}




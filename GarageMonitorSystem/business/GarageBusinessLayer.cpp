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

void GarageBusinessLayer::checkSystem(AvrMicroRepository& avrMicroRepository, 
	/*SmokeActivity* smokeActivity,*/ SimModuleActivity* simModuleActivity)
{
	/*if (smokeActivity->isThereSmoke(avrMicroRepository))
	{*/
	if (simModuleActivity->makeCall(avrMicroRepository))
	{
		avrMicroRepository.print_chars("Chiamata effettuata", true);
		avrMicroRepository.clearBuffer_m();

	}
	//}
	
}




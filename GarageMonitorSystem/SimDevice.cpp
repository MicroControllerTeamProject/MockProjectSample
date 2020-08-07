#include "SimDevice.h"
#include <string.h>

SimDevice::SimDevice(const char* uid) : SerialDevice(uid) {
	
}

char* SimDevice::dialPhone(char* phoneNumber,microInterfaceSimDevice& microInterfaceSimDevice)
{
	char result[25];   
	strcpy(result, "ATD + "); 
	strcat(result, phoneNumber); 
	strcat(result, ";");
	microInterfaceSimDevice.println(result);
	return "";
}
#include "SimDevice.h"
#include <string.h>

SimDevice::SimDevice(const char* uid) : SerialDevice(uid){	
	
}

char* SimDevice::dialPhone(char* phoneNumber,microInterfaceSimDevice microInterfaceSimDevice)
{
	//if (_isCallDisabled) return;
	char result[25];   
	strcpy(result, "ATD + "); 
	strcat(result, phoneNumber); 
	strcat(result, ";");
	//SIM900.println("ATD + +393397510192;");
	microInterfaceSimDevice.println(result);
	return result;
}
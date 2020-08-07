#include "SimDevice.h"
#include <string.h>

SimDevice::SimDevice(const char* uid) : SerialDevice(uid) {
	
}

char* SimDevice::dialPhone(char* phoneNumber,microInterfaceSimDevice& microInterfaceSimDevice)
{
	//if (_isCallDisabled) return;
	//microInterface* microInterface2 = new microInterface();
	//microInterface2->serial_begin(9600);
	//microInterface2->println("AAAAAAA");
	char result[25];   
	strcpy(result, "ATD + "); 
	strcat(result, phoneNumber); 
	strcat(result, ";");
	//
	////SIM900.println("ATD + +393397510192;");
	//microInterfaceSimDevice.serial_begin(19200);
	//microInterfaceSimDevice.println("ATD + +393202445649;");
	microInterfaceSimDevice.println(result);
	return "";
}
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
	/*microInterfaceSimDevice.println(result);*/
	return "";
}

//Call in setup for sms activation
//void SimDevice::waitSMSComing(microInterfaceSimDevice& microInterfaceSimDevice)
//{
//	microInterfaceSimDevice.println("AT+CPMS=\"SM\"");
//	microInterfaceSimDevice.println("AT+CMGF=1");  // set SMS mode to text	
//	microInterfaceSimDevice.println("AT+CMGD=1,4");
//	// blurt out contents of new SMS upon receipt to the GSM shield's serial out
//	microInterfaceSimDevice.delay_m(100);
//}
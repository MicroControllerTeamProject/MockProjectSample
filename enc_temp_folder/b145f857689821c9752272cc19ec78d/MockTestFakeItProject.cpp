// MockTestFakeItProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\MockSampleVSMicro\src\modules\waterSensor.h"
#include "..\MockSampleVSMicro\src\modules\sensorInterface.h"
#include "..\MockSampleVSMicro\src\waterSensorActivity.h"
#include "..\MockSampleVSMicro\src\programStates.h"
#include "..\MockTestFakeItProject\src\extend.h"

int main()
{
	/*Mock<programStates> mock2;*/

	//programStates& i2 = mock2.get();

	//When(Method(mock2, test)).Return(567); // Method mock.foo will return 1 once.
	
	Mock<sensorInterface> mock;

	When(Method(mock, analogicRead)).Return(50); // Method mock.foo will return 1 once.

	When(Method(mock, getAlarmMinValue)).Return(2); // Method mock.foo will return 1 once.

	//When(Method(mock, print)).Return(true); // Method mock.foo will return 1 once.

	sensorInterface& i = mock.get();

	waterSensor w(5.00,"x01");

	waterSensorActivity* wsa = new waterSensorActivity();

	programStates ps;

	wsa->isWaterDetect(w, i, ps);

	//std::cout << w->isThereWater(i);
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

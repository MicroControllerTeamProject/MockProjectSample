// MockTestFakeItProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\MockSampleVSMicro\src\modules\waterSensor.h"
#include "..\MockSampleVSMicro\src\modules\microInterface.h"
#include "..\MockSampleVSMicro\src\waterSensorActivity.h"
#include "..\MockSampleVSMicro\src\programStates.h"
#include "..\MockTestFakeItProject\src\extend.h"

int main()
{
	Mock<microInterface> mock;

	When(Method(mock, printData)).Return(true); // Method mock.foo will return 1 once.

	When(Method(mock, analogicRead)).Return(50); // Method mock.foo will return 1 once.

	When(Method(mock, getAlarmMinValue)).Return(2); // Method mock.foo will return 1 once.

	When(Method(mock, getAlarmMaxValue)).Return(5); // Method mock.foo will return 1 once.

	microInterface& i = mock.get();

	waterSensor w(5.00,"x01");

	programStates ps;

	waterSensorActivity* wsActivity = new waterSensorActivity();

	wsActivity->start(w, i, ps);

	
	return 0;
}

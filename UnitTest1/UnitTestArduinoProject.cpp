#include "pch.h"
#include "CppUnitTest.h"
#include "..\GarageMonitorSystem\src\modules\waterSensor.h"
#include "..\GarageMonitorSystem\src\modules\microInterface.h"
#include "..\GarageMonitorSystem\src\waterSensorActivity.h"
#include "..\GarageMonitorSystem\src\programStates.h"
#include "src\extend.h"



//https://docs.microsoft.com/it-it/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestArduinoProject
{
	TEST_CLASS(UnitTestArduinoProject)
	{
	public:
		
		TEST_METHOD(TestMethodWaterSensor)
		{
			Mock<microInterface> mock;

			When(OverloadedMethod(mock, printTest,bool(int))).Return(false);

			When(OverloadedMethod(mock, printTest, bool(double,int))).Return(true);

			When(Method(mock, printData)).Return(true);

			When(Method(mock, analogicRead)).Return(50);

			When(Method(mock, getAlarmMinValue)).Return(2);

			When(Method(mock, getAlarmMaxValue)).Return(5);

			microInterface& i = mock.get();

			waterSensor waterSensor(5.00, "x01");

			programStates programStates;

			waterSensorActivity* wsActivity = new waterSensorActivity();

			wsActivity->start(waterSensor, i, programStates);

			Assert::AreEqual(true, programStates._isWaterDetected);
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "..\GarageMonitorSystem\src\modules\waterSensor.h"
#include "..\GarageMonitorSystem\src\modules\microInterface.h"
#include "..\GarageMonitorSystem\src\waterSensorActivity.h"
#include "..\GarageMonitorSystem\src\programStates.h"
#include "src\extend.h"



//https://docs.microsoft.com/it-it/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGarageMonitorSystem
{
	TEST_CLASS(UnitTestGarageMonitorSystem)
	{
	public:
		TEST_METHOD(TestMethod_WaterInGarage)
		{
			Mock<microInterface> mock;

			When(Method(mock, analogicRead)).AlwaysReturn(50);

			When(OverloadedMethod(mock, print, bool(const char*, bool))).AlwaysReturn(false);

			When(OverloadedMethod(mock, print, bool(float,bool))).AlwaysReturn(false);

			When(OverloadedMethod(mock, print, bool(float, bool,uint8_t,uint8_t))).AlwaysReturn(false);

			When(OverloadedMethod(mock, print,bool(const char*, bool))).AlwaysReturn(true);

			microInterface& microInterface = mock.get();


			//waterSensor waterSensor(5.00, "x01",2,5);

			programStates programStates;

			waterSensorActivity* wsActivity = new waterSensorActivity();

			wsActivity->start(microInterface, programStates);

			Assert::AreEqual(true, programStates._isWaterDetected);
		}

		TEST_METHOD(TestMethod_NoWaterInGarage)
		{
			Mock<microInterface> mock;

			When(Method(mock, analogicRead)).AlwaysReturn(1000);

			When(OverloadedMethod(mock, print, bool(const char*, bool))).AlwaysReturn(false);

			When(OverloadedMethod(mock, print, bool(float, bool))).AlwaysReturn(false);

			When(OverloadedMethod(mock, print, bool(float, bool, uint8_t, uint8_t))).AlwaysReturn(false);

			When(OverloadedMethod(mock, print, bool(const char*, bool))).AlwaysReturn(true);

			microInterface& microInterface = mock.get();

			programStates programStates;

			waterSensorActivity* wsActivity = new waterSensorActivity();

			wsActivity->start(microInterface, programStates);

			Assert::AreEqual(false, programStates._isWaterDetected);
		}
	};
}

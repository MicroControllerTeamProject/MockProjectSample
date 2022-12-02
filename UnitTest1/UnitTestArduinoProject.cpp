#include "pch.h"
#include "CppUnitTest.h"
#include "..\GarageMonitorSystem\src\modules\WatherSensor.h"
#include "..\GarageMonitorSystem\GarageDoorRepository.h"
#include "..\GarageMonitorSystem\src\GarageDoorActivity.h"
#include "..\GarageMonitorSystem\src\programStates.h"


#include "src\extend.h"

//https://docs.microsoft.com/it-it/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGarageMonitorSystem
{
	TEST_CLASS(UnitTestGarageMonitorSystem)
	{
	public:
		TEST_METHOD(TestMethod_WatherInGarage)
		{
			Mock<GarageDoorRepository> mock;

			When(Method(mock, analogicRead)).AlwaysReturn(50);

			GarageDoorRepository& garageDoorRepository = mock.get();

			programStates programStates;

			WaterSensor waterSensor(5, "", 1, 0);

			GarageDoorActivity* garageDoorActivity = new GarageDoorActivity();

			Assert::AreEqual(true, garageDoorActivity->isGarageDoorOpening(garageDoorRepository, waterSensor, programStates));
		}



		//TEST_METHOD(TestMethod_NoWaterInGarage)
		//{
		//	Mock<microInterfaceWaterSensor> mock;

		//	When(Method(mock, serial_begin)).AlwaysReturn(false);

		//	When(Method(mock, analogiReadm)).AlwaysReturn(1000);

		//	When(Method(mock, blink)).AlwaysReturn(false);

		//	//When(OverloadedMethod(mock, print, bool(const char*))).AlwaysReturn(false);

		//	//When(OverloadedMethod(mock, print, bool(float))).AlwaysReturn(false);

		//	microInterfaceWaterSensor& microInterface = mock.get();

		//	programStates programStates;

		//	waterSensorActivity* wsActivity = new waterSensorActivity();

		//	wsActivity->start(microInterface, programStates);

		//	Assert::AreEqual(false, programStates._isWaterSensor01Detected);
		//}

	};
}

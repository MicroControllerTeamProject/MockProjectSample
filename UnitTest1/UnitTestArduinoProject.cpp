#include "pch.h"
#include "CppUnitTest.h"
#include "..\GarageMonitorSystem\src\modules\WatherSensor.h"
#include "..\GarageMonitorSystem\WatherSensorRepository.h"
#include "..\GarageMonitorSystem\src\WatherSensorActivity.h"
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
			Mock<WatherSensorRepository> mock;

			When(Method(mock, analogicRead)).AlwaysReturn(50);

	
			WatherSensorRepository& watherSensorRepository = mock.get();

			programStates programStates;

			//WaterSensor* a = new WaterSensor(5, "", 1, 0);

			WatherSensorActivity* wsActivity = new WatherSensorActivity();

			wsActivity->start(watherSensorRepository, programStates);

			Assert::AreEqual(true, programStates._isWaterSensor01Detected);
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

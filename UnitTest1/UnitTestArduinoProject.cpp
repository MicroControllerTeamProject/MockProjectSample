#include "pch.h"
#include "CppUnitTest.h"
#include "..\GarageMonitorSystem\src\modules\WatherSensor.h"
#include "..\GarageMonitorSystem\GarageDoorRepository.h"
#include "..\GarageMonitorSystem\src\GarageDoorActivity.h"
#include "..\GarageMonitorSystem\src\programStates.h"
#include "..\GarageMonitorSystem\library\AnalogPort.h"
#include "..\GarageMonitorSystem\library\SmokeActivity.h"
#include "..\GarageMonitorSystem\library\DeviceActivity.h"



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
			Mock<MainRepository> mock;

			When(Method(mock, analogReadm)).Return(500,600);

			MainRepository& mainRepository = mock.get();

			AnalogPort** analogPort = new AnalogPort * [2];
			analogPort[0] = new AnalogPort("Smoke left", 14);
			analogPort[0]->isEnable = true;
			analogPort[0]->maxAlarmValueIn = 200;
			analogPort[1] = new AnalogPort("Smoke right", 15);
			analogPort[1]->isEnable = true;
			analogPort[1]->maxAlarmValueIn = 200;

			SmokeActivity* smokeActivity = new SmokeActivity(analogPort, 5, 2);

			programStates programStates;

			WaterSensor waterSensor(5, "", 1, 0);

			GarageDoorActivity* garageDoorActivity = new GarageDoorActivity(programStates);

			Assert::AreEqual(true, garageDoorActivity->isGarageDoorToOpen(mainRepository, waterSensor));

			Assert::AreEqual(false, smokeActivity->isThereSmoke(mainRepository));

			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(mainRepository, 0));*/
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

#include "pch.h"
#include "CppUnitTest.h"
#include "..\GarageMonitorSystem\library\AnalogPort.h"
#include "..\GarageMonitorSystem\library\DigitalPort.h"
#include "..\GarageMonitorSystem\library\SmokeActivity.h"
#include "..\GarageMonitorSystem\library\PirActivity.h"
#include "..\GarageMonitorSystem\library\DeviceActivity.h"
#include "..\GarageMonitorSystem\src\GarageBusinessLayer.h"

#include "src\extend.h"

//https://docs.microsoft.com/it-it/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGarageMonitorSystem
{
	TEST_CLASS(UnitTestGarageMonitorSystem)
	{
	public:
		TEST_METHOD(TestMethod_openTheGarageDoor)
		{
#pragma region repository mocked
			//Repository mocked
			Mock<MainRepository> mockForSmoke;
			MainRepository& mainRepositoryForSmoke = mockForSmoke.get();
			Mock<MainRepository> mockForPir;
			MainRepository& mainRepositoryForPir = mockForPir.get();

#pragma endregion Repository mocked

#pragma region objects for test 
			AnalogPort** analogPort = new AnalogPort*[1];
			analogPort[0] = new AnalogPort("Smoke01", 14);
			analogPort[0]->maxAlarmValueIn = 150;
			analogPort[0]->minAlarmValueIn = 1;

			DigitalPort** digitalPort = new DigitalPort*[1];
			digitalPort[0] = new DigitalPort("Pir01", 4);
			digitalPort[0]->alarmTriggerOn = DigitalPort::AlarmOn::high;
			digitalPort[0]->direction = DigitalPort::PortDirection::input;
#pragma endregion objects for test 
			
			SmokeActivity* smokeActivity = new SmokeActivity(analogPort, 5, 1);
			PirActivity* pirActivity = new PirActivity(digitalPort, 1);

#pragma region mocked methods 
			When(Method(mockForSmoke, analogReadm)).AlwaysReturn(500);

			When(Method(mockForPir, digitalReadm)).AlwaysReturn(1);

		/*	When(Method(mockForPir, digitalReadm)).AlwaysReturn(1);*/
#pragma endregion mocked methods 

#pragma region Asserts 

			/*GarageBusinessLayer* b = new GarageBusinessLayer();

			Assert::AreEqual(true, b->canOpenTheDoor(mainRepositoryForSmoke,smokeActivity,pirActivity));*/
			
		/*	Assert::AreEqual(false, smokeActivity->isThereSmoke(mainRepositoryForSmoke));
			Assert::AreEqual(true, pirActivity->isThereAnyOne(mainRepositoryForPir));*/

			Assert::AreEqual(false, smokeActivity->isThereSmoke(mainRepositoryForSmoke));

			Assert::AreEqual(true, pirActivity->isThereAnyOne(mainRepositoryForPir));
#pragma endregion Asserts

			

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

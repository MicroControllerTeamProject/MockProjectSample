#include "pch.h"
#include "CppUnitTest.h"
#include "..\GarageMonitorSystem\model\AnalogPort.h"
#include "..\GarageMonitorSystem\model\DigitalPort.h"
#include "..\GarageMonitorSystem\activity\SmokeActivity.h"
#include "..\GarageMonitorSystem\activity\PirActivity.h"
#include "..\GarageMonitorSystem\activity\DeviceActivity.h"
#include "..\GarageMonitorSystem\business\GarageBusinessLayer.h"
#include "..\GarageMonitorSystem\activity\VoltageActivity.h"

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
			Mock<MainRepository> mockedRepository;
			MainRepository& mainRepository = mockedRepository.get();
#pragma endregion Repository mocked

#pragma region objects for test 
			AnalogPort** analogSmokePorts = new AnalogPort * [1];
			analogSmokePorts[0] = new AnalogPort("Smoke01", 14);
			analogSmokePorts[0]->maxAlarmValueIn = 150;
			analogSmokePorts[0]->minAlarmValueIn = 1;

			DigitalPort** digitalPirPorts = new DigitalPort * [1];
			digitalPirPorts[0] = new DigitalPort("Pir01", 4);
			digitalPirPorts[0]->alarmTriggerOn = DigitalPort::AlarmOn::high;
			digitalPirPorts[0]->direction = DigitalPort::PortDirection::input;
#pragma endregion objects for test 

			SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5, 1);
			PirActivity* pirActivity = new PirActivity(digitalPirPorts, 1);

#pragma region mocked methods 
			When(Method(mockedRepository, analogReadm)).AlwaysReturn(100);
			When(Method(mockedRepository, digitalReadm)).AlwaysReturn(1);
#pragma endregion mocked methods 

#pragma region Asserts 
			GarageBusinessLayer* b = new GarageBusinessLayer();
			Assert::AreEqual(true, b->canOpenTheDoor(mainRepository, smokeActivity, pirActivity));
#pragma endregion Asserts
			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(mainRepository, 0));*/
		}
		TEST_METHOD(TestMethod_cantOpenTheGarageDoor)
		{
#pragma region repository mocked
			Mock<MainRepository> mockedRepository;
			MainRepository& mainRepository = mockedRepository.get();
#pragma endregion Repository mocked

#pragma region objects for test 
			AnalogPort** analogSmokePorts = new AnalogPort * [1];
			analogSmokePorts[0] = new AnalogPort("Smoke01", 14);
			analogSmokePorts[0]->maxAlarmValueIn = 150;
			analogSmokePorts[0]->minAlarmValueIn = 1;

			DigitalPort** digitalPirPorts = new DigitalPort * [1];
			digitalPirPorts[0] = new DigitalPort("Pir01", 4);
			digitalPirPorts[0]->alarmTriggerOn = DigitalPort::AlarmOn::high;
			digitalPirPorts[0]->direction = DigitalPort::PortDirection::input;
#pragma endregion objects for test 

			SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5, 1);
			PirActivity* pirActivity = new PirActivity(digitalPirPorts, 1);

#pragma region mocked methods 
			When(Method(mockedRepository, analogReadm)).AlwaysReturn(500);
			When(Method(mockedRepository, digitalReadm)).AlwaysReturn(1);
#pragma endregion mocked methods 

#pragma region Asserts 
			GarageBusinessLayer* b = new GarageBusinessLayer();
			Assert::AreEqual(false, b->canOpenTheDoor(mainRepository, smokeActivity, pirActivity));
#pragma endregion Asserts
			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(mainRepository, 0));*/
		}
		TEST_METHOD(TestMethod_batteryGrapfIsFull)
		{
#pragma region repository mocked
			Mock<MainRepository> mockedRepository;
			MainRepository& mainRepository = mockedRepository.get();
#pragma endregion Repository mocked

#pragma region objects for test 
			AnalogPort** analogPowerBatteryPorts = new AnalogPort*[1];
			analogPowerBatteryPorts[0] = new AnalogPort("batt01", 14);
			analogPowerBatteryPorts[0]->maxVoltageAlarmValueIn = 5.0f;
			analogPowerBatteryPorts[0]->minVoltageAlarmValueIn = 3.3f;

#pragma endregion objects for test 

			VoltageActivity* voltageActivity = new VoltageActivity(analogPowerBatteryPorts, 5.0f, 1);

#pragma region mocked methods 
			When(Method(mockedRepository, analogVrefRead)).AlwaysReturn(5.0f);
#pragma endregion mocked methods 

#pragma region Asserts 
			GarageBusinessLayer* b = new GarageBusinessLayer();
			Assert::AreEqual("[||||]o", b->getBatteryGrapfLevel(mainRepository, voltageActivity, 14));
#pragma endregion Asserts
			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(mainRepository, 0));*/
		}


	};
}

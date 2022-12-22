#include "pch.h"
#include "CppUnitTest.h"
#include "..\GarageMonitorSystem\model\AnalogPort.h"
#include "..\GarageMonitorSystem\model\DigitalPort.h"
#include "..\GarageMonitorSystem\activity\SmokeActivity.h"
#include "..\GarageMonitorSystem\activity\PirActivity.h"
#include "..\GarageMonitorSystem\activity\DeviceActivity.h"
#include "..\GarageMonitorSystem\business\GarageBusinessLayer.h"
#include "..\GarageMonitorSystem\activity\VoltageActivity.h"
#include "..\GarageMonitorSystem\repository\UltrasonicRepository.h"
#include "..\GarageMonitorSystem\repository\AvrMicroRepository.h"
#include "..\GarageMonitorSystem\activity\UltrasonicActivity.h"
#include "..\GarageMonitorSystem\activity\SimModuleActivity.h"
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
			Mock<AvrMicroRepository> mockedAvrMicroRepository;
			AvrMicroRepository& mainRepository = mockedAvrMicroRepository.get();
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
			When(Method(mockedAvrMicroRepository, analogReadm)).AlwaysReturn(100);
			When(Method(mockedAvrMicroRepository, digitalReadm)).AlwaysReturn(1);
#pragma endregion mocked methods 

#pragma region Asserts 
			GarageBusinessLayer* b = new GarageBusinessLayer();
			Assert::AreEqual(true, b->canOpenTheDoor(mainRepository, smokeActivity, pirActivity));
#pragma endregion Asserts
			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(ultrasonicRepository, 0));*/
		}
		TEST_METHOD(TestMethod_cantOpenTheGarageDoor)
		{
#pragma region repository mocked
			Mock<AvrMicroRepository> mockedAvrMicroRepository;
			AvrMicroRepository& avrMicroRepository = mockedAvrMicroRepository.get();
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
			When(Method(mockedAvrMicroRepository, analogReadm)).AlwaysReturn(500);
			When(Method(mockedAvrMicroRepository, digitalReadm)).AlwaysReturn(1);
#pragma endregion mocked methods 

#pragma region Asserts 
			GarageBusinessLayer* b = new GarageBusinessLayer();
			Assert::AreEqual(false, b->canOpenTheDoor(avrMicroRepository, smokeActivity, pirActivity));
#pragma endregion Asserts
			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(ultrasonicRepository, 0));*/
		}
		TEST_METHOD(TestMethod_batteryGrapfIsFull)
		{
#pragma region repository mocked
			Mock<AvrMicroRepository> mockedAvrMicroRepository;
			AvrMicroRepository& avrMicroRepository = mockedAvrMicroRepository.get();
#pragma endregion Repository mocked

#pragma region objects for test 
			AnalogPort** analogPowerBatteryPorts = new AnalogPort*[1];
			analogPowerBatteryPorts[0] = new AnalogPort("bat01", 14);
			analogPowerBatteryPorts[0]->maxVoltageAlarmValueIn = 5.0f;
			analogPowerBatteryPorts[0]->minVoltageAlarmValueIn = 3.3f;

#pragma endregion objects for test 

			VoltageActivity* voltageActivity = new VoltageActivity(analogPowerBatteryPorts, 4.2f, 1);

#pragma region mocked methods 
			When(Method(mockedAvrMicroRepository, analogReadm)).AlwaysReturn(1024);
#pragma endregion mocked methods 

#pragma region Asserts 
			GarageBusinessLayer* garageBusinessLayer = new GarageBusinessLayer();

			Assert::AreEqual("[||||]o", garageBusinessLayer->getBatteryGrapfLevel(avrMicroRepository, voltageActivity, 14));
#pragma endregion Asserts
			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(ultrasonicRepository, 0));*/
		}
		TEST_METHOD(TestMethod_UltrasonicTest)
		{
#pragma region repository mocked
			Mock<UltrasonicRepository> mockedUltrasonicRepository;
			UltrasonicRepository& ultrasonicRepository = mockedUltrasonicRepository.get();
#pragma endregion Repository mocked
			
#pragma region objects for test 
			DigitalPort** digitalUltasonicPorts = new DigitalPort * [2];

			digitalUltasonicPorts[0] = new DigitalPort("Trig", 4);
			digitalUltasonicPorts[0]->direction = DigitalPort::PortDirection::input;
			digitalUltasonicPorts[1] = new DigitalPort("Echo", 5);
			digitalUltasonicPorts[1]->direction = DigitalPort::PortDirection::output;

#pragma endregion objects for test 
			UltrasonicActivity* ultrasonicActivity = new UltrasonicActivity(digitalUltasonicPorts, 2, "Trig", "Echo");

#pragma region mocked methods 
			When(Method(mockedUltrasonicRepository, getDistance)).AlwaysReturn(500);
#pragma endregion mocked methods 

#pragma region Asserts 
			GarageBusinessLayer* garageBusinessLayer = new GarageBusinessLayer();
			Assert::AreEqual(500u, ultrasonicActivity->getDistance(ultrasonicRepository));
#pragma endregion Asserts
			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(ultrasonicRepository, 0));*/
		}
//
//		TEST_METHOD(TestMethod_PhoneCallIsStarted)
//		{
//#pragma region repository mocked
//			Mock<AvrMicroRepository> mockedAvrMicroRepository;
//			AvrMicroRepository& avrMicroRepository = mockedAvrMicroRepository.get();
//#pragma endregion Repository mocked
//
//			SimModuleActivity* simModuleActivity = new SimModuleActivity();
//			simModuleActivity->setBaud(19200);
//			simModuleActivity->setPrefixAndphoneNumber("+393202445649");
//
//			AnalogPort** analogSmokePorts = new AnalogPort * [1];
//			analogSmokePorts[0] = new AnalogPort("sk01", 15);
//			analogSmokePorts[0]->maxAlarmValueIn = 150;
//			analogSmokePorts[0]->minAlarmValueIn = 1;
//
//			SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5, 1);
//
//#pragma region mocked methods 
//			When(Method(mockedAvrMicroRepository, readString_m)).AlwaysReturn("OK");
//			When(Method(mockedAvrMicroRepository, serial_available)).AlwaysReturn(true);
//
//			//void methods
//			When(Method(mockedAvrMicroRepository, begin_m)).AlwaysReturn();
//			When(Method(mockedAvrMicroRepository, clearBuffer_m)).AlwaysReturn();
//			When(OverloadedMethod(mockedAvrMicroRepository, print_m, void(const char*,bool))).AlwaysReturn();
//			When(Method(mockedAvrMicroRepository, free_m)).AlwaysReturn();
//			When(Method(mockedAvrMicroRepository, delaym)).AlwaysReturn();
//			
//			
//#pragma endregion mocked methods 
//
//#pragma region Asserts 
//			GarageBusinessLayer* garageBusinessLayer = new GarageBusinessLayer();
//			garageBusinessLayer->checkSystem(avrMicroRepository, smokeActivity, simModuleActivity);
//
//			/*bool check = simModuleActivity->makeCall(avrMicroRepository);*/
//			/*Assert::AreEqual(false, check);*/
//#pragma endregion Asserts
//			
//		}
	};
}


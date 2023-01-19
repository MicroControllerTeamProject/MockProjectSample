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
#include "..\GarageMonitorSystem\activity\NTC3950thermistorActivity.h"
#include "..\GarageMonitorSystem\commons\commonsLayer.h"
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
			Mock<AvrMicroRepository> mockedAvrMicroRepository;
			AvrMicroRepository& mainRepository = mockedAvrMicroRepository.get();

			AnalogPort** analogSmokePorts = new AnalogPort * [1];
			analogSmokePorts[0] = new AnalogPort("Smoke01", 14);
			analogSmokePorts[0]->maxAlarmValueIn = 150;
			analogSmokePorts[0]->minAlarmValueIn = 1;

			DigitalPort** digitalPirPorts = new DigitalPort * [1];
			digitalPirPorts[0] = new DigitalPort("Pir01", 4);
			digitalPirPorts[0]->alarmTriggerOn = DigitalPort::AlarmOn::high;
			digitalPirPorts[0]->direction = DigitalPort::PortDirection::input;

			SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5, commonsLayer::analogRefMode::DEFAULT_m, 1);
			PirActivity* pirActivity = new PirActivity(digitalPirPorts, 1);


			When(Method(mockedAvrMicroRepository, analogReadm)).AlwaysReturn(100);
			When(Method(mockedAvrMicroRepository, digitalReadm)).AlwaysReturn(1);
			When(Method(mockedAvrMicroRepository, testMethode)).AlwaysReturn(0);

			GarageBusinessLayer* b = new GarageBusinessLayer();
			Assert::AreEqual(true, b->canOpenTheDoor(mainRepository, smokeActivity, pirActivity));

			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(ultrasonicRepository, 0));*/
		}
		TEST_METHOD(TestMethod_cantOpenTheGarageDoor)
		{

			Mock<AvrMicroRepository> mockedAvrMicroRepository;
			AvrMicroRepository& avrMicroRepository = mockedAvrMicroRepository.get();



			AnalogPort** analogSmokePorts = new AnalogPort * [1];
			analogSmokePorts[0] = new AnalogPort("Smoke01", 14);
			analogSmokePorts[0]->maxAlarmValueIn = 150;
			analogSmokePorts[0]->minAlarmValueIn = 1;

			DigitalPort** digitalPirPorts = new DigitalPort * [1];
			digitalPirPorts[0] = new DigitalPort("Pir01", 4);
			digitalPirPorts[0]->alarmTriggerOn = DigitalPort::AlarmOn::high;
			digitalPirPorts[0]->direction = DigitalPort::PortDirection::input;


			SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5, commonsLayer::analogRefMode::DEFAULT_m, 1);
			PirActivity* pirActivity = new PirActivity(digitalPirPorts, 1);


			When(Method(mockedAvrMicroRepository, analogReadm)).AlwaysReturn(500);
			When(Method(mockedAvrMicroRepository, digitalReadm)).AlwaysReturn(1);
			When(Method(mockedAvrMicroRepository, testMethode)).AlwaysReturn(1);



			GarageBusinessLayer* b = new GarageBusinessLayer();
			Assert::AreEqual(false, b->canOpenTheDoor(avrMicroRepository, smokeActivity, pirActivity));

			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(ultrasonicRepository, 0));*/
		}
		TEST_METHOD(TestMethod_batteryGrapfIsFull)
		{

			Mock<AvrMicroRepository> mockedAvrMicroRepository;
			AvrMicroRepository& avrMicroRepository = mockedAvrMicroRepository.get();

			AnalogPort** analogPowerBatteryPorts = new AnalogPort*[1];
			analogPowerBatteryPorts[0] = new AnalogPort("bat01", 14);
			analogPowerBatteryPorts[0]->maxVoltageAlarmValueIn = 5.0f;
			analogPowerBatteryPorts[0]->minVoltageAlarmValueIn = 3.3f;



			VoltageActivity* voltageActivity = new VoltageActivity(analogPowerBatteryPorts, 4.2f, commonsLayer::analogRefMode::EXTERNAL_m, 1);

			When(Method(mockedAvrMicroRepository, analogReadm)).AlwaysReturn(1024);



			GarageBusinessLayer* garageBusinessLayer = new GarageBusinessLayer();

			Assert::AreEqual("[||||]o", garageBusinessLayer->getBatteryGrapfLevel(avrMicroRepository, voltageActivity, 14));

			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(ultrasonicRepository, 0));*/
		}
		TEST_METHOD(TestMethod_UltrasonicTest)
		{

			Mock<UltrasonicRepository> mockedUltrasonicRepository;
			UltrasonicRepository& ultrasonicRepository = mockedUltrasonicRepository.get();

			DigitalPort** digitalUltasonicPorts = new DigitalPort * [2];

			digitalUltasonicPorts[0] = new DigitalPort("Trig", 4);
			digitalUltasonicPorts[0]->direction = DigitalPort::PortDirection::input;
			digitalUltasonicPorts[1] = new DigitalPort("Echo", 5);
			digitalUltasonicPorts[1]->direction = DigitalPort::PortDirection::output;

			When(Method(mockedUltrasonicRepository, getDistance)).AlwaysReturn(500u);

			UltrasonicActivity* ultrasonicActivity = new UltrasonicActivity(digitalUltasonicPorts, 2, "Trig", "Echo",0);

			GarageBusinessLayer* garageBusinessLayer = new GarageBusinessLayer();
			Assert::AreEqual(500u, ultrasonicActivity->getDistance(ultrasonicRepository));

			/*Assert::AreEqual("[|   ]o", garageDoorActivity->getBatteryGrafBarLevel(ultrasonicRepository, 0));*/
		}
		TEST_METHOD(TestMethod_ThereAreFlamesInGarage)
		{
			Mock<AvrMicroRepository> mockedAvrMicroRepository;
			AvrMicroRepository& mainRepository = mockedAvrMicroRepository.get();

			AnalogPort** analogNTC3950Ports = new AnalogPort * [1];
			analogNTC3950Ports[0] = new AnalogPort("NTC01", 14);
			analogNTC3950Ports[0]->maxUnitOfMisureAlarmValue = 25.00f;
			analogNTC3950Ports[0]->minUnitOfMisureAlarmValue = 10.00f;

			AnalogPort** analogSmokePorts = new AnalogPort * [1];
			analogSmokePorts[0] = new AnalogPort("Smoke01", 15);
			analogSmokePorts[0]->maxAlarmValueIn = 150;
			analogSmokePorts[0]->minAlarmValueIn = 1;

			SmokeActivity* smokeActivity = new SmokeActivity(analogSmokePorts, 5, commonsLayer::analogRefMode::DEFAULT_m, 1);
			NTC3950thermistorActivity* ntc3950thermistorActivity = new NTC3950thermistorActivity(analogNTC3950Ports, 3.30f, commonsLayer::analogRefMode::EXTERNAL_m, 1,200000.0f);
			
			When(Method(mockedAvrMicroRepository, analogVoltageRead_m)).AlwaysReturn(0.70f);
		
			/*When(Method(mockedAvrMicroRepository, analogReadm)).Return(100);*/

			Assert::AreEqual(true, ntc3950thermistorActivity->isThereAnyPortsOnAlarm(mainRepository));
			/*GarageBusinessLayer* b = new GarageBusinessLayer();
			Assert::AreEqual(true, b->canOpenTheDoor(mainRepository, smokeActivity, pirActivity));*/

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


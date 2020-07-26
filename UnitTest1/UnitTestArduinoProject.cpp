#include "pch.h"
#include "CppUnitTest.h"
#include "..\MockSampleVSMicro\src\modules\waterSensor.h"
#include "..\MockSampleVSMicro\src\modules\microInterface.h"
#include "..\MockSampleVSMicro\src\waterSensorActivity.h"
#include "..\MockSampleVSMicro\src\programStates.h"
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

			When(Method(mock, printData)).Return(true);

			When(Method(mock, analogicRead)).Return(50);

			When(Method(mock, getAlarmMinValue)).Return(2);

			When(Method(mock, getAlarmMaxValue)).Return(5);

			microInterface& i = mock.get();

			waterSensor w(5.00, "x01");

			programStates ps;

			waterSensorActivity* wsActivity = new waterSensorActivity();

			wsActivity->start(w, i, ps);

			Assert::AreEqual(true, ps._isWaterDetected);
		}
	};
}

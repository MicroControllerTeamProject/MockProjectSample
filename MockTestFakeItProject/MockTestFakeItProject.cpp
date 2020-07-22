// MockTestFakeItProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\MockSampleVSMicro\src\modules\waterSensor.h"
#include "..\MockTestFakeItProject\src\extend.h"

int main()
{
	Mock<waterSensor> mock;
	When(Method(mock, analogicRead)).Return(3.5); // Method mock.foo will return 1 once.
	waterSensor& i = mock.get();
	//std::cout << i.analogicRead();

	Mock<waterSensor> mock2;
	When(Method(mock, getMaxValue)).Return(5.00); // Method mock.foo will return 1 once.
	waterSensor& i2 = mock.get();
    std::cout << i2.getMaxValue();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

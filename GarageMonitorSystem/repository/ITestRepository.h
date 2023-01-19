#pragma once
class ITestRepository
{
public:
	virtual ~ITestRepository() {};
	virtual bool testMethode() = 0;
};


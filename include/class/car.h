#pragma once

#include <iostream>
#include <string>

#include "console.h"
#include "taskManager.h"

using namespace std;

class Car
{
protected:
	string brand;
	unsigned int cylinders;
	unsigned int power;

public:
	Car(string brand, unsigned int cylinders, unsigned int power);
	virtual ~Car();

	string getBrand() const;
	unsigned int getCylinders() const;
	unsigned int getPower() const;

	void setBrand(string brand);
	void setCylinders(unsigned int cylinders);
	void setPower(unsigned int power);

	virtual void printInfo() const;
};
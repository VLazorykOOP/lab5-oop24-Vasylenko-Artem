#pragma once

#include <iostream>

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
	~Car();

	string getBrand();
	unsigned int getCylinders();
	unsigned int getPower();

	void setBrand(string brand);
	void setCylinders(unsigned int cylinders);
	void setPower(unsigned int power);

	void printInfo();
};

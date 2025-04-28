#pragma once

#include <iostream>
#include "class/car.h"

using namespace std;

class Lorry : public Car
{
private:
	unsigned int loadCapacity;

public:
	Lorry(string brand, unsigned int cylinders, unsigned int power, unsigned int loadCapacity);
	~Lorry();

	unsigned int getLoadCapacity() const;
	void setLoadCapacity(unsigned int loadCapacity);

	void setBrand(string brand);

	void printInfo() const override;
};

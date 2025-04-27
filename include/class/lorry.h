#pragma once

#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "class/car.h"

using namespace std;

class Lorry : public Car
{
private:
	int loadCapacity;

public:
	Lorry(string brand, unsigned int cylinders, unsigned int power);
	~Lorry();
};
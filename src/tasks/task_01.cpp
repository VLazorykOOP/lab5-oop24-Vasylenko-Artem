#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "class/car.h"
#include "class/lorry.h"

using namespace std;

void task_01()
{
	Car car("Audi", 4, 200);
	car.setBrand("Toyota");
	car.printInfo();

	Lorry lorry("Mercedes", 6, 300);
	lorry.setBrand("Honda");
	lorry.printInfo();
}

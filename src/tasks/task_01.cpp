#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "class/car.h"
#include "class/lorry.h"

using namespace std;

void task_01()
{
	Car car("Toyota", 4, 150);
	car.printInfo();

	cout << "------------------" << endl;

	Lorry lorry("Volvo", 6, 400, 12000);
	lorry.printInfo();

	lorry.setBrand("Scania");
	lorry.setLoadCapacity(15000);

	cout << "\nAfter modifications:" << endl;
	lorry.printInfo();
}

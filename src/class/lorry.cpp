#include "class/lorry.h"

Lorry::Lorry(string brand, unsigned int cylinders, unsigned int power, unsigned int loadCapacity)
	: Car(brand, cylinders, power), loadCapacity(loadCapacity) {}

Lorry::~Lorry() {}

unsigned int Lorry::getLoadCapacity() const { return loadCapacity; }

void Lorry::setLoadCapacity(unsigned int loadCapacity) { this->loadCapacity = loadCapacity; }

void Lorry::setBrand(string brand) { this->brand = brand; }

void Lorry::printInfo() const
{
	Car::printInfo();
	cout << "Load Capacity: " << loadCapacity << " kg" << endl;
}

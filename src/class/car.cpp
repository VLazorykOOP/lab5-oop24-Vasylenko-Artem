#include "class/car.h"

Car::Car(string brand, unsigned int cylinders, unsigned int power) : brand(brand), cylinders(cylinders), power(power) {}

Car::~Car() {}

string Car::getBrand() { return brand; }
unsigned int Car::getCylinders() { return cylinders; }
unsigned int Car::getPower() { return power; }
void Car::setBrand(string brand) { this->brand = brand; }
void Car::setCylinders(unsigned int cylinders) { this->cylinders = cylinders; }
void Car::setPower(unsigned int power) { this->power = power; }

void Car::printInfo()
{
	cout << "Brand: " << brand << endl;
	cout << "Cylinders: " << cylinders << endl;
	cout << "Power: " << power << endl;
}
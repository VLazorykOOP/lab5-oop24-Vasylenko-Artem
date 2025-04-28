#include "class/person.h"

Person::Person() : name("Unknown"), age(0) {}

Person::Person(const string &name, int age) : name(name), age(age) {}

Person::Person(const Person &other) : name(other.name), age(other.age) {}

Person::~Person() {}

Person &Person::operator=(const Person &other)
{
	if (this != &other)
	{
		name = other.name;
		age = other.age;
	}
	return *this;
}

void Person::print(ostream &os) const
{
	os << "Name: " << name << ", Age: " << age;
}

void Person::read(istream &is)
{
	cout << "Enter name: ";
	is >> name;
	cout << "Enter age: ";
	is >> age;
}

ostream &operator<<(ostream &os, const Person &person)
{
	person.print(os);
	return os;
}

istream &operator>>(istream &is, Person &person)
{
	person.read(is);
	return is;
}

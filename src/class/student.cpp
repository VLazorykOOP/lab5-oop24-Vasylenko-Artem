#include "class/student.h"

Student::Student() : Person(), university("Unknown"), course(1) {}

Student::Student(const string &name, int age, const string &university, int course)
	: Person(name, age), university(university), course(course) {}

Student::Student(const Student &other)
	: Person(other), university(other.university), course(other.course) {}

Student::~Student() {}

Student &Student::operator=(const Student &other)
{
	if (this != &other)
	{
		Person::operator=(other);
		university = other.university;
		course = other.course;
	}
	return *this;
}

void Student::print(ostream &os) const
{
	Person::print(os);
	os << ", University: " << university << ", Course: " << course;
}

void Student::read(istream &is)
{
	Person::read(is);
	cout << "Enter university: ";
	is >> university;
	cout << "Enter course: ";
	is >> course;
}

ostream &operator<<(ostream &os, const Student &student)
{
	student.print(os);
	return os;
}

istream &operator>>(istream &is, Student &student)
{
	student.read(is);
	return is;
}

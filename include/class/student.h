#pragma once

#include "class/person.h"

class Student : public Person
{
private:
	string university;
	int course;

public:
	Student();
	Student(const string &name, int age, const string &university, int course);
	Student(const Student &other);
	~Student();

	Student &operator=(const Student &other);

	void print(ostream &os) const override;
	void read(istream &is) override;

	friend ostream &operator<<(ostream &os, const Student &student);
	friend istream &operator>>(istream &is, Student &student);
};

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string name;
	int age;

public:
	Person();
	Person(const string &name, int age);
	Person(const Person &other);
	virtual ~Person();

	Person &operator=(const Person &other);

	virtual void print(ostream &os) const;
	virtual void read(istream &is);

	friend ostream &operator<<(ostream &os, const Person &person);
	friend istream &operator>>(istream &is, Person &person);
};

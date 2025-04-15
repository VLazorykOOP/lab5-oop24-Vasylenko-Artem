#pragma once

#include <iostream>

#include "console.h"
#include "taskManager.h"

using namespace std;

typedef struct
{
	int codeError;
	string message;
} VectorError;

class VectorBase
{
protected:
	static int countObject;

public:
	static int getCountObject();
};

template <typename T>
class Vector : public VectorBase
{
private:
	T *data;
	size_t size;
	size_t capacity;
	int codeError;

public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, T value);

	Vector(const Vector &other);

	~Vector();

	Vector &operator++();
	Vector operator++(int);
	Vector &operator--();
	Vector operator--(int);

	bool operator!() const;

	Vector operator~();

	Vector &operator-();

	Vector &operator=(const Vector &other);

	Vector operator+=(const Vector &other);
	Vector operator-=(const Vector &other);
	Vector operator*=(const int &other);
	Vector operator/=(const int &other);
	Vector operator%=(const int &other);
	Vector operator|=(const Vector &other);
	Vector operator^=(const Vector &other);
	Vector operator&=(const Vector &other);

	Vector operator+(const Vector &other);
	Vector operator-(const Vector &other);
	Vector operator*(const int &other);
	Vector operator/(const int &other);
	Vector operator%(const int &other);

	Vector operator|(const Vector &other);
	Vector operator^(const Vector &other);
	Vector operator&(const Vector &other);

	Vector &operator<<(const int &other);
	Vector &operator>>(const int &other);

	template <typename U>
	friend ostream &operator<<(ostream &os, const Vector<U> &v);

	template <typename U>
	friend istream &operator>>(istream &is, Vector<U> &v);

	bool operator==(const Vector &other) const;
	bool operator!=(const Vector &other) const;

	T &operator[](size_t index);
	const T &operator[](size_t index) const;

	static void *operator new[](size_t size);
	static void operator delete[](void *ptr);

	bool operator>(const Vector &other) const;
	bool operator>=(const Vector &other) const;
	bool operator<(const Vector &other) const;
	bool operator<=(const Vector &other) const;

	void empty();
	size_t getSize() const;
	static int getCountObject();
	void push_back(T value);
	void print() const;
};

#include "vector.tpp"
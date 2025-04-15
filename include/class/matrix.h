#pragma once

#include "vector.h"

using namespace std;

class MatrixBase
{
protected:
	static int totalCount;

public:
	static int getTotalCount();
};

template <typename T>
class Matrix : public MatrixBase
{
private:
	Vector<T> *data;
	size_t rows;
	size_t columns;
	static int codeError;

public:
	Matrix();
	Matrix(size_t size); // E
	Matrix(size_t rows, size_t columns);
	Matrix(size_t rows, size_t columns, T value);

	Matrix(const Matrix &other);

	~Matrix();

	Matrix &operator++();
	Matrix operator++(int);
	Matrix &operator--();
	Matrix operator--(int);

	bool operator!() const;

	Matrix operator~();
	Matrix &operator-();
	Matrix &operator=(const Matrix &other);

	Matrix operator+(const Matrix &other);
	Matrix operator+(const T &other);
	Matrix operator-(const Matrix &other);
	Matrix operator-(const T &other);
	Matrix operator*(const Matrix &other);
	Matrix operator*(const T &other);
	Matrix operator/(const Matrix &other);
	Matrix operator/(const T &other);
	Matrix operator%(const Matrix &other);
	Matrix operator%(const T &other);
	Matrix operator|(const Matrix &other);
	Matrix operator|(const T &other);
	Matrix operator^(const Matrix &other);
	Matrix operator^(const T &other);
	Matrix operator&(const Matrix &other);
	Matrix operator&(const T &other);

	Matrix operator+=(const Matrix &other);
	Matrix operator+=(const T &other);
	Matrix operator-=(const Matrix &other);
	Matrix operator-=(const T &other);
	Matrix operator*=(const Matrix &other);
	Matrix operator*=(const T &other);
	Matrix operator*=(const Vector<T> &other);
	Matrix operator/=(const Matrix &other);
	Matrix operator/=(const T &other);
	Matrix operator%=(const Matrix &other);
	Matrix operator%=(const T &other);
	Matrix operator|=(const Matrix &other);
	Matrix operator|=(const T &other);
	Matrix operator^=(const Matrix &other);
	Matrix operator^=(const T &other);
	Matrix operator&=(const Matrix &other);
	Matrix operator&=(const T &other);

	bool operator==(const Matrix &other) const;
	bool operator!=(const Matrix &other) const;

	bool operator>=(const Matrix &other) const;
	bool operator<=(const Matrix &other) const;
	bool operator>(const Matrix &other) const;
	bool operator<(const Matrix &other) const;

	Vector<T> &operator[](size_t index);
	const Vector<T> &operator[](size_t index) const;

	T &operator()(size_t row, size_t column);
	const T &operator()(size_t row, size_t column) const;

	template <typename K>
	friend ostream &operator<<(ostream &out, const Matrix<K> &matrix);

	template <typename K>
	friend istream &operator>>(istream &in, Matrix<K> &matrix);

	void print() const;
};

#include "matrix.tpp"
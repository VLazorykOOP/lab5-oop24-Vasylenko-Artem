#include "class/matrix.h"

template <typename T>
Matrix<T>::Matrix() : rows(0), columns(0), data(nullptr) { totalCount++; }

template <typename T>
Matrix<T>::Matrix(size_t size) : rows(size), columns(size)
{
	data = new Vector<T>[size];
	for (size_t i = 0; i < size; i++)
		data[i] = Vector<T>(size);

	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			i == j ? data[i][j] = 1 : data[i][j] = 0;

	totalCount++;
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns) : rows(rows), columns(columns)
{
	data = new Vector<T>[rows];
	totalCount++;
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns, T value) : rows(rows), columns(columns)
{
	data = new Vector<T>[rows];
	for (size_t i = 0; i < rows; i++)
		data[i] = Vector<T>(columns, value);
	totalCount++;
}

template <typename T>
Matrix<T>::Matrix(const Matrix &other) : rows(other.rows), columns(other.columns)
{
	data = new Vector<T>[rows];
	for (size_t i = 0; i < rows; i++)
		data[i] = other.data[i];
	totalCount++;
}

int MatrixBase::totalCount = 0;

template <typename T>
Matrix<T>::~Matrix()
{
	delete[] data;
	totalCount--;
}

template <typename T>
Matrix<T> &Matrix<T>::operator++()
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j]++;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator++(int)
{
	Matrix temp(*this);
	++*this;
	return temp;
}

template <typename T>
Matrix<T> &Matrix<T>::operator--()
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j]--;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator--(int)
{
	Matrix temp(*this);
	--*this;
	return temp;
}

template <typename T>
bool Matrix<T>::operator!() const
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			if (data[i][j] != 0)
				return true;
	return false;
}

template <typename T>
Matrix<T> Matrix<T>::operator~()
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] = ~data[i][j];
	return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-()
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] = -data[i][j];
	return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &other)
{
	if (this != &other)
	{
		delete[] data;
		rows = other.rows;
		columns = other.columns;
		data = new Vector<T>[rows];
		for (size_t i = 0; i < rows; i++)
			data[i] = other.data[i];
	}
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &other)
{
	if (rows != other.rows || columns != other.columns)
		return Matrix<T>();
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
		{
			temp.data[i][j] = data[i][j] + other.data[i][j];
			cout << temp.data[i][j] << " " << data[i][j] << " " << other.data[i][j] << endl;
		}
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T &other)
{
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] + other;
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &other)
{
	if (rows != other.rows || columns != other.columns)
		return Matrix<T>();
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] - other.data[i][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const T &other)
{
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] - other;
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] * other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &other)
{
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] * other;
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] / other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &other)
{
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] / other;
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator%(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] % other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator%(const T &other)
{
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] % other;
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator^(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] ^ other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator^(const T &other)
{
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] ^ other;
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator|(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] | other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator|(const T &other)
{
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] | other;
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator&(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] & other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator&(const T &other)
{
	Matrix<T> temp(rows, columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][j] = data[i][j] & other;
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix &other)
{
	if (rows != other.rows || columns != other.columns)
		return Matrix<T>();
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] += other.data[i][j];
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+=(const T &other)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] += other;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-=(const Matrix &other)
{
	if (rows != other.rows || columns != other.columns)
		return Matrix<T>();
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] -= other.data[i][j];
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-=(const T &other)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] -= other;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const T &other)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] *= other;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] * other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const Vector<T> &other)
{
	if (columns != other.size)
		return Matrix<T>();
	Matrix<T> temp(rows, 1);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			temp.data[i][0] += data[i][j] * other.data[j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator/=(const T &other)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] /= other;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/=(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] / other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator^=(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] ^ other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator^=(const T &other)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] ^= other;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator%=(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] % other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator%=(const T &other)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] %= other;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator&=(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] & other.data[k][j];
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator&=(const T &other)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] &= other;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator|=(const T &other)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j] |= other;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator|=(const Matrix &other)
{
	if (columns != other.rows)
		return Matrix<T>();
	Matrix<T> temp(rows, other.columns);
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < other.columns; j++)
			for (size_t k = 0; k < columns; k++)
				temp.data[i][j] += data[i][k] | other.data[k][j];
	return temp;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix &other) const
{
	if (rows != other.rows || columns != other.columns)
		return false;
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			if (data[i][j] != other.data[i][j])
				return false;
	return true;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix &other) const { return !(*this == other); }

template <typename T>
bool Matrix<T>::operator<(const Matrix &other) const
{
	if (rows != other.rows || columns != other.columns)
		return false;
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			if (data[i][j] < other.data[i][j])
				return true;
	return false;
}

template <typename T>
bool Matrix<T>::operator>(const Matrix &other) const { return other < *this; }

template <typename T>
bool Matrix<T>::operator<=(const Matrix &other) const { return !(*this > other); }

template <typename T>
bool Matrix<T>::operator>=(const Matrix &other) const { return !(*this < other); }

template <typename T>
T &Matrix<T>::operator()(size_t row, size_t column) { return data[row][column]; }

template <typename T>
Vector<T> &Matrix<T>::operator[](size_t index) { return data[index]; }

template <typename T>
const Vector<T> &Matrix<T>::operator[](size_t index) const { return data[index]; }

template <typename T>
const T &Matrix<T>::operator()(size_t row, size_t column) const { return data[row][column]; }

template <typename K>
ostream &operator<<(ostream &out, const Matrix<K> &matrix)
{
	for (size_t i = 0; i < matrix.rows; i++)
	{
		for (size_t j = 0; j < matrix.columns; j++)
			out << matrix.data[i][j] << " ";
		out << endl;
	}
	return out;
}

template <typename T>
istream &operator>>(istream &in, Matrix<T> &matrix)
{
	for (size_t i = 0; i < matrix.rows; i++)
		for (size_t j = 0; j < matrix.columns; j++)
			in >> matrix.data[i][j];
	return in;
}

int MatrixBase::getTotalCount() { return totalCount; }

template <typename T>
void Matrix<T>::print() const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}
}
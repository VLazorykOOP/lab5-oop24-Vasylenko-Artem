#include "class/vector.h"

using namespace std;

template <typename T>
Vector<T>::Vector() : size(1), capacity(1)
{
	data = new T[capacity];
	countObject++;
}

template <typename T>
Vector<T>::Vector(size_t n) : size(n), capacity(n)
{
	data = new T[capacity];
	countObject++;
}

template <typename T>
Vector<T>::Vector(size_t n, T value) : size(n), capacity(n)
{
	data = new T[capacity];
	for (size_t i = 0; i < n; i++)
		data[i] = value;
	countObject++;
}

template <typename T>
Vector<T>::Vector(const Vector &other) : size(other.size), capacity(other.capacity)
{
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
		data[i] = other.data[i];

	countObject++;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;

	countObject--;
}

template <typename T>
Vector<T> &Vector<T>::operator++()
{
	for (size_t i = 0; i < size; i++)
		++data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator++(int)
{
	Vector temp(*this);
	++(*this);
	return temp;
}

template <typename T>
Vector<T> &Vector<T>::operator--()
{
	for (size_t i = 0; i < size; ++i)
		--data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator--(int)
{
	Vector temp(*this);
	--(*this);
	return temp;
}

template <typename T>
bool Vector<T>::operator!() const
{
	if (size == 0)
		return true;

	for (size_t i = 0; i < size; i++)
		if (data[i] != 0)
			return false;

	return true;
}

template <typename T>
Vector<T> Vector<T>::operator~()
{
	for (size_t i = 0; i < size; i++)
		data[i] = ~data[i];
	return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator-()
{
	for (size_t i = 0; i < size; i++)
		data[i] = -data[i];
	return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other)
{
	if (this != &other)
	{
		delete[] data;
		size = other.size;
		capacity = other.capacity;
		data = new (nothrow) T[size];
		if (!data)
		{
			codeError = 2;
			return *this;
		}
		for (size_t i = 0; i < size; i++)
			data[i] = other.data[i];
	}
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] += other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator-=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] -= other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator*=(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] *= other;
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator/=(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] /= other;
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator%=(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] %= other;
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator|=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] |= other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator^=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] ^= other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator&=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] &= other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] + other.data[i];
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] - other.data[i];
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator*(const int &other)
{
	Vector temp(size);
	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] * other;
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator/(const int &other)
{
	Vector temp(size);
	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] / other;
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator%(const int &other)
{
	Vector temp(size);
	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] % other;
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator|(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] | other.data[i];
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator^(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] ^ other.data[i];
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator&(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] & other.data[i];
	return temp;
}

template <typename T>
Vector<T> &Vector<T>::operator<<(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] <<= other;
	return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator>>(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] >>= other;
	return *this;
}

template <typename U>
ostream &operator<<(ostream &os, const Vector<U> &v)
{
	for (size_t i = 0; i < v.size; i++)
		os << v.data[i] << " ";
	return os;
}

template <typename U>
istream &operator>>(istream &is, Vector<U> &v)
{
	for (size_t i = 0; i < v.size; i++)
		is >> v.data[i];
	return is;
}

template <typename T>
bool Vector<T>::operator==(const Vector &other) const
{
	if (size != other.size)
		return false;
	for (size_t i = 0; i < size; i++)
		if (data[i] != other.data[i])
			return false;
	return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector &other) const { return !(*this == other); }

template <typename T>
T &Vector<T>::operator[](size_t index) { return data[index]; }

template <typename T>
const T &Vector<T>::operator[](size_t index) const { return data[index]; }

template <typename T>
void *Vector<T>::operator new[](size_t size) { return ::operator new[](size); }

template <typename T>
void Vector<T>::operator delete[](void *ptr) { ::operator delete[](ptr); }

template <typename T>
bool Vector<T>::operator<(const Vector &other) const
{
	size_t minSize = min(size, other.size);
	for (size_t i = 0; i < minSize; ++i)
	{
		if (data[i] < other.data[i])
			return true;
		if (data[i] > other.data[i])
			return false;
	}
	return size < other.size;
}

template <typename T>
bool Vector<T>::operator>(const Vector &other) const { return other < *this; }

template <typename T>
bool Vector<T>::operator<=(const Vector &other) const { return !(*this > other); }

template <typename T>
bool Vector<T>::operator>=(const Vector &other) const { return !(*this < other); }

template <typename T>
size_t Vector<T>::getSize() const { return size; }

template <typename T>
void Vector<T>::empty()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

template <typename T>
void Vector<T>::push_back(T value)
{
	if (size >= capacity)
	{
		size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
		T *newData = new (nothrow) T[newCapacity];
		if (!newData)
		{
			codeError = 2;
			return;
		}
		for (size_t i = 0; i < size; ++i)
			newData[i] = data[i];
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

	data[size++] = value;
}

template <typename T>
void Vector<T>::print() const
{
	for (size_t i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

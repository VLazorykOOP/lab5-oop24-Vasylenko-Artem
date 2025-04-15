#pragma once

#include "vector.h"

using namespace std;

template <typename T, typename U>
class Map
{
private:
	Vector<T> keys;
	Vector<U> values;
	size_t size;
	int codeError;

public:
	Map();
	~Map();

	U &operator[](size_t index);
	const U &operator[](size_t index) const;

	void push_back(T key, U value);

	template <typename K, typename M>
	friend ostream &operator<<(ostream &os, const Map<K, M> &map);

	template <typename K, typename M>
	friend istream &operator>>(istream &is, Map<K, M> &map);

	void print();
};

#include "map.tpp"
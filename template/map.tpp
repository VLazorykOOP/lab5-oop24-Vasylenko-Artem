#include "class/map.h"

using namespace std;

template <class T, class U>
Map<T, U>::Map() : size(0)
{
	keys = Vector<T>(size);
	values = Vector<U>(size);
}

template <class T, class U>
Map<T, U>::~Map() {}

template <class T, class U>
U &Map<T, U>::operator[](size_t pos) { return values[pos]; }

template <class T, class U>
void Map<T, U>::push_back(T key, U value)
{
	keys.push_back(key);
	values.push_back(value);
	size++;
}

template <class T, class U>
void Map<T, U>::print()
{
	for (size_t i = 0; i < keys.getSize(); i++)
		cout << "Key: " << keys[i] << " - Value: " << values[i] << endl;
}

template <typename K, typename M>
ostream &operator<<(ostream &os, const Map<K, M> &map)
{
	for (size_t i = 0; i < map.size; i++)
		os << map.keys[i] << ' ' << map.values[i] << endl;
	return os;
}

template <typename K, typename M>
istream &operator>>(istream &is, Map<K, M> &map)
{
	size_t newSize;
	is >> newSize;
	K key;
	M value;

	for (size_t i = 0; i < newSize; ++i)
	{
		is >> key >> value;
		map.push_back(key, value);
	}
	return is;
}

#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "class/map.h"
#include <vector>

// Побудувати асоційований клас збереження
// двох сутностей.В завданні створити клас,
// який представляє собою асоціативний
// масив між двома сутностями.Написати функцію створення набору
// асоціативних сутностей.Перевантажити операцію індексації[] – функцію,
// яка звертається до об’єкта класу,
// за однією сутністю, якщо індекс, повертає асоціативну сутність, якщо відповідної сутності немає в встановлює код помилки у змінну CodeError, альтернативні звернення через перевантаження операції виклику функції();
// перевантажити дружні операції введення та
// виведення.
// Задача 2.1. Цілих чисел від 1 до 100 та цілі прописом.Наприклад, 1 та один, 10 та десять.

using namespace std;

void task_02()
{
	static const vector<string> ones = {
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"};

	static const vector<string> teens = {
		"ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	static const vector<string> tens = {
		"twenty", "thirty", "forty", "fifty",
		"sixty", "seventy", "eighty", "ninety"};

	Map<int, string> map;

	for (int i = 0; i <= 100; i++)
	{
		string str;

		if (i < 10)
		{
			str = ones[i];
		}
		else if (i >= 10 && i < 20)
		{
			str = teens[i - 10];
		}
		else if (i < 100)
		{
			str = tens[i / 10 - 2];
			if (i % 10 != 0)
				str += "-" + ones[i % 10];
		}
		else if (i == 100)
		{
			str = "one hundred";
		}

		map.push_back(i, str);
	}

	map.print();

	newLine();

	cout << "cout << map: " << map << endl;
	cout << "cout << map: " << map[0] << endl;

	newLine();

	int index;
	cout << "\nEnter index: ";
	cin >> index;
	cout << "Value: " << map[index] << endl;
}

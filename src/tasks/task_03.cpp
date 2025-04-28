#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "class/student.h"

using namespace std;

void task_03()
{
	Student s1;
	cout << "Enter student info:\n";
	cin >> s1;

	cout << "\nStudent info:\n";
	cout << s1 << endl;

	Student s2 = s1;

	cout << "\nCopied student info:\n";
	cout << s2 << endl;

	Student s3;
	s3 = s1;

	cout << "\nAssigned student info:\n";
	cout << s3 << endl;
}

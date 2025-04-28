#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "class/window.h"

#include <vector>
using namespace std;

void task_02()
{
	MenuWindow menuWin(100, 200, 300, 150, "Main Menu");

	menuWin.print();
}

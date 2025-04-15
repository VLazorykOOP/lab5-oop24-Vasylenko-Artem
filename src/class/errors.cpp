#include "class/vector.h"

VectorError vectorError[4] = {
	{0, "No error"},
	{1, "Vector sizes are not equal"},
	{2, "Not enough memory"},
	{3, "Unknown error"}};

int VectorBase::countObject = 0;
int VectorBase::getCountObject() { return countObject; }
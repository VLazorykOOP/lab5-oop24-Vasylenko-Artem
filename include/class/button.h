#pragma once

#include <iostream>
using namespace std;

class Button
{
private:
	int width;
	int height;

public:
	Button();
	Button(int width, int height);
	~Button();

	int getWidth() const;
	int getHeight() const;

	void setWidth(int width);
	void setHeight(int height);

	void print() const;
};

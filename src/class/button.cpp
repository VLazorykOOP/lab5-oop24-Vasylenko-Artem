#include "class/button.h"

Button::Button() : width(0), height(0) {}

Button::Button(int width, int height) : width(width), height(height) {}

Button::~Button() {}

int Button::getWidth() const { return width; }
int Button::getHeight() const { return height; }

void Button::setWidth(int width) { this->width = width; }
void Button::setHeight(int height) { this->height = height; }

void Button::print() const
{
	cout << "Button size: " << width << " x " << height << endl;
}

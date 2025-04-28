#include "class/window.h"
#include <iostream>

using namespace std;

Window::Window() : x(0), y(0), button() {}

Window::Window(int x, int y, int buttonWidth, int buttonHeight)
	: x(x), y(y), button(buttonWidth, buttonHeight) {}

Window::~Window() {}

int Window::getX() const { return x; }
int Window::getY() const { return y; }

void Window::setX(int x) { this->x = x; }
void Window::setY(int y) { this->y = y; }

void Window::print() const
{
	cout << "Window position: (" << x << ", " << y << ")" << endl;
	button.print();
}

#include <cstring> // Для strcpy, strlen
#include <iostream>

using namespace std;

MenuWindow::MenuWindow() : Window(), menuName(nullptr) {}

MenuWindow::MenuWindow(int x, int y, int buttonWidth, int buttonHeight, const char *menuName)
	: Window(x, y, buttonWidth, buttonHeight)
{
	if (menuName)
	{
		this->menuName = new char[strlen(menuName) + 1];
		strcpy(this->menuName, menuName);
	}
	else
	{
		this->menuName = nullptr;
	}
}

MenuWindow::~MenuWindow()
{
	delete[] menuName;
}

void MenuWindow::print() const
{
	Window::print();
	if (menuName)
		cout << "Menu Name: " << menuName << endl;
	else
		cout << "Menu Name: (none)" << endl;
}

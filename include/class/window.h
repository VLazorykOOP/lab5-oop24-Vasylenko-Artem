#pragma once

#include "class/button.h"

class Window
{
protected:
	int x;
	int y;
	Button button;

public:
	Window();
	Window(int x, int y, int buttonWidth, int buttonHeight);
	virtual ~Window();

	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	virtual void print() const;
};

class MenuWindow : public Window
{
private:
	char *menuName;

public:
	MenuWindow();
	MenuWindow(int x, int y, int buttonWidth, int buttonHeight, const char *menuName);
	~MenuWindow();

	void print() const override;
};

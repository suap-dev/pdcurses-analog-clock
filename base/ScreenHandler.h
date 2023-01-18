#pragma once
#include <curses.h>
#include <iostream>
#include "Entity.h"

class ScreenHandler
{
private:
	WINDOW* m_curses_window;
	void noWindowMessage();

public:
	ScreenHandler();
	~ScreenHandler();
	void init();
	void mvprint(double x, double y, const char* text);
	void mvprint(double x, double y, const int num);
	void mvprint(int x, int y, const char* text);
	void mvprint(int x, int y, const int num);

	void refresh();

	void draw(Entity& ent);
	void erase(Entity& ent);
	void log(Entity& ent);

	int maxX() const;
	int maxY() const;

	mnowacki::Vector center() const;
};


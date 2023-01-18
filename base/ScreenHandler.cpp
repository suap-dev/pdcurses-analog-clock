#include "ScreenHandler.h"

ScreenHandler::~ScreenHandler()
{
	if (m_curses_window == nullptr)
		noWindowMessage();
	else {
		endwin();
	}
}

void ScreenHandler::noWindowMessage()
{
	std::cout << "WARNING: Curses window not initialised." << std::endl;
}

ScreenHandler::ScreenHandler():
	m_curses_window(nullptr)
{}

void ScreenHandler::init()
{
	m_curses_window = initscr();
	/*	In cbreak mode, characters typed by the user are made available immediately,
		and erase/kill character processing is not performed. */
	//cbreak();
	halfdelay(1);

	/*	echo() and noecho()
		control whether typed characters are echoed by the input routine. */
	noecho();

	/*	leaveok() allows the cursor to be left wherever the update happens to leave it.
		It's useful for applications where the cursor is not used, since it reduces
		the need for cursor motions. If possible, the cursor is made invisible when
		this option is enabled. */
	leaveok(m_curses_window, true);

	/* Resizes Windows terminal */
	resize_term(60, 200);
}

void ScreenHandler::mvprint(double x, double y, const char* text)
{

	mvprint(int(round(x)), int(round(y)), text);
}

void ScreenHandler::mvprint(double x, double y, const int num)
{
	mvprint(int(round(x)), int(round(y)), num);
}

void ScreenHandler::mvprint(int x, int y, const char* text)
{
	if (m_curses_window == nullptr) {
		noWindowMessage();
	}
	else {
		mvprintw(y, x * 2, text);
	}
}

void ScreenHandler::mvprint(int x, int y, const int num)
{
	if (m_curses_window == nullptr) {
		noWindowMessage();
	}
	else {
		mvprintw(y, x * 2, "%d", num);
	}

}

void ScreenHandler::refresh()
{
	if (m_curses_window)
		wrefresh(m_curses_window);
	else
		noWindowMessage();
}

void ScreenHandler::draw(Entity& ent)
{
	if (m_curses_window) {
		if(ent.visible)
			for (const auto& v : ent.vList) {
				mvprint(ent.anchor.getX() + v.getX(), ent.anchor.getY() + v.getY(), "[]");
			}
	}
	else {
		noWindowMessage();
	}
}

void ScreenHandler::erase(Entity& ent)
{
	if (m_curses_window) {
		if (ent.visible)
			for (const auto& v : ent.vList) {
				mvprint(ent.anchor.getX() + v.getX(), ent.anchor.getY() + v.getY(), "  ");
			}
	}
	else {
		noWindowMessage();
	}

}

void ScreenHandler::log(Entity& ent)
{
	
	int i = 0;
	for (auto& v : ent.vList) {
		mvprint(0, i, v.toString().data());
		i++;
	}
}

int ScreenHandler::maxX() const
{
	if (m_curses_window) {
		return getmaxx(m_curses_window) / 2;
	}
	else {
		return -1;
	}
}

int ScreenHandler::maxY() const
{
	if (m_curses_window) return getmaxy(m_curses_window);
	else return -1;
}

mnowacki::Vector ScreenHandler::center() const
{
	const int maxX = getmaxx(m_curses_window);
	const int maxY = getmaxy(m_curses_window);

	const int centerX = maxX / 4;
	const int centerY = maxY / 2;

	return mnowacki::Vector(centerX, centerY);
}

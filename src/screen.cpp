#include "screen.h"

#include <ncurses.h>

/************************************ SCREEN ************************************/

Screen::Screen()
{
  initscr();
}

Screen::~Screen()
{
  endwin();
}

void Screen::print(const char* text)
{
  printw(text);
  refresh();
  getch();
}

#include "screen.h"

#include <ncurses.h>

/************************************ SCREEN ************************************/

Screen::Screen()
{
  initscr();             //start the stdscrn
  cbreak();              //disable input line buffering (we dont want to have to hit enter to get input)
  noecho();              //dont echo typed chars to the screen
  keypad(stdscr, TRUE);  //lets us read special keys (funct, arrow ...)
  curs_set(0);           //dont print the cursor
}

Screen::~Screen()
{
  endwin();        //end the stdscrn
}

void Screen::print(const char* text)
{
  printw(text);
  refresh();
  getch();
}

#include "screen.h"

#include <ncurses.h>

namespace ncurses_game_eng
{

Screen::Screen()
{
  initscr();             //start the stdscrn
  cbreak();              //disable input line buffering (we dont want to have to hit enter to get input)
  noecho();              //dont echo typed chars to the screen
  keypad(stdscr, TRUE);  //lets us read special keys (funct, arrow ...)
  curs_set(0);           //dont print the cursor
  //make sure we are using m_input_mode's blocking mode
  nodelay(stdscr,m_input_mode == InputMode::NonBlocking);
}

Screen::~Screen()
{
  endwin();        //end the stdscrn
}

void Screen::clear_screen()
{
  clear();
  refresh();   //refresh the screen to actually print the changes
}

void Screen::print_str(const char* text)
{
  addstr(text);
  refresh();
}

void Screen::print_ch(int ch)
{
  addch(ch);
  refresh();
}

void Screen::set_input_mode(InputMode mode)
{
  m_input_mode = mode;
  nodelay(stdscr, m_input_mode == InputMode::NonBlocking);
}

int Screen::get_ch()
{
  return getch();
}

int Screen::get_ch(InputMode mode)
{
  nodelay(stdscr, mode == InputMode::NonBlocking);            //set input mode temperarily
  int ch = getch();
  nodelay(stdscr, m_input_mode == InputMode::NonBlocking);    //go back to class wide mode
  return ch;
}

} //end namespace ncurses_game_eng

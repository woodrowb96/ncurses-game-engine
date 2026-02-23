#include "screen.h"

#include <vector>
#include <ncurses.h>

namespace ncurses_game_eng
{

//PUBLIC

Screen::Screen()
{
  initscr();             //start the stdscrn
  cbreak();              //disable input line buffering (we dont want to have to hit enter to get input)
  noecho();              //dont echo typed chars to the screen
  keypad(stdscr, TRUE);  //lets us read special keys (funct, arrow ...)
  curs_set(0);           //dont print the cursor
  set_blocking(DEFAULT_BLOCKING_MODE);
}

Screen::~Screen()
{
  endwin();        //end the stdscrn
}

void Screen::clear()
{
  ::clear();
  refresh();   //refresh the screen to actually print the changes
}

void Screen::print_str(const std::string& str)
{
  addstr(str.c_str());
  refresh();
}

void Screen::print_ch(int ch)
{
  addch(ch);
  refresh();
}

int Screen::get_ch(BlockingMode mode)
{
  set_blocking(mode);
  int ch = getch();
  set_blocking(DEFAULT_BLOCKING_MODE);
  return ch;
}

std::string Screen::get_str(int buffer_size)
{
  std::vector<char> buffer(buffer_size);

  set_blocking(BlockingMode::Blocking);     //make sure we are blocking
  getnstr(buffer.data(), buffer_size - 1);  //read the string into the buffer
  set_blocking(DEFAULT_BLOCKING_MODE);      //go back to default blocking mode

  return std::string(buffer.data());
}

int Screen::get_height() const
{
  [[maybe_unused]] int h {-1}, w {-1};
  getmaxyx(stdscr, h, w);
  return h;
}

int Screen::get_width() const
{
  [[maybe_unused]] int h {-1}, w {-1};
  getmaxyx(stdscr, h, w);
  return w;
}

Coord Screen::get_cursor_pos() const
{
  Coord pos {-1,-1};
  getyx(stdscr, pos.y, pos.x);
  return pos;
}

//PRIVATE

void Screen::set_blocking(BlockingMode mode)
{
  nodelay(stdscr, BlockingMode::NonBlocking == mode);
}

} //end namespace ncurses_game_eng

#include "screen.h"
#include "coord.h"

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
  for(Window* w : m_windows) {
    if(w) {
      delete w;
    }
  }
  endwin();        //end the stdscrn
}

//USER OUTPUT

void Screen::clear()
{
  ::clear();
}

void Screen::refresh()
{
  ::refresh();
}

void Screen::add_str(const std::string& str)
{
  addstr(str.c_str());
}

//USER INPUT

int Screen::get_ch(BlockingMode mode)
{
  set_blocking(mode);
  int ch = getch();
  set_blocking(DEFAULT_BLOCKING_MODE);
  return (ch == ERR) ? '\0' : ch;   //ncurses will return ERR if getch gets no input in NonBlocking mode
}

std::string Screen::get_str(int buffer_size)
{
  std::vector<char> buffer(buffer_size);

  set_blocking(BlockingMode::Blocking);     //make sure we are blocking
  getnstr(buffer.data(), buffer_size - 1);  //read the string into the buffer
  set_blocking(DEFAULT_BLOCKING_MODE);      //go back to default blocking mode

  return std::string(buffer.data());
}

//SCREEN ATTRIBUTE GETTERS

int Screen::get_height() const
{
  int h {-1};
  [[maybe_unused]] int w {-1};
  getmaxyx(stdscr, h, w);
  return h;
}

int Screen::get_width() const
{
  [[maybe_unused]] int h {-1};
  int w {-1};
  getmaxyx(stdscr, h, w);
  return w;
}

//MANAGE WINDOWS

Window* Screen::create_window(int width, int height, Coord pos)
{
  Window* win = new Window(width, height, pos);
  m_windows.push_back(win);
  return win;
}

//SYSTEM UTILS

void Screen::sleep(int ms)
{
  napms(ms);
}

//PRIVATE

void Screen::set_blocking(BlockingMode mode)
{
  nodelay(stdscr, BlockingMode::NonBlocking == mode);
}

} //end namespace ncurses_game_eng

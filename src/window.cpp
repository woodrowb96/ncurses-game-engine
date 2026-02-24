#include "window.h"
#include "coord.h"

#include <ncurses.h>

namespace cursen
{
//PUBLIC
//WINDOW ATTRIBUTE GETTERS

int Window::height() const { return height_; }

int Window::width() const { return width_; }

Coord Window::pos() const {return pos_; }

Coord Window::cursor_pos() const
{
  Coord pos {-1,-1};
  getyx(win_, pos.y, pos.x);
  return pos;
}

//USER OUTPUT

void Window::clear()
{
  wclear(win_);
}

void Window::refresh()
{
  wrefresh(win_);
}

void Window::move_cursor(const Coord& pos)
{
  wmove(win_, pos.y, pos.x);
}

void Window::add_ch(int ch)
{
  waddch(win_, ch);
}

void Window::add_str(const std::string& str)
{
  waddstr(win_, str.c_str());
}

//PRIVATE

Window::Window(int width, int height, Coord pos)
  :
  win_(newwin(height,width,pos.y, pos.x)),   //create the window with ncurses
  width_(width),
  height_(height),
  pos_(pos)
{}

Window::~Window()
{
  if(win_) {
    delwin(win_);   //destroy the window through ncurses
  }
}

} //end namespace

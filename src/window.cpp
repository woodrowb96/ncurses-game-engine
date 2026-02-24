#include "window.h"
#include "coord.h"

#include <ncurses.h>

namespace ncurses_game_eng
{
//PUBLIC
//WINDOW ATTRIBUTE GETTERS

int Window::get_height() const { return m_height; }

int Window::get_width() const { return m_width; }

Coord Window::get_pos() const {return m_pos; }

Coord Window::get_cursor_pos() const
{
  Coord pos {-1,-1};
  getyx(m_win, pos.y, pos.x);
  return pos;
}

//USER OUTPUT

void Window::clear()
{
  wclear(m_win);
}

void Window::refresh()
{
  wrefresh(m_win);
}

void Window::move_cursor(const Coord& pos)
{
  wmove(m_win, pos.y, pos.x);
}

void Window::add_ch(int ch)
{
  waddch(m_win, ch);
}

void Window::add_str(const std::string& str)
{
  waddstr(m_win, str.c_str());
}

//PRIVATE

Window::Window(int width, int height, Coord pos)
  :
  m_win(newwin(height,width,pos.y, pos.x)),   //create the window with ncurses
  m_width(width),
  m_height(height),
  m_pos(pos)
{}

Window::~Window()
{
  if(m_win) {
    delwin(m_win);   //destroy the window through ncurses
  }
}

} //end namespace

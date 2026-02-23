#include "window.h"
#include "coord.h"

#include <ncurses.h>

namespace ncurses_game_eng
{
//PUBLIC

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

} //endnamespace

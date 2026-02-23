#ifndef WINDOW_H
#define WINDOW_H

#include "coord.h"

#include <ncurses.h>

namespace ncurses_game_eng
{

/************************************ WINDOW ************************************/
// A wrapper around the ncurses window.
//
// Note:
//  - Constructor and destructor are private. We dont want users creating windows
//    directly. We want windows to be tied to the screen, so we use the screen class 
//    to create them. If a user needs a window they need to create one and get a handle
//    through the screen class.
/********************************************************************************/

class Window
{
  public:

  private:
    Window(int width, int height, Coord pos = {0,0});
    ~Window();

    //ncurses window ptr, dimension, and stdscr position
    WINDOW* m_win;
    int m_width;
    int m_height;
    Coord m_pos;
};

} //endnamespace

#endif

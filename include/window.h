#ifndef WINDOW_H
#define WINDOW_H

#include "coord.h"

#include <string>

//forward declare a WINDOW from ncurses
typedef struct _win_st WINDOW;

namespace ncurses_game_eng
{

/************************************ WINDOW ************************************/
// A wrapper around the ncurses window.
//
// The window class lets us:
//  - print output onto the window
//    -- move the cursor around the window
//    -- add strings and chars to the window
//    -- clear the window 
//    -- refresh the window to print adds and clears onto the screen
//
// Note:
//  - Constructor and destructor are private. We dont want users creating windows
//    directly. We want windows to be tied to the screen, so we use the screen class 
//    to create them. If a user needs a window they need to create one and get a handle
//    through the screen class.
/********************************************************************************/

class Window
{
  friend class Screen;

  public:
    //we dont want any copying or moving.
    //We want to make sure only one Window obj exists per ncurses WINDOW*
    Window(const Window& other) = delete;
    Window& operator=(const Window& other) = delete;
    Window(Window&& other) = delete;
    Window& operator=(Window&& other) = delete;

    //window attribute getters
    int get_height() const;
    int get_width() const;
    Coord get_pos() const;          //window position relative to the stdscrn
    Coord get_cursor_pos() const;

    //user output
    void clear();
    void refresh();
    void move_cursor(const Coord& pos);
    void add_ch(int ch);
    void add_str(const std::string& str);

  private:
    Window(int width, int height, Coord pos);
    ~Window();

    //member vars
    WINDOW* m_win;  //pointer to the ncurses window object
    int m_width;
    int m_height;
    Coord m_pos;    //position is relative to the screen coords
};

} //end namespace

#endif

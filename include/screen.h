#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

/********************************** SCREEN ***********************************/
// The screen class is our game engines interface to the outside world.
//
// The screen class lets us:
//  - print output to the screen
//  - get input from users
/********************************************************************************/

enum class InputMode {Blocking, NonBlocking};

class Screen
{
  public:
    Screen();
    ~Screen();

    void clear_screen();
    void print_str(const char* text);
    void print_ch(int ch);

    void set_input_mode(InputMode mode);
    int get_ch();
    int get_ch(InputMode mode);

  private:
    InputMode m_input_mode {InputMode::Blocking};
};

#endif

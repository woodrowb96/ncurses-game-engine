#include <ncurses.h>

/********************************** SCREEN ***********************************/
// The screen class is our game engines interface to the outside world.
//
// The screen class lets us:
//  - print output to the screen
//  - get input from users
/********************************************************************************/
class Screen
{
  public:
    Screen();
    ~Screen();

    void print(const char* text);

  private:
};

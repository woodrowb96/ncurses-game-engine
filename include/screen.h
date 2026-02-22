#include <ncurses.h>

/********************************** SCREEN ***********************************/
// A screen class to initialize and interface with the main ncurses stdscrn
/********************************************************************************/
class Screen
{
  public:
    Screen();
    ~Screen();

    void print(const char* text);

  private:
};

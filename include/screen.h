#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>

#include "coord.h"
#include "window.h"

namespace cursen
{

/********************************** SCREEN ***********************************/
// The screen class is our game engines interface to the outside world.
//
// The screen class lets us:
//  - create and manage ncurses subwindows
//  - get input from users
//  - do some simple prints of strings to the stdscrn
//  - interface with some ncurses system facilities
/********************************************************************************/

enum class BlockingMode {Blocking, NonBlocking};

class Screen
{
  public:
    Screen();
    ~Screen();

    //we dont want any copying or moving, because
    //we only want one screen object to exist
    Screen(const Screen& other) = delete;
    Screen& operator=(const Screen& other) = delete;
    Screen(Screen&& other) = delete;
    Screen& operator=(Screen&& other) = delete;

    //user output
    void clear();
    void refresh();
    void add_str(const std::string& str);

    //user input
    int get_ch(BlockingMode mode = DEFAULT_BLOCKING_MODE);
    std::string get_str(int buffer_size = 256);

    //screen attribute getters
    int height() const;
    int width() const;

    //system utils
    void sleep(int ms);

    //manage windows
    Window* create_window(int width, int height, Coord pos = {0,0});

  private:
    static constexpr BlockingMode DEFAULT_BLOCKING_MODE {BlockingMode::Blocking};

    void set_blocking(BlockingMode mode);

    //member vars
    std::vector<Window*> windows_;
};

} //end namespace

#endif

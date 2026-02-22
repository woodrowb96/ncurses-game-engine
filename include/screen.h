#ifndef SCREEN_H
#define SCREEN_H

#include <string>

namespace ncurses_game_eng {

/********************************** SCREEN ***********************************/
// The screen class is our game engines interface to the outside world.
//
// The screen class lets us:
//  - print output to the screen
//  - get input from users
/********************************************************************************/

enum class BlockingMode {Blocking, NonBlocking};

class Screen
{
  public:
    Screen();
    ~Screen();

    void clear_screen();
    void print_str(const std::string& str);
    void print_ch(int ch);

    int get_ch(BlockingMode mode = DEFAULT_BLOCKING_MODE);
    std::string get_str(int buffer_size = 256);

  private:
    static constexpr BlockingMode DEFAULT_BLOCKING_MODE {BlockingMode::Blocking};

    void set_blocking(BlockingMode mode);
};

} //end namespace ncurses_game_eng

#endif

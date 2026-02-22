#include "screen.h"

#include <string>

using namespace ncurses_game_eng;

int main()
{
  Screen screen;
  screen.print_str("HELLO WORLD, from ncurses!");
  screen.get_ch();
  screen.clear_screen();
  screen.print_str("We blocked on that input\n now lets get a string:");
  std::string s = screen.get_str();
  screen.clear_screen();
  screen.print_str(s);
  screen.get_ch();


  return 0;
}

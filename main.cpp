#include "screen.h"

using namespace ncurses_game_eng;

int main()
{
  Screen screen;
  screen.print_str("HELLO WORLD, from ncurses!");

  char c = screen.get_ch();
  screen.set_input_mode(InputMode::NonBlocking);
  screen.clear_screen();
  screen.print_ch(c);
  c = screen.get_ch();
  return 0;
}

#include "screen.h"
#include "coord.h"

#include <string>

using std::string;
using std::to_string;

using namespace ncurses_game_eng;


int main()
{
  string s;

  Screen screen;
  screen.print_str("HELLO WORLD, from ncurses!");
  screen.get_ch();

  screen.clear();
  Coord begining = screen.get_cursor_pos();
  screen.print_str("Cursor_position at start of this line: " + to_string(begining) + "\n");
  screen.print_str("Cursor_position at end of this line:");
  screen.print_str(to_string(screen.get_cursor_pos()));
  screen.get_ch();

  screen.clear();
  screen.print_str("Cursor_position at end of this line:");
  screen.print_str(to_string(screen.get_cursor_pos()));
  screen.get_ch();

  return 0;
}

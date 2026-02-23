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

  Coord pos = screen.get_cursor_pos();

  screen.move_cursor({pos.x + 1, pos.y + 1});
  screen.print_str("Cursor_position at end of this line:");
  screen.print_str(to_string(screen.get_cursor_pos()));
  screen.get_ch();

  screen.move_cursor({pos.x - 5, pos.y + 2});
  screen.print_str("Cursor_position at end of this line:");
  screen.print_str(to_string(screen.get_cursor_pos()));
  screen.get_ch();

  screen.move_cursor({pos.x - 10, pos.y});
  screen.print_str("Cursor_position at end of this line:");
  screen.print_str(to_string(screen.get_cursor_pos()));
  screen.get_ch();
  
  screen.move_cursor({pos.x + 5, pos.y - 5});
  screen.print_str("Cursor_position at end of this line:");
  screen.print_str(to_string(screen.get_cursor_pos()));
  screen.get_ch();

  screen.move_cursor({pos.x + 100, pos.y + 6});
  screen.print_str("Cursor_position at end of this line:");
  screen.print_str(to_string(screen.get_cursor_pos()));
 
  screen.move_cursor({pos.x + 500, pos.y + 500});
  screen.print_str("Cursor_position at end of this line:");
  screen.print_str(to_string(screen.get_cursor_pos()));
  screen.get_ch(); screen.get_ch();

  return 0;
}

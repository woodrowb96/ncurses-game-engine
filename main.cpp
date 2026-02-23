#include "screen.h"
#include "coord.h"
#include "window.h"
#include "game.h"

#include <string>

using std::string;
using std::to_string;

using namespace ncurses_game_eng;

int main()
{
  Screen screen;
  screen.add_str("HELLO WORLD, from ncurses!");
  screen.get_ch();
  screen.add_str("\n");
  screen.add_str("Hello again!");
  screen.get_ch();


  Window* win_1 = screen.create_window(20,5);
  int h = win_1->get_height();
  int w = win_1->get_width();
  Coord win_curs = win_1->get_cursor_pos();

  screen.clear();
  screen.add_str(to_string(h));
  screen.add_str("\n");
  screen.add_str(to_string(w));
  screen.add_str("\n");
  screen.add_str(to_string(win_curs));
  screen.get_ch();

  win_1->add_str("height: " + to_string(h));
  win_1->add_str("\n");
  win_1->add_str("kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");
  win_1->refresh();
  screen.get_ch();

  Coord win_2_pos = win_1->get_pos();
  win_2_pos.x += 3;
  win_2_pos.y += 1;
  Window* win_2 = screen.create_window(3,8,win_2_pos);
  h = win_2->get_height();
  w = win_2->get_width();
  win_curs = win_2->get_cursor_pos();

  win_2->add_str("height: " + to_string(h));
  win_2->add_str("\n");
  win_2->add_str("\n");
  win_2->refresh();
  screen.get_ch();

  win_1->clear();
  win_1->refresh();
  screen.get_ch();

  return 0;
}

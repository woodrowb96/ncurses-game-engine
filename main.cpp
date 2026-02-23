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
  Game game;
  game.run();
  return 0;
}

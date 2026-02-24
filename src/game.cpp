#include "game.h"
#include "coord.h"
#include "window.h"

namespace cursen
{

//PUBLIC

//GAME LOOP
void Game::run()
{

  running_ = true;
  while(running_)
  {
    input();
    update();
    render();
    screen_.sleep(16);
  }
}

//PROTECTED

//user input

int Game::get_input()
{
  return screen_.get_ch(BlockingMode::NonBlocking);
}

//control game flow
void Game::stop()
{
  running_ = false;
}

Window* Game::create_window(int width, int height, Coord pos)
{
  return screen_.create_window(width, height, pos);
}

int Game::screen_width() const
{
  return screen_.width();
}

int Game::screen_height() const
{
  return screen_.height();
}

//PRIVATE

//end namespace ncurses_game_eng
}

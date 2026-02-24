#include "game.h"
#include "coord.h"
#include "window.h"

namespace cursen
{

//PUBLIC

//GAME LOOP
void Game::run()
{

  m_running = true;
  while(m_running)
  {
    input();
    update();
    render();
    m_screen.sleep(16);
  }
}

//PROTECTED

//user input

int Game::get_input()
{
  return m_screen.get_ch(BlockingMode::NonBlocking);
}

//control game flow
void Game::stop()
{
  m_running = false;
}

Window* Game::create_window(int width, int height, Coord pos)
{
  return m_screen.create_window(width, height, pos);
}

int Game::screen_width() const
{
  return m_screen.width();
}

int Game::screen_height() const
{
  return m_screen.height();
}

//PRIVATE

//end namespace ncurses_game_eng
}

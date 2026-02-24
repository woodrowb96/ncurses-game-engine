#include "game.h"
#include "window.h"

using ncurses_game_eng::Game;
using ncurses_game_eng::Window;

class TestGame : public Game
{
  public:
    TestGame();

  private:
    void input() override;
    void update() override;
    void render() override;

    Window* m_win;
    int m_input {'\0'};
    int m_output {'o'};

};

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "game.h"
#include "window.h"
#include "coord.h"

using ncurses_game_eng::Game;
using ncurses_game_eng::Window;
using ncurses_game_eng::Coord;

class TestGame : public Game
{
  public:
    TestGame();

  private:
    //input consts
    static constexpr int UP {'w'};
    static constexpr int DOWN {'s'};
    static constexpr int LEFT {'a'};
    static constexpr int RIGHT {'d'};
    static constexpr int QUIT {'q'};
    static constexpr int NO_INPUT {'\0'};
    //movement consts
    static constexpr int Y_STEP {1};
    static constexpr int X_STEP {1};
    //output consts
    static constexpr int SPRITE {'#'};

    void input() override;
    void update() override;
    void render() override;

    int m_screen_w;
    int m_screen_h;
    Window* m_win;
    int m_input {NO_INPUT};
    Coord m_pos {0,0};
};

#endif

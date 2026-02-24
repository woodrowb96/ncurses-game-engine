#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "game.h"
#include "window.h"
#include "coord.h"

class TestGame : public cursen::Game
{
  public:
    TestGame();

  private:
    //input consts
    static constexpr int kUp {'w'};
    static constexpr int kDown {'s'};
    static constexpr int kLeft {'a'};
    static constexpr int kRight {'d'};
    static constexpr int kQuit {'q'};
    static constexpr int kNoInput {'\0'};
    //movement consts
    static constexpr int kYStep {1};
    static constexpr int kXStep {1};
    //output consts
    static constexpr int kSprite {'#'};

    void input() override;
    void update() override;
    void render() override;

    int screen_w_;
    int screen_h_;
    cursen::Window* win_;
    int input_ {kNoInput};
    cursen::Coord pos_ {0,0};
};

#endif

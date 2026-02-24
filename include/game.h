#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "window.h"

namespace ncurses_game_eng
{

/********************************** GAME ***********************************/
// The game class
/********************************************************************************/

class Game
{
  public:
    Game();
    ~Game();

    //delete copy and move
    //we only want one Game
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    Game(Game&& other) = delete;
    Game& operator=(Game&& other) = delete;

    //game loop
    void run();

  private:
    Screen m_screen;
    Window* m_win;    //for now well just use a single window

    bool m_running {false};  //a game doesnt start running
    int m_input {'\0'};
    int m_output {'t'};

    //game loop functions
    void input();
    void update();
    void render();

};

}//end namespace

#endif

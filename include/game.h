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
    Window* m_win;    //our main window (well expand how we manage windows later)
};

}//end namespace

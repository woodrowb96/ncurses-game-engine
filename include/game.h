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
    //delete copy and move
    //we only want one Game
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    Game(Game&& other) = delete;
    Game& operator=(Game&& other) = delete;

    //game loop
    void run();

  protected:
    Game() = default;
    virtual ~Game() = default;

    //user input
    int get_input();

    //control game flow
    void stop();

    //screen interface functions
    Window* create_window(int width, int height, Coord pos = {0,0});
    int get_screen_width() const;
    int get_screen_height() const;

  private:
    Screen m_screen;

    bool m_running {false};  //a game doesnt start running

    //game loop functions
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

};

}//end namespace

#endif

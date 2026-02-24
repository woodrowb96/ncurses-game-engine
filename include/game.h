#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "window.h"

namespace cursen
{

/********************************** GAME ***********************************/
// The game is the abstract parent class users use to derive their custom games from.
//
// The game class provides users a public run() function to start the game loop.
// Users interface with the game loop through three pure virtual functions
//  - input()
//  - update()
//  - render()
// Users can use these to write their custom game logic.
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
    int screen_width() const;
    int screen_height() const;

  private:
    //game loop functions
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    //member vars
    Screen m_screen;
    bool m_running {false};  //the game starts out not running
};

} //end namespace

#endif

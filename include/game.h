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

  private:
};

}//end namespace

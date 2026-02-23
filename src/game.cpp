#include "game.h"
#include "coord.h"

#include <string>
#include "ncurses.h"

namespace ncurses_game_eng
{

//PUBLIC
Game::Game()
{
  int screen_w = m_screen.get_width();
  int screen_h = m_screen.get_height();

  //create a window over the whole screen
  m_win = m_screen.create_window(screen_w, screen_h, {0,0});
}

Game::~Game()
{
}

//GAME LOOP
void Game::run()
{
  int output {'t'};
  while(true) 
  {
    int input = m_screen.get_ch(BlockingMode::NonBlocking);
    if ( (input == 'q') || (input == 'Q') ) {
      break;
    }
    else if( (input == 't') || (input == 'o') ) {
      output = input;
    }

    m_win->clear();

    switch(output)
    {
      case 't': {
        Coord curs_pos = m_win->get_cursor_pos();

        m_win->add_str("HELLO WORLD");
        m_win->add_ch('\n');
        m_win->add_str("this is a new line using add_ch(\\n)");

        curs_pos = m_win->get_cursor_pos();
        m_win->move_cursor({curs_pos.x = 0, ++curs_pos.y});
        m_win->add_str("this is a new line move_curs");
        m_win->move_cursor({curs_pos.x = 0, ++curs_pos.y});
        m_win->add_str("another new line using move_curs");
        break;
      }
      case 'o': {
        m_win->add_str("OTHER");
        m_win->add_ch('\n');
        m_win->add_str("this is a new line on the other message");
        break;
      }
    }
    m_win->refresh();
    m_screen.sleep(16);
  }
}

}//end namespacek

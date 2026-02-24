#include "test_game.h"

//PUBLIC

TestGame::TestGame()
{
  int w = get_screen_width();
  int h = get_screen_height();
  m_win = create_window(w,h);
}

//PRIVATE

void TestGame::input()
{
  m_input = get_input();
}

void TestGame::update()
{
  if(m_input == 'q') {
    stop();
    // return;
  }
  else if(m_input == 't') {
    m_output = 't';
  }
  else if(m_input == 'o') {
    m_output = 'o';
  }
}

void TestGame::render()
{
  m_win->clear();

  switch(m_output)
  {
    case 't': {
      m_win->add_str("this message say: T");
      break;
    }
    case 'o': {
      m_win->add_str("this message say: O");
      break;
    }
  }

  m_win->refresh();
}

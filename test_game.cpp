#include "test_game.h"
#include "coord.h"

using cursen::Coord;

//PUBLIC

TestGame::TestGame()
  :
  m_screen_w(screen_width()),
  m_screen_h(screen_height())
{
  m_win = create_window(m_screen_w, m_screen_h);
  m_pos = {m_screen_w/2, m_screen_h/2};
}

//PRIVATE

void TestGame::input()
{
  m_input = get_input();
}

void TestGame::update()
{
  switch(m_input)
  {
    case QUIT: {
      stop();
      break;
    }
    case UP: {
      m_pos.y -= Y_STEP;
      break;
    }
    case DOWN: {
      m_pos.y += Y_STEP;
      break;
    }
    case LEFT: {
      m_pos.x -= X_STEP;
      break;
    }
    case RIGHT: {
      m_pos.x += X_STEP;
      break;
    }
  }

  //wrap our x position
  if( m_pos.x > (m_screen_w - 1) ) {
    m_pos.x = 0;
  }
  else if( m_pos.x < 0 ) {
    m_pos.x = m_screen_w - 1;
  }

  //wrap our y position
  if( m_pos.y > (m_screen_h - 1) ) {
    m_pos.y = 0;
  }
  else if( m_pos.y < 0 ) {
    m_pos.y = m_screen_h - 1;
  }
}

void TestGame::render()
{
  //clear the screen
  m_win->clear();

  //draw our cube to the buffer
  Coord cursor = m_pos;
  m_win->move_cursor(cursor);
  m_win->add_ch(SPRITE);

  cursor.x += 1;
  m_win->move_cursor(cursor);
  m_win->add_ch(SPRITE);

  cursor.y += 1;
  m_win->move_cursor(cursor);
  m_win->add_ch(SPRITE);

  cursor.x -= 1;
  m_win->move_cursor(cursor);
  m_win->add_ch(SPRITE);

  //push buffer onto screen
  m_win->refresh();
}

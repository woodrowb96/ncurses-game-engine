#include "test_game.h"
#include "coord.h"

using cursen::Coord;

//PUBLIC

TestGame::TestGame()
  :
  screen_w_(screen_width()),
  screen_h_(screen_height())
{
  win_ = create_window(screen_w_, screen_h_);
  pos_ = {screen_w_/2, screen_h_/2};
}

//PRIVATE

void TestGame::input()
{
  input_ = get_input();
}

void TestGame::update()
{
  switch(input_)
  {
    case QUIT: {
      stop();
      break;
    }
    case UP: {
      pos_.y -= Y_STEP;
      break;
    }
    case DOWN: {
      pos_.y += Y_STEP;
      break;
    }
    case LEFT: {
      pos_.x -= X_STEP;
      break;
    }
    case RIGHT: {
      pos_.x += X_STEP;
      break;
    }
  }

  //wrap our x position
  if( pos_.x > (screen_w_ - 1) ) {
    pos_.x = 0;
  }
  else if( pos_.x < 0 ) {
    pos_.x = screen_w_ - 1;
  }

  //wrap our y position
  if( pos_.y > (screen_h_ - 1) ) {
    pos_.y = 0;
  }
  else if( pos_.y < 0 ) {
    pos_.y = screen_h_ - 1;
  }
}

void TestGame::render()
{
  //clear the screen
  win_->clear();

  //draw our cube to the buffer
  Coord cursor = pos_;
  win_->move_cursor(cursor);
  win_->add_ch(SPRITE);

  cursor.x += 1;
  win_->move_cursor(cursor);
  win_->add_ch(SPRITE);

  cursor.y += 1;
  win_->move_cursor(cursor);
  win_->add_ch(SPRITE);

  cursor.x -= 1;
  win_->move_cursor(cursor);
  win_->add_ch(SPRITE);

  //push buffer onto screen
  win_->refresh();
}

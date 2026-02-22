#include "coord.h"

namespace ncurses_game_eng
{

Coord Coord::operator+(const Coord& other) const
{
  return {x + other.x, y + other.y};
}

Coord Coord::operator-(const Coord& other) const
{
  return {x - other.x, y - other.y};
}

bool Coord::operator==(const Coord& other) const
{
  return (x == other.x) && (y == other.y);
}

bool Coord::operator!=(const Coord& other) const
{
  return !(*this == other);
}

} //end namespace

#include "coord.h"

#include <string>

namespace cursen
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

std::string to_string(const Coord& coord)
{
  return "(" + std::to_string(coord.x) + "," + std::to_string(coord.y) + ")";
}

} //end namespace

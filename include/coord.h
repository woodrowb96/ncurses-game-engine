#ifndef COORD_H
#define COORD_H

#include <string>

namespace ncurses_game_eng
{

struct Coord
{
  int x;
  int y;

  //arithmetic operators
  Coord operator+(const Coord& other) const;
  Coord operator-(const Coord& other) const;

  //logical operators
  bool operator==(const Coord& other) const;
  bool operator!=(const Coord& other) const;
};

std::string to_string(const Coord& coord);

} //end namespace

#endif

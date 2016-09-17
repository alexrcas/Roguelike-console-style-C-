#pragma once

#include <cmath>
#include "room.hpp"
#include "character.hpp"

class room;
class player;

/**
 * @class monster
 * @brief Representa un monstruo.
 * */

class monster: public character {
public:
  monster(room&);
  ~monster();
  char print();
  bool is_near(character&);
  bool allowtomove(table& tb, int y, int x);
};
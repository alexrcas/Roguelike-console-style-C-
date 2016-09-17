#pragma once

#include "character.hpp"


/**
 * @class player
 * @brief Representa al personaje
 * */
class player : public character {
private:
public:
  player(int x, int y, int health);
  ~player();
  char print();
};
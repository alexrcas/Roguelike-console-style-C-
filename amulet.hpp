#pragma once

#include "room.hpp"

/**
 * @class amulet
 * @brief Representa el amuleto del juego
 * */

class room;

class amulet {
private:
  coordinate cord_; //!<@brief Coordenadas del amuleto
public:
  amulet(room&);
  ~amulet();
  int get_x();
  int get_y();
  char print();
};
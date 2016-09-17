#pragma once

#include "table.hpp"

/**
 * @class character
 * @brief Clase de la que heredan todos los personajes del juego
 * */

class table;

class character {
protected:
  coordinate cord_; //!<@brief Coordenadas del personaje
  int health_;	//!<@brief Salud del personaje
public:
  character();
  character(int, int, int);
  virtual ~character();
  void move_left(table&);
  void move_right(table&);
  void move_up(table&);
  void move_down(table&);
  virtual bool allowtomove(table&, int, int);
  int get_x();
  int get_y();
  virtual char print()=0;
  int& get_health();
};
#pragma once

#include <iostream>
#include "coordinate.hpp"
#include "room.hpp"
#include "table.hpp"
/**
 * @class door
 * @brief Representa una puerta
 * */

class room;
class table;

using namespace std;

class door {
private:
  coordinate cord_; //!<@brief Coordenadas de la puerta
public:
  door();
  door(int, int);
  ~door();
  void print(table&);
  void install_left(room&);
  void install_right(room&);
  void install_top(room&);
  void install_bottom(room&);
  coordinate get_coordinate();
};
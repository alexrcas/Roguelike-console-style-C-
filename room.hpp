#pragma once

#include "door.hpp"

/**
 * @class room
 * @brief Representa la habitación
 * */

class door;
class table;

class room {
private:
  int id_; //!<@brief Número de la habitación
  coordinate cord_[2];//!<@brief Vector que contiene ambas coordenadas
  door* door_[2];//!<@brief Vector que contiene las puertas
public:
  room(int);
  ~room();
  
  void print(table&);
  void create(int, int, int, int);
  void create_doors();
  
  coordinate get_coordinate(int);
  coordinate get_door_coordinate(int);
  
  coordinate get_access_point();
};
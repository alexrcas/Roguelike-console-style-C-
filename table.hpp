#pragma once

#include <cstdlib>
#include <iomanip>

#include "amulet.hpp"
#include "character.hpp"

/**
 * @class table
 * @brief Representa el tablero de juego
 * */

class amulet;
class character;


class table {
private:
  char** M_;//!<@brief Matriz que hace de tablero
  int xsize_;//!<@brief Anchura del tablero
  int ysize_;//!<@brief Altura del tablero
public:
  table(int, int);
  ~table();
  void clean();
  void print(character&, character**, amulet&);
  
  char &get(int, int);
  
  int get_xsize();
  int get_ysize();
  
};
#pragma once

#include "fstream"
#include "table.hpp"
#include "amulet.hpp"
#include "character.hpp"
#include "player.hpp"
#include "monster.hpp"

/**
 * @class game
 * @brief Encapsula a todas las demás clases y las gestiona ofreciendo al
 * jugador la interfaz de juego
 * */

class game {
private:
  table* table_; //!<@brief Tablero de juego
  room* room_[3]; //!<@brief Vector de habitaciones
  character* p_; //!<@brief Personaje
  character* mons_[9]; //!<@brief Vector de monstruos
  amulet* am_; //!<@brief Amuleto
  ifstream* file_; //!<@brief Fichero de entrada (opcional)
  int x_; //!<@brief Anchura del tablero
  int y_; //!<@brief Altura del tablero
public:
  game(int, int);
  game(char* filename);
  ~game();
  void refresh();
  void initialize();
  void generate_paths();
  void trace(table&, char, int, int, int, int);
  void start();
  
  void move_player();
  void move_monsters();
  void test_health();
};
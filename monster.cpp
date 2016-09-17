#include "monster.hpp"


/**
 * @brief Constructor. Genera un monstruo en una habitación en una
 * posición al azar
 * @param rm Habitación donde se desea colocar el monstruo
 * */
monster::monster(room& rm)
{
  coordinate point1 = rm.get_coordinate(0);
  coordinate point2 = rm.get_coordinate(1);
  cord_.x_ = rand()%((point2.x_)-(point1.x_+2)) + point1.x_+2;
  cord_.y_ = rand()%((point2.y_)-(point1.y_+2)) + point1.y_+2;
}

/**
 * @brief Destructor de la clase
 * */
monster::~monster()
{
}

/**
 * @brief Devuelve el símbolo usado para pintar el monstruo en el tablero
 * @returns Símbolo del monstruo
 * */
char monster::print()
{
  return 'o';
}

/**
 * @brief Comprueba si el monstruo está cerca del jugador.
 * @returns Booleano que indica si el monstruo está adyacente al jugador
 * */
bool monster::is_near(character& player)
{
  if ((fabs((cord_.x_)-(player.get_x()))<=1) && (fabs(cord_.y_-player.get_y())<=1))
    return true;
}

/**
 * @brief Herencia virtual de la clase character.
 * @returns Indica si el movimiento está permitido.
 * Véase que el monstruo no puede atravesar las puertas
 * */
bool monster::allowtomove(table& tb, int y, int x)
{
  return ((tb.get(y,x)=='*')||(tb.get(y,x)=='+'));
}
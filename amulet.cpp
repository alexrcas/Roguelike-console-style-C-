#include "amulet.hpp"

/**
 * @brief Constructor. Recibe una habitación y coloca el amuleto en su centro
 * @param rm Habitación donde se desea colocar el amuleto
 * */
amulet::amulet(room& rm)
{
  cord_.x_ = (rm.get_coordinate(1).x_ + rm.get_coordinate(0).x_)/2;
  cord_.y_ = (rm.get_coordinate(1).y_ + rm.get_coordinate(0).y_)/2;
}

/**
 * @brief Destructor.
 * */
amulet::~amulet()
{
}

/**
 * @brief Devuelve la coordenada X del amuleto
 * @returns Coordenada X del amuleto.
 * */
int amulet::get_x()
{
  return cord_.x_;
}

/**
 * @brief Devuelve la coordenada Y del amuleto
 * @returns Coordenada Y del amuleto.
 * */
int amulet::get_y()
{
  return cord_.y_;
}

/**
 * @brief Devuelve el símbolo del amuleto
 * @returns Símbolo del amuleto.
 * */
char amulet::print()
{
  return '&';
}
#include "character.hpp"

/**
 * @brief Constructor por defecto.
 * */
character::character()
{
}

/**
 * @brief Constructor de la clase.
 * @param y Coordenada de spawn en Y
 * @param x Coordenada de spawn en X
 * @param health Salud del personaje
 * */
character::character(int y, int x, int health=5)
{
  cord_.y_ = y;
  cord_.x_ = x;
  health_ = health;
}

/**
 * @brief Destructor de la clase
 * */
character::~character()
{
}

/**
 * @brief Mueve el personaje a la izquierda
 * @param tb Referencia al tablero de juego
 * */
void character::move_left(table& tb)
{
  if((cord_.x_ > 0)&&(!allowtomove(tb, cord_.y_, cord_.x_-1)))
    cord_.x_-=1;
}

/**
 * @brief Mueve el personaje a la derecha
 * @param tb Referencia al tablero de juego
 * */
void character::move_right(table& tb)
{
  if((cord_.x_ <(tb.get_xsize()-1))&&(!allowtomove(tb, cord_.y_, cord_.x_+1)))
    cord_.x_+=1;
}

/**
 * @brief Mueve el personaje arriba
 * @param tb Referencia al tablero de juego
 * */
void character::move_up(table& tb)
{
  if((cord_.y_ > 0)&&(!allowtomove(tb, cord_.y_-1, cord_.x_)))
    cord_.y_-=1;
}

/**
 * @brief Mueve el personaje abajo
 * @param tb Referencia al tablero de juego
 * */
void character::move_down(table& tb)
{
  if((cord_.y_ <(tb.get_ysize()-1))&&(!allowtomove(tb, cord_.y_+1, cord_.x_)))
    cord_.y_+=1;
}

/**
 * @brief Indica si el punto de destino está libre
 * @param tb Referencia al tablero de juego
 * @param y Punto deseado en Y
 * @param x Punto deseado en X
 * */
bool character::allowtomove(table& tb, int y, int x)
{
  if(tb.get(cord_.y_, cord_.x_)=='#')
  {
    if((tb.get(y,x)!='#')&&(tb.get(y,x)!='+'))
      return true;
  }
  return (tb.get(y,x)=='*');
}

/**
 * @brief Devuelve la coordenada X del personaje
 * @returns Coordenada X del personaje
 * */
int character::get_x()
{
  return cord_.x_;
}

/**
 * @brief Devuelve la coordenada Y del personaje
 * @returns Coordenada Y del personaje
 * */
int character::get_y()
{
  return cord_.y_;
}

/**
 * @brief Devuelve una referencia a la salud del personaje
 * @returns Salud del personaje
 * */
int& character::get_health()
{
  return health_;
}
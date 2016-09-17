#include "door.hpp"


/**
 * @brief Constructor por defecto
 * */
door::door() {}

/**
 * @brief Constructor de la clase. Asigna a la puerta en el punto dado
 * */
door::door(int x, int y)
{
  cord_.x_=x;
  cord_.y_=y;
}
  
/**
 * @brief Destructor de la clase
 * */
door::~door() {}

/**
 * @brief Imprime la puerta en el tablero de juego
 * @param tb Referencia al tablero de juego
 * */
void door::print(table& tb)
{
  tb.get(cord_.y_, cord_.x_)='+';
}

/**
 * @brief Coloca la puerta en el lado izquierdo de una habitación
 * @returns Habitación donde se desea la puerta
 * */
void door::install_left(room& rm)
{
  coordinate point1 = rm.get_coordinate(0);
  coordinate point2 = rm.get_coordinate(1);
  cord_.x_ = point1.x_;
  cord_.y_ = (point1.y_ + point2.y_)/2;
}

/**
 * @brief Coloca la puerta en el lado derecho de una habitación
 * @returns Habitación donde se desea la puerta
 * */
void door::install_right(room& rm)
{
  coordinate point1 = rm.get_coordinate(0);
  coordinate point2 = rm.get_coordinate(1);
  cord_.x_ = point2.x_;
  cord_.y_ = (point1.y_ + point2.y_)/2;
}

/**
 * @brief Coloca la puerta en el lado superior de una habitación
 * @returns Habitación donde se desea la puerta
 * */
void door::install_top(room& rm)
{
  coordinate point1 = rm.get_coordinate(0);
  coordinate point2 = rm.get_coordinate(1);
  cord_.y_ = point1.y_;
  cord_.x_ = (point1.x_ + point2.x_)/2;
}

/**
 * @brief Coloca la puerta en el lado inferior de una habitación
 * @returns Habitación donde se desea la puerta
 * */
void door::install_bottom(room& rm)
{
  coordinate point1 = rm.get_coordinate(0);
  coordinate point2 = rm.get_coordinate(1);
  cord_.y_ = point2.y_;
  cord_.x_ = (point1.x_ + point2.x_)/2;
}

/**
 * @brief Devuelve las coordenadas de la puerta
 * @returns Estructura de datos que contiene las coordenadas de la puerta.
 * */
coordinate door::get_coordinate()
{
  return cord_;
}

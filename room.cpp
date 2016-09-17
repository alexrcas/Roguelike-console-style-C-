#include "room.hpp"

/**
 * @brief Constructor de la clase
 * @param id Número de la habitación
 * */
room::room(int id)
{
  id_=id;
  for(int i=0;i<2;i++)
    door_[i] = new door();
}

/**
 * @brief Destructor de la clase
 * */
room::~room()
{
  for(int i=0;i<2;i++)
  {
    if(door_[i]!=NULL)
      delete door_[i];
  }
}

/**
 * @brief Pinta la habitación en el tablero
 * @param tb Referencia al tablero de juego
 * */
void room::print(table& tb)
{
  for(int i=cord_[0].x_;i<=cord_[1].x_;i++)
  {
    tb.get(cord_[0].y_, i)='*';
    tb.get(cord_[1].y_, i)='*';
  }
  for(int i=cord_[0].y_;i<=cord_[1].y_;i++)
  {
    tb.get(i, cord_[0].x_)='*';
    tb.get(i, cord_[1].x_)='*';
  }
  for(int i=0;i<2;i++)
  {
    door_[i]->print(tb);
  }
}

/**
 * @brief Genera las coordenadas de una habitación dentro del área dada
 * @param hinf Límite inferior en X
 * @param hsup Límite superior en X
 * @param vinf Límite inferior en Y
 * @param vsup Límite superior en Y
 * */
void room::create(int hinf, int hsup, int vinf, int vsup)
{
  srand(time(NULL));
  
  cord_[0].x_ = rand()%(hsup-hinf-MINSIZE)+hinf;
  cord_[0].y_ = rand()%(vsup-vinf-MINSIZE)+vinf;
  cord_[1].x_ = rand()%(hsup-(cord_[0].x_+MINSIZE))+cord_[0].x_+MINSIZE;
  cord_[1].y_ = rand()%(vsup-(cord_[0].y_+MINSIZE))+cord_[0].y_+MINSIZE;
  
  create_doors();
}

/**
 * @brief Coloca las puertas de la habitación
 * */
void room::create_doors()
{
  switch (id_)
  {
    case 1:
      door_[0]->install_bottom(*this);
      door_[1]->install_right(*this);
    break;
    
    case 2:
      door_[0]->install_left(*this);
      door_[1]->install_right(*this);
    break;
    
    case 3:
      door_[0]->install_top(*this);
      door_[1]->install_right(*this);
    break;
  }
}

/**
 * @brief Devuelve las coordenadas de uno de los dos puntos de la habitación
 * @returns Estructura que contiene las coordenadas de un vércite
 * */
coordinate room::get_coordinate(int inx)
{
  if(inx<2)
    return cord_[inx];
  else
    cerr<<"Error. No existe el punto"<<endl;
}

/**
 * @brief Devuelve las coordenadas de la puerta elegida de la habitación
 * @returns Estructura que contiene las coordenadas de la puerta
 * */
coordinate room::get_door_coordinate(int inx)
{
  if(inx<2)
    return door_[inx]->get_coordinate();
  else
    cerr<<"Error. No existe la puerta"<<endl;
}

/**
 * @brief Devuelve el punto de acceso de la habitación (su centro)
 * @returns Estructura que contiene las coordenadas del punto de acceso
 * */
coordinate room::get_access_point()
{
  coordinate dummy;
  dummy.x_ = (cord_[0].x_ + cord_[1].x_)/2;
  dummy.y_ = (cord_[0].y_ + cord_[1].y_)/2;
  return dummy;
}
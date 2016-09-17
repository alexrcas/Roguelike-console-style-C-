#include "player.hpp"

/**
 * @brief Constructor del protagonista
 * @param x Posición X del personaje
 * @param y Posición Y del personaje
 * @param health Salud del personaje
 * */
player::player(int x, int y, int health): character(y, x, health)
{
}

/**
 * @brief Destructor de la clase
 * */
player::~player()
{
}

/**
 * @brief Devuelve el símbolo para usado para pintar el personaje
 * @returns Símbolo usado para pintar el personaje en pantalla
 * */
char player::print()
{
  return '@';
}
#include "game.hpp"

/**
 * @mainpage
 * @author Alexis Rodríguez Casañas (grupo L10)
 * @date 21/09/2015
 * */
int main()
{
  int x,y;
  cout<<"Dimensiones del tablero (mínimo 30x30): ";
  cin>>y>>x;
  game* G = new game(y,x);
  /*char aux[256];
  cin>>aux;
  game* G = new game(aux);*/
  G->start();
  
  return 0;
}
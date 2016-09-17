#include "game.hpp"

/**
 * @brief Constructor. Inicia el juego
 * @param y Altura del tablero
 * @param x Anchura del tablero
 * */
game::game(int y, int x)
{
  x_=x;
  y_=y;
  if((x<MAXSIZE*2)||(y<MAXSIZE*2))
  {
    cout<<"Dimensiones incorrectas. Redimensionando automaticamente..."<<endl;
    x_=MAXSIZE*2;
    y_=x_;
  }
  table_ = new table(y_, x_);
  for(int i=0;i<3;i++)
    room_[i] = new room(i+1);
  initialize();
  
}

/**
 * @brief Constructor. Inicia el juego a partir de un fichero
 * @param filename Nombre del fichero que contiene los datos de entrada
 * */
game::game(char* filename)
{
  file_ = new ifstream(filename);
  if(file_->is_open())
  {
    *file_ >> x_;
    *file_ >> y_;
    table_ = new table(y_, x_);
    for(int i=0;i<3;i++)
      room_[i] = new room(i+1);
    initialize();
  }
  else
  {
    cerr<<"No se encuentra el fichero!"<<endl;
  }
}

/**
 * @brief Destructor
 * */
game::~game()
{
  if(table_!=NULL)
    delete table_;
  if(p_!=NULL)
    delete p_;
  if(am_!=NULL)
    delete am_;
  if(file_!=NULL)
    delete file_;
  for(int i=0;i<9;i++)
  {
    if (mons_[i]!=NULL)
      delete mons_[i];
  }
  for(int i=0;i<3;i++)
  {
    if (room_[i]!=NULL)
      delete room_[i];
  }
}

/**
 * @brief Actualiza la pantalla limpiándola y repintando el tablero
 * */
void game::refresh()
{
  system("clear");
  for(int i=0;i<9;i++)
    table_->print(*p_, mons_, *am_);
}

/**
 * @brief Inicia el juego una vez están los datos listos.
 * Se crean las habitaciones, se crean y colocan los personajes y
 * objetos.
 * Se generan los pasillos que conectan las habitaciones
 * */
void game::initialize()
{
  room_[0]->create(0, (x_/2)-2, 0, (y_/2)-2);
  room_[1]->create(x_/2,y_-2,0,(y_/2)-2);
  room_[2]->create(0,x_-2,y_/2,y_);
  
  for(int i=0;i<3;i++)
    room_[i]->print(*table_);
  coordinate access_point = room_[0]->get_access_point();
  p_ = new player(access_point.x_, access_point.y_ ,5);
  
  for(int i=0;i<9;i++)
  {
    mons_[i]=new monster(*room_[i%3]);;
  }
  am_ = new amulet(*room_[2]);
  generate_paths();
  
}

/**
 * @brief Solicita un movimiento al jugador y lo aplica. Acto seguido
 * mueve los monstruos y comprueba si el jugador debe recibir daño
 * */
void game::move_player()
{
  char m;
  const char heart[] = "\xe2\x99\xa5";
  for(int i=0;i<p_->get_health();i++)
    cout<<heart<<" ";
  cout<<"\nJ.Left\tL.Right\t\tI.Up\tK.Down"<<endl;
  cin>>m;
  switch(m)
  {
    case 'l':
      p_->move_right(*table_);
      break;
      
    case 'j':
      p_->move_left(*table_);
      break;
      
    case 'i':
      p_->move_up(*table_);
      break;
      
    case 'k':
      p_->move_down(*table_);
      break;
  }
  move_monsters();
  test_health();
}

/**
 * @brief Genera un movimiento al azar para todos los monstruos
 * */
void game::move_monsters()
{
  int mov;
  for(int i=0;i<9;i++)
  {
    mov = rand()%4;
    switch (mov)
    {
      case 0:
	mons_[i]->move_left(*table_);
      break;
      case 1:
	mons_[i]->move_right(*table_);
      break;
      case 2:
	mons_[i]->move_up(*table_);
      break;
      case 3:
	mons_[i]->move_down(*table_);
      break;
    }
  }
}

/**
 * @brief Comprueba la distancia entre monstruos y jugador y disminuye
 * su nivel de vida si procede

 * */
void game::test_health()
{
  for(int i=0;i<9;i++)
  {
    if(static_cast<monster*>(mons_[i])->is_near(*p_))
      p_->get_health()--;
  }
}

/**
 * @brief Genera los pasillos que conectan las habitaciones
 * */
void game::generate_paths()
{
  /*PRIMER PASILLO*/
  coordinate point1 = room_[0]->get_door_coordinate(1);
  coordinate point2 = room_[1]->get_door_coordinate(0);
  for(int i=point1.x_+1; i<point2.x_;i++)
  {
    table_->get(point1.y_, i) = '#';
  }
  /*SEGUNDO PASILLO*/
  point1 = room_[0]->get_door_coordinate(0);
  point2 = room_[2]->get_door_coordinate(0);
  
  int dir = point2.x_ - point1.x_;
  if(dir>0)
  {
    trace(*table_, '#', point1.y_+1, point2.y_-2, point1.x_, point1.x_);
    trace(*table_, '#', point2.y_-2, point2.y_-2, point1.x_, point2.x_);
    trace(*table_, '#', point2.y_-2, point2.y_-1, point2.x_, point2.x_);
  }
  else
  {
    trace(*table_, '#', point1.y_+1, point2.y_-2, point1.x_, point1.x_);
    trace(*table_, '#', point2.y_-2, point2.y_-2, point2.x_, point1.x_);
    trace(*table_, '#', point2.y_-2, point2.y_-1, point2.x_, point2.x_);
  }
  /*TERCER PASILLO*/
  point1 = room_[1]->get_door_coordinate(1);
  point2 = room_[2]->get_door_coordinate(1);
  trace(*table_, '#', point1.y_, point1.y_, point1.x_+1, point1.x_+2);
  trace(*table_, '#', point1.y_, point2.y_, point1.x_+2, point1.x_+2);
  trace(*table_, '#', point2.y_, point2.y_, point2.x_+1, point1.x_+2);
}

/**
 * @brief Traza una pared de simbolos vertical u horizontal con destino y fin en los puntos.
 * Necesita que los puntos X o Y estén en el mismo eje o no hará nada.
 * @param tb Referencia al tablero de juego
 * @param symbol Símbolo con el que trazar
 * @param y1 Punto de partida
 * @param y2 Punto de destino
 * */
void game::trace(table& tb, char symbol, int y1, int y2, int x1, int x2)
{
  if(y1==y2)
  {
    for(int i=x1;i<=x2;i++)
      tb.get(y1, i)=symbol;
  }
  else
  {
    if(x1==x2)
    {
      for(int i=y1;i<=y2;i++)
	tb.get(i,x1)=symbol;
    }
    else
    {
      cerr<<"Error. No existe una linea recta entre los puntos."<<endl;
    }
  }
}


/**
 * @brief Función principal. Mantiene la partida en bucle hasta
 * que el jugador gane o pierda
 * */
void game::start()
{
  bool dead=false;
  refresh();
  while((p_->get_x()!=am_->get_x()||(p_->get_y()!=am_->get_y())))
  {
    move_player();
    refresh();
    if(p_->get_health()<=0)
    {
      dead=true;
      break;
    }
  }
  if(!dead)
  {
    cout<<"*********************************************"<<endl;
    cout<<"*                 HAS GANADO!               *"<<endl;
    cout<<"*********************************************"<<endl;
  }
  else
  {
    cout<<"\n*********************************************"<<endl;
    cout<<"****************HAS PERDIDO******************"<<endl;
    cout<<"*********************************************"<<endl;
    
  }
}
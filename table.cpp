#include "table.hpp"

/**
 * @brief Constructor. Genera el tablero
 * @param ysize Altura del tablero
 * @param xsize Anchura del tablero
 * */
table::table(int ysize, int xsize):
  xsize_(xsize),
  ysize_(ysize)
  {
    try {
      
    M_=new char*[ysize_];
    for(int i=0;i<ysize_;i++)
      M_[i]=new char[xsize_];
    }
    catch(std::bad_alloc&) {
      cerr<<"Memoria insuficiente"<<endl;
      exit(-1);
    }
      
    clean();
  }
  
  /**
 * @brief Destructor de la clase
 * */
table::~table() 
{
  if (M_!=NULL)
  {
    for(int i=0;i<ysize_;i++)
    {
      if (M_[i]!=NULL)
	delete [] M_[i];
    }
    delete [] M_;
  }
}

/**
 * @brief Limpia, dejando en blanco el tablero
 * */
void table::clean()
{
  for(int i=0;i<ysize_;i++)
  {
    for(int j=0;j<xsize_;j++)
    {
      M_[i][j] = ' ';
    }
  }
}

/**
 * @brief Imprime el tablero por pantalla
 * @param p Personaje
 * @param m Vector que contiene los monstruos del juego
 * @param am amuleto
 * */
void table::print(character& p, character** m, amulet& am)
{
  bool flag;
  
  for(int i=0;i<ysize_;i++)
  {
    for(int j=0;j<xsize_;j++)
    {
      if((i==p.get_y())&&(j==p.get_x()))
      {
	cout<<p.print();
      }
      else
      {
	    for(int k=0;k<9;k++)
	    {
	      flag=false;
	      if ((i==m[k]->get_y()) && (j==m[k]->get_x()))
	      {
		cout<<m[k]->print();
		flag=true;
	      }
	    }
	    if((i==am.get_y()) && (j==am.get_x()))
	      cout<<am.print();
      }
      if(flag==false)
	cout<<M_[i][j];
      
    }
    cout<<endl;
  }
}

/**
 * @brief Devuelve una referencia a una celda del tablero
 * @param y Coordenada en Y
 * @param x Coordenada en X
 * @returns Referencia al contenido de una celda del tablero
 * */
char& table::get(int y, int x)
{
  if((y<ysize_)&&(x<xsize_))
    return M_[y][x];
}

/**
 * @brief Devuelve la anchura del tablero
 * @returns Anchura del tablero
 * */
int table::get_xsize()
{
  return xsize_;
}

/**
 * @brief Devuelve la altura del tablero
 * @returns Altura del tablero
 * */
int table::get_ysize()
{
  return ysize_;
}

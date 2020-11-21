#include "imdbS.h"
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;
/*****************************************

Funcion de Abstraccion:
AF: Rep => Abs
   
  dada I vector<movie> datos; // Donde se almacenan las peliculas.
  list< vector<movie>::iterator > borrados //posiciones borradas
  
  (datos, borrados,ind_peli,ind_anio) ==> imbd
  
Un objeto abstracto, IMDb, se instancia en la clase imdb:


 I.datos == imdb, donde las posiciones en borradas no son películas válidas

ind_peli es un indice ordenado sobre las peliculas válidas (no estan borradas)
 ind_peli.find(nombre) representa el indice de una pelicula valida

ind_anio, representa un indice por año, dentro de cada año, las peliculas se encuentran ordendas por un indice por nombre (solo las no borradas). 
  ind_anio[1995] es un map sobre peliculas ordenado alfabeticamente.

Invariante de la Representación:


Propiedades que debe cumplir cualquier objeto 

- No puede existir dos copias de una misma pelicula en posiciones validas de imdb.

- i representa a una posición valida (pelicula en imdb) sii el datos.begin()+i no pertenece a la
lista de borrados.

- I.size() = I.imdb.size()-borrados.size(); 
 
- Hay que tener en cuenta que el nombre de la película se puede repetir
(aunque en el mismo año sólo habría una con un mismo tìtulo).

- ind_peli.find(nombre) representa el indicice de una pelicula valida (no borrada)


*/

/* @brief Sobrecarga del operador << para movie */
 ostream & operator<<( ostream & s, const movie &x) {
  s<< x.distr<< " " << x.votos << " " << x.media << " "  << x.nombre << " " << x.anio << "  "<< x.otra;
  return s;
  }
  
/* @brief Sobrecarga del operador < para movie */
bool  operator<(const movie & x,const movie m)  {
 if (x.nombre < m.nombre) return true;
 else if (x.nombre == m.nombre) return (x.anio < m.anio);
 return false;
 }
 
 
/* @brief Sobrecarga del operador == para movie */
bool  operator==(const movie & x,const movie m)  {
 if ( (x.nombre == m.nombre)&&  (x.anio ==  m.anio)) return true;
 return false;
 }
 
/********************************************************************
Metodos de IMDB
********************************************************************/

imdb::size_type imdb::size() const
{

  return datos.size()-borrados.size();
}



bool imdb::cheq_rep() const{
//Implementar el metodo

  
}

/********************************************************************
Metodos de IMDB::CONST_ITERATOR
********************************************************************/



imdb::const_iterator::const_iterator()
{
ptr = 0;
}

imdb::const_iterator::const_iterator(const imdb::const_iterator& it)
{
pos = it.pos;
ptr=it.ptr;
}



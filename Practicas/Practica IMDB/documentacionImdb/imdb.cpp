#include "imdbU.h"
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;
/*****************************************

Funcion de Abstraccion:
AF: Rep => Abs
   
  dada I vector<movie> datos; // Donde se almacenan las peliculas.
  list< vector<movie>::iterator > borrados //posiciones borradas
  
  (datos, borrados) ==> imbd
  
Un objeto abstracto, IMDb, se instancia en la clase imdb:


 I.datos == imdb, donde las posiciones en borradas no son películas válidas

Invariante de la Representación:


Propiedades que debe cumplir cualquier objeto 

- i representa a una posición valida (pelicula en imdb) sii el datos.begin()+i no pertenece a la
lista de borrados.

- I.size() = I.imdb.size()-borrados.size(); 
 
- Hay que tener en cuenta que el nombre de la película se puede repetir
(aunque en el mismo año sólo habría una con un mismo tìtulo).

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
el_ite = it.el_ite;
ptr=it.ptr;
}



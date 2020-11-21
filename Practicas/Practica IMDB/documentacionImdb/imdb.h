#ifndef __imdb_H
#define __imdb_H

#include <assert.h>
#include <vector>
#include <set>
#include <list>
#include <string>

using namespace std;


/** Struct para gestionar las peliculas 
 
 @param distr distribucion del voto
 @param votos numero de votos
 @param media voto medio de la pelicula
 @param anio ano de lanzamiento 
 @param nombre titulo de la pelicula
 @param otra resto de informacion
 */

struct movie{
 string distr;
 int votos;  
 float media;
 string anio;
 string nombre;
 string otra;
 };
 

/* @brief Sobrecarga del operador << para movie */
 ostream & operator<<( ostream & s, const movie &x);

/* @brief Sobrecarga del operador < para movie */
bool  operator<(const movie & x,const movie m);


/* @brief Sobrecarga del operador == para movie */
bool  operator==(const movie & x,const movie m);

/** \class imdb imdb.h

imdb:imdb, operator=, size, empty,  insert, erase, find, 

Descripcion


Un objeto de la clase imbd representara un contenedor que permite almacenar informacion sobre como un conjunto de
usuarios de Internet Movie Database (imdb) han valorado a un conjunto de películas.


El numero de elementos en la base de datos puede variar dinamicamente; la gestion de la memoria es automatica. 
 
*/

class imdb {
 public:

/** @typedef typedef size_type
Hace referencia al tipo asociado al numero de elementos de imdb

*/
typedef unsigned int size_type;

/** @typedef iterador
Hace referencia a un elemento en imdb. Nos permite iterar sobre las peliculas en orden alfabético

*/
class const_iterator; 



 /**
     @brief Constructor primitivo 
  */
  imdb(  );

/**
     @brief Constructor de copia.
     
     @param[in] org imdb que se copia
     
     Crea un imdb  duplicado exacto de org.
  */
  imdb( const imdb & org);

/**
     @brief Destructor.
     Destruye el receptor liberando los recursos que ocupaba.
  */
  ~imdb();

/** @brief tamaÃ±o
 * @return delvuelve el numero de elementos del imdb
    Devuelve el numero de elementos en el imdb
*/
  size_type size() const;

/** @brief determina si la cadena esta vacia
 * @return devuelve true si esta vacia y false en caso contrario
   Chequea si el imdb esta vacio (size()==0)
*/
  bool empty() const;
  

/** @brief Inserta una nueva pelicula  dentro de un imdb

@param[in] x elemento a insertar en el imdb
@param[out] bool true si la insercion se ha podido realizar con exito
@post  el size() sera incrementado
*/
  bool insert(const movie &x);

/** @brief elimina una pelicula  de un imdb 
 
@param[in] x elemento a borrar. 
@param[out] bool true si el borrado se ha podido realizar con exito
@post  el size() sera decrementado.

*/
  bool erase(const movie &x);

/** @brief operador de asignacion
@param[in] org imdb a copiar.
 Crea un imdb  duplicado exacto a org.
*/
  imdb & operator=( const imdb & org);

/** @brief busca una pelicula en imdb
@param[in] t nombre de la pelicula a buscar
@return un iterador que apunta a la primera pelicula con titulo t en la base de datos. Si no se encuentra devuelve
fin
*/
  const_iterator find(string & t);
  
   
/** @brief busca una pelicula en imdb
@param[in] t nombre de la pelicula a buscar
@return un iterador que apunta a la primera pelicula con titulo t en la base de datos y que haya sido lanzada el
año year. Si no se encuentra devuelve
fin
*/
const_iterator find(string & t, string & year );

/** @brief  calcular las k mejores películas según valoración
@param [in] k numero de peliculas 
@param [in] year: en el caso en que year sea igual al string por defecto nos devolverá las k mejores peliculas de
todos los tiempos, si year != string() nos devolverá las k mejoras películas de ese año.
@param[in,out] tk referencia al vector donde se almacenarán los datos

Es importante tener en cuenta que en IMDb el número mínimo de votos necesarios para que una película se encuentre entre las K mejores es de 25000. 
*/

void topK( int k, vector<movie> & tk, string  year=string() ) const;

/** @brief  peliculas por año

@param [in] year: año de lanzamiento de la pelicula
@param[in,out] rl conjunto de peliculas lanzadas durante ese año.
*/

void released (string & year, list<imdb::const_iterator>  & rl) const;


/************************************************************************/

class const_iterator { 
        public:
               const_iterator();
               const_iterator( const const_iterator & it);
               const movie & operator*();
               const_iterator & operator++();
	       const_iterator operator++(int);
               const_iterator & operator=(const const_iterator & it);
               bool operator==(const const_iterator & it) const;
               bool operator!=(const const_iterator & it) const;
        private:
	       friend class imdb;
               vector<movie>::const_iterator el_ite;
	       const imdb *ptr; // Puntero al imdb que apunta el_ite;
               };
	       

/** @brief  iterador a la primera pelicula en IMDb 
.
*/	     
   const_iterator begin() const;
   
/** @brief  iterador al fin de IMDB
.
*/	 
   const_iterator end() const;
 private:
  vector<movie> datos; // Donde se almacenan las peliculas.
  set< vector<movie>::const_iterator > borrados; //Lista de posiciones borradas

  
  bool cheq_rep( ) const;

};



#endif

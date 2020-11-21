#ifndef __priority_queue_H
#define __priority_queue_H

#include <assert.h>
#include <vector>

using namespace std;

/** prioirty_queue<T>

prioirty_queue<T>:: priority_queue, size, capacity, empty,  push, pop, top, operator=


Descripción


Una priority_queue (cola_con_prioridad) es un contenedor que proporciona un
subconjunto restringido de métodos (inserción de elementos además del borrado y consulta del elemento “mayor”). Se garantiza que el elemento “mayor” de la priority_queue se encuentra en el tope de la misma. Priority_queue no permite la iteración a través de sus elementos.


El número de elementos en el priority_queue puede variar dinámicamente; la gestión de la memoria es automática. 
 
**/


template<typename T>
class priority_queue {
 public:

/** @typedef typedef size_type
Hace referencia al tipo asociado al tamaño de la cola con prioridad

*/
typedef unsigned int size_type;

 /**
     @brief Constructor primitivo 
  */
  priority_queue(  );

/**
     @brief Constructor de copia.
     
     @param[in] org priority_queue que se copia
     
     Crea un priority_queue  duplicado exacto de org.
  */
  priority_queue( const priority_queue<T> & org);

/**
     @brief Destructor.
     Destruye el receptor liberando los recursos que ocupaba.
  */
  ~priority_queue();

/** @brief tamaño
    Devuelve el numero de elementos en el priority_queue
*/
  size_type size() const;

/** @brief vacia
   Chequea si el priority_queue esta vacio (size()==0)
*/
  bool empty() const;
/** @brief tope de la cola
Se garantiza que el elemento en el tope es el elemento más grande de la
cola con prioridad, según determina el criterio de comparación.
@pre empty() == false;
@return Devuelve una referencia al elemento en el tope del  priority_queue
*/
  const T & top( ) const;

/** @brief insertar
 Añade el elemento  al priority_queue
@param[in] t elemento a insertar en la cola
@post  el size() será incrementado en 1.

*/
  void push(const T & t);

/** @brief sacar
 Saca el elemento  al tope del priority_queue
@pre empty() == false;
@post  el size() será decrementado  en 1.

*/
  void pop( );

/** @brief operador de asignación
@param[in] org priority_queue a copiar.
 Crea un priority_queue  duplicado exacto de org.
*/
  priority_queue<T> & operator=( const priority_queue<T> & org);
  
   
 private:
  
  bool cheq_rep( ) const;
  
  #ifdef PQ_V1
    vector<T> V; // Donde se almacenan los datos.
    int mayor;  // mayor elemento del vector
  #else 
    #ifdef PQ_V2
      vector<T> V; // Vs Vector ordenado donde se almacenan los datos
    #endif
  #endif
 

};

#ifdef PQ_V1
  #include "priority_queue_v1.hxx"
#else
  #include "priority_queue_v2.hxx"
#endif

#endif

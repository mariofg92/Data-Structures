#ifndef __deque_H
#define __deque_H

#include <assert.h>
#include <iostream>

using namespace std;

/** deque<T>

deque<T>:: deque, size, capacity, empty, operator[], push_back, resize, operator=, insert, erase,

deque<T>::iterator::  iterator,operator*, operator++, operator=, operator==, operator!=

Descripci�n

Un deque es un contenedor que permite el acceso aleatorio (mediante valores enteoros) a los elementos, inserci�n y borrado en tiempo constante si se realiza al final del deque. Sin embargo, la inserci�n y el borrado son de orden lineal si se realizan en posiciones intermedias del deque. El n�mero de elementos en el deque puede variar din�micamente; la gesti�n de la memoria es autom�tica. 
 
**/


template<typename T>
class deque {
 public:
  typedef unsigned int size_type;

  deque( size_type n=0, const T & t = T()  );
  deque( const deque<T> & org);
  ~deque();
  size_type size() const;
  size_type capacity() const;
  bool empty() const;
  T & operator[](size_type n);
  const T & operator[ ](size_type n) const;
  void push_back(const T & t);
  void push_front(const T & t);
  void resize( size_type n, const T & t = T() );
  deque<T> & operator=( const deque<T> & org);
  
  // ITERADOR SOBRE VECTORES
  class iterator {
        public:
               iterator();
               iterator( const deque<T>::iterator & it);
               T & operator*();
               iterator & operator++();
               iterator & operator=(const deque<T>::iterator & it);
               bool operator==(const deque<T>::iterator & it) const;
               bool operator!=(const deque<T>::iterator & it) const;
        private:
               friend class deque;
               T * el_ite;
               deque<T> * el_deq;
               };
   iterator begin();
   iterator end();
   iterator insert(deque<T>::iterator & pos, const T & t);
   iterator erase(deque<T>::iterator & pos);
   
 private:
  T * datos;
  int inicio;  // Inicio de los datos
  int final;   // fin de los datos
  size_type cuantos;
  size_type capa;
  
  void cheq_rep( ) const { 
       cout << "Rep" << endl;
       cout << "datos " << datos << endl;
       cout << "inicio " << inicio << endl;
       cout << "final " << final << endl;
       cout << "cuantos " << cuantos << endl;
       cout << "capa " << capa << endl;
        for (int i =0; i< capa ; i++)
           cout << i << "\t" ;
	cout << endl;
       for (int i =0; i< capa ; i++)
           cout << datos[i] << "\t" ;
       cout << endl;
       }

};

#include "mi_deque.template"
#endif
 
                
 

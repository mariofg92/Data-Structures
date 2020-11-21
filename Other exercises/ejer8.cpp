#include <iostream>
#include <list>
#include "eje8.h"

using namespace std;

template <class T>
T vector_disperso<T>::SumaTotal(){
	T suma;

	suma = (tama - diferentes.size())*valor_def; //Sumatoria de los elementos por def

	for(map<int, T>::iterator ite=diferentes.begin(); ite != diferentes.end(); ite++){
		suma += *ite;
	}
	suma += *ite; //suma el ultimo elemento

	return suma;
}

/** @pre suponemos que los 2 vectores tienen el mismo valor por defecto */
template<class T>
vector_disperso<T> vector_disperso<T>::operator+(const vector_disperso<T> & v, const vector_disperso<T> & w){
	vector_disperso<T> aux;

	for(map<int, T>::iterator ite=diferentes.begin(); ite != diferentes.end(); ite++){
		if(v.diferentes.find((*ite).first) != v.diferentes.end()){ // si hay 2 elementos que deberían ir en la misma posición del vector 
			aux.insert()
		}
	}
}

template <class T>
void vector_disperso<T>::asigna(int i, const T & c){ //DUDA
	diferentes.insert(i, T);
}
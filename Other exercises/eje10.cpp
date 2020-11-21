#include <iostream>
#include <vector>
#include "eje10.h"

using namespace std;

template <class T>
bool vector_mejorado<T>::full(){
	return ocupados==(datos.size()-1) ? true : false;
}

template<class T>
typename vector_mejorado<T>::iterator & vector_mejorado<T>::iterator::operator++(){
	pos = (++pos)%(*elvector).size();
}
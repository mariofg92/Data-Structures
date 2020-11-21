//Es un vector circular
//Se desperdicia 1 elemento
#ifndef _EJE10_H_
#define _EJE10_H_

#include <iostream>
#include <vector>

using namespace std;

//Flata FA y IR
template <class T>
class vector_mejorado<T>{
private:
	int ocupados;
	int ini, fin;
	vector<T> datos;
public:
	bool full();

	class iterator{
	private:
		int pos;
		vecttor<T> *elvector;
	public:
		iterator & operator++();
	};
};

#endif
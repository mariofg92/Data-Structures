#ifndef _EJE_11_H_
#define _EJE_11_H_

#include <iostream>
#include <string>
#include <list>

using namespace std;

class palabras{
private:
	list<list<string> > datos;

public:
	void insertar(string dato);
};

#endif
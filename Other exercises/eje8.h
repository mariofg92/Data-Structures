#ifndef _VECTOR_DISPERSO_H_
#define _VECTOR_DISPERSO_H_

#include <iostream>
#include <list>

using namespace std;


/*F.A: Dado un objeto de tipo rep, f = {valor_def, map_diferentes}

	Sólo almacenamos en el map los elementos con valor distinto 
	a valor_def.

	fa: rep -> Vector Disperso
		f   -> f.valor_def, f.map_diferentes


  I.R: -Todo elemento del vector disperso que tenga un valor distinto de
  		valor_def irá almacenado en map_diferentes.
  		-Un elemento almacenado en map_diferentes no puede tener
  		valor_def

*/
template <class T>
class vector_disperso{
private:
	T valor_def;
	int tama;
	map<int, T> diferentes;

public:
	inline vector_disperso(); //FALTA
	void asigna(int i, const T & c);
	T SumaTotal();
	vector_disperso<T> operator+(const vector_disperso<T> & v, const vector_disperso<T> & w);
};

#endif
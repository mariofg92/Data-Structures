#include <iostream>
#include <string>
#include <list>
#include "eje11.h"

using namespace std;

void palabras::insertar(string dato){
	int longi = dato.size();
	bool posicion_encontrada = false;
	bool dato_repetido = false;
	list<list<string> >::iterator ite;

	for(ite=datos.begin(); ite != datos.end() && !posicion_encontrada; ite++){
		if((*ite).front().size() == longi)
			posicion_encontrada = true;
	}

	if(posicion_encontrada){
		list<string>::iterator elem;
		for(elem = (*ite).begin(); elem != (*ite).end() && !dato_repetido; elem++){
			if(*elem == dato) //Existe operator == en string??
				dato_repetido = true;
		}

		if(!dato_repetido){
			(*ite).push_back(dato);
		} // Si está repetido no hace nada
	}else{
		list<string> nueva(1, dato);
		datos.push_back(nueva);
	}
}
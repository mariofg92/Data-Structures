#include <iostream>
#include "eje5.h"

using namespace std;

template <class T>
void list<T>::Peinar(list<T> & l2){
	if (this -> ini==0 && l2.ini != 0){
		ini = l2.ini;
		l2.ini = 0;
	}else{
		Celda * auxthis, * auxl2, *temporal;
		auxthis = ini;
		auxl2 = l2.ini;

		while(auxthis != 0 && auxl2 != 0){
			temporal = auxl2 -> sig;
			auxl2->sig = auxthis->sig;
			auxthis->sig = auxl2;
			auxthis = auxl2->sig;
			if(auxthis != 0)
				auxl2 = temporal;
		}
		if(auxl2 != 0)
			auxl2->sig = temporal;
		l2.ini = 0;
	}
}

int main(){ //NO FUNCIONA FALTA DEFINIR ALGUNOS METODOS
	int aleer;
	list<int> l, l2;

	cout << "Introduce los enteros de la lista, separados por saltos de linea o espacios (Para terminar pulsa CRTL+D): " << endl;
	do{
		cin >> aleer;
		l.push_back(aleer);
	}
	while(!cin.eof());

	l.pop_back(); //extraer el eof de la pila

	cout << "Introduce los enteros de la lista, separados por saltos de linea o espacios (Para terminar pulsa CRTL+D): " << endl;
	do{
		cin >> aleer;
		l2.push_back(aleer);
	}
	while(!cin.eof());

	l2.pop_back(); //extraer el eof de la pila

	l.Peinar(l2);

	cout << endl << "El resultado final es: " << endl;
	for(list<int>::iterator ite=l.begin(); ite != l.end(); ite++){
		cout << *ite << " ";
	}

	cout << endl;
	
	return 0;
}
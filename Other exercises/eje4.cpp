#include <iostream>
#include <list>

using namespace std;

/** @brief Función que indica si un entero es primo o no.
	@param a Es el entero del cual queremos saber si es entero o no.
	@pre a no puede ser 0.
	@return True si a es primo, false en caso contrario.
*/
bool EsPrimo(int a){
	int veces_divisible = 0;

	for(int i=1; i <= a && veces_divisible <= 2; i++){
		if (a%i == 0)
			veces_divisible++;
	}

	return veces_divisible <= 2 ? true : false;
}

/** @brief Función que invierte el orden relativo de los elementos que sean
    numeros primos de una lista.
    @param l es la lista sobre la cual queremos hacer la inversión.
    @pre l no puede contener ningún elemento que sea 0.
    @return devuelve la lista con los elementos primos con su orden relaivo invertido.
*/
void InviertePrimos(list<int> &l){
	list<int>::iterator ite_izq;
	list<int>::iterator ite_dcha;
	ite_izq = l.begin();
	ite_dcha = l.end();
	int aux;

	while(ite_izq != ite_dcha){
		while(!EsPrimo(*ite_izq) && ite_izq != ite_dcha)
			ite_izq++;
		while(!EsPrimo(*ite_dcha) && ite_izq != ite_dcha)
			ite_dcha--;

		if(EsPrimo(*ite_izq) && EsPrimo(*ite_dcha)){
			aux = *ite_izq;
			*ite_izq = *ite_dcha;
			*ite_dcha = aux;
		}
	}
}

int main(){
	int aleer;
	list<int> l;

	cout << "Introduce los enteros de la lista, separados por saltos de linea o espacios (Para terminar pulsa CRTL+D): " << endl;
	do{
		cin >> aleer;
		l.push_back(aleer);
	}
	while(!cin.eof());

	l.pop_back(); //extraer el eof de la pila

	cout << endl << "El resultado final es: " << endl;

	InviertePrimos(l);

	cout << endl << "El resultado final es: " << endl;
	for(list<int>::iterator ite=l.begin(); ite != l.end(); ite++){
		cout << *ite << " ";
	}

	cout << endl;
	
	return 0;
}
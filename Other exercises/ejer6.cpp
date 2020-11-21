#include <iostream>
#include <list>

using namespace std;

/*En las listas solo invalida iteradores los metodos que borran elementos 
invalidando solo
los iteradores de los elementos que han sido borrados.*/

void BorrarV1(list<int> & l, int n){
	l.remove(n);
}

void BorrarV2(list<int> & l, int n){
	list<int>::iterator indi;

	for(indi=l.begin(); indi != v.end(); indi++){
		if(*indi == n)
			indi = l.erase(indi); // erase devuelve el iterador al siguiente
		//Asi no invalidamos el iterador

		indi++;
	}
}
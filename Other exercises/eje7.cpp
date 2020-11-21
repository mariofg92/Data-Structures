#include <iostream>
#include <list>

using namespace std;

/** @brief Función que mezcla 2 listas ordenadas en una única ordenada.
	@param l1 Lista 1.
	@param l2 Lista 2.
	@pre Las listas están ordenadas en orden creciente.
	@return Devuelve una nueva lista resultado de la mezcla ordenada de las 2 ordenadas.
*/
template <class T>
list<T> MezclaOrdenado(const list<T> & l1, const list<T> & l2){
	list<T> aux;
	list<T>::iterator ite1, ite2;
	ite1 = l1.begin();
	ite2 = l2.begin();

	while(ite1 != l1.end() && ite2 != l2.end()){
		if(*ite1 <= *ite2){
			aux.push_back(*ite1);
			ite1++;
		}else{
			aux.push_back(*ite2);
			ite2++;
		}
	}

	while(ite1 != l1.end()){ //El que ha llegado al ultimo elem es l2
		aux.push_back(*ite1);
		ite1++;
	}
	while(ite2 != l2.end()){ //El que ha llegado al ultimo elem es l1
		aux.push_back(*ite2);
		ite2++;
	}


	return aux;
}
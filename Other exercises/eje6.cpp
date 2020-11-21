#include <iostream>
#include <set> 

using namespace std;

/** @brief Función que determina si un cojunto está incluido dentro de otro.
	@param c1 Conjunto del cual se quiere saber si está incluido en c2.
	@param c2 Conjunto en el cual se quiere mirar si está incluido c1.
	@return True en caso de que c1 esté incluido en c2, false en caso contrario.
*/
bool Incluido(const set<int> & c1, const set<int> & c2){
	encontrado = true;
	set<int>::iterator ite= c1.begin();

	while(encontrado && ite != c1.end()){
		encontrado = (c2.find(*ite) != c2.end());
		ite++;
	}

	return encontrado;
}
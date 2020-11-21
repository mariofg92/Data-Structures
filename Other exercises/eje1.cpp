#include <iostream>
#include <stack>

using namespace std;

/** @brief Función que invierte una pila y elimina los elementos consecutivos repetidos.
	@pre la pila no está vacía.
	@param p la pila a invertir.
	@return la pila invertida con los elementos repetidos borrados.
*/
void Transforma(stack<int> &p){
	stack<int> aux;
	int copia;

	copia = p.top();
	aux.push(copia);
	p.pop();

	while(!p.empty()){
		if(p.top()!=copia){
			aux.push(p.top());
			copia = p.top();
		}
		p.pop();
	}

	p = aux;
}

int main(){
	int aleer;
	stack<int> p;

	cout << "Introduce los enteros de la pila, separados por saltos de linea o espacios (Para terminar pulsa CRTL+D): " << endl;
	do{
		cin >> aleer;
		p.push(aleer);
	}
	while(!cin.eof());

	p.pop(); //extraer el eof de la pila

	Transforma(p);
	
	cout << endl << "Tenga en cuenta que en la pila los elementos se almacenaron en orden inverso al introducido antes de realizar la transformacion";
	cout << endl << "El resultado de la transformacion es: " << endl;
	while(!p.empty()){
		cout << p.top() << " ";
		p.pop();
	}

	return 0;
}
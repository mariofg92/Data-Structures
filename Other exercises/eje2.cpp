#include <iostream>
#include <stack>

using namespace std;


/** @brief Función que busca un valor en una pila y en caso de estar la actualiza por uno nuevo.
	@pre La pila no está vacía.
	@param p la pila donde buscar el elemento viejo.
	@param viejo Elemento a sustituir en caso de que se halle en la pila.
	@param nuevo Elemento que reemplaza a viejo en caso de que viejo se encuentre en la pila.
	@return la pila con los elementos sustituidos.
*/
void Reemplazar(stack<int> &p, int nuevo, int viejo){
	stack<int> aux;
	while(!p.empty()){
		if(p.top()!=viejo){
			aux.push(p.top());
		}else{
			aux.push(nuevo);
		}

		p.pop();
	}

	/*Ahora ponemos p en el orden original de p con los 
	elementos ya sustituidos, lo hacemos reviertiendo aux */

	while(!aux.empty()){
		p.push(aux.top());
		aux.pop();
	}
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

	Reemplazar(p, 30, 2);
	
	cout << endl << "Tenga en cuenta que en la pila los elementos se almacenaron en orden inverso al introducido antes de realizar el reemplazo";
	cout << endl << "El resultado del reemplazo es: " << endl;
	while(!p.empty()){
		cout << p.top() << " ";
		p.pop();
	}

	return 0;
}
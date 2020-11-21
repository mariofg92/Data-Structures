#include <iostream>
#include <stack>

using namespace std;

/** @brief Función que busca si hay el mismo número de parentesis abiertos que cerrados en una pila.
	@pre La pila no está vacía.
	@param p la pila donde buscar el elemento viejo.
	@return True si hay el mismo numero de abiertos que de cerrado, false en otro caso.
*/
bool Parentesis(const stack<char> p){
	stack<char> aux = p;
	int contador=0;

	while(!aux.empty()){
		if(aux.top()=='('){
			contador++;
		}else if(aux.top()==')'){
			contador--;
		}

		aux.pop();
	}

	return contador==0 ? true : false;
}

int main(){
	char aleer;
	stack<char> p;

	cout << "Introduce los char de la pila, separados por saltos de linea o espacios (Para terminar pulsa CRTL+D): " << endl;
	do{
		cin >> aleer;
		p.push(aleer);
	}
	while(!cin.eof());

	p.pop(); //extraer el eof de la pila

	if(Parentesis(p)){
		cout << endl << "Hay el mismo numero de abiertos que de cerrados." << endl;
	}else{
		cout << endl << "No hay el mismo numero de abiertos que de cerrados." << endl;
	}
	
	return 0;
}
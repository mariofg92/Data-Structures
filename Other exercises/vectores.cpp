//Ejercicios 1, 2, 3, 4, 5
#include <iostream>
#include <vector>

using namespace std;

template <class T>
int VecesRepetidoV1(T elem, const vector<T> & v){
	int acumulador = 0;

	for(int i=0; i < v.size(); i++){
		if(v[i] == elem)
			acumulador++;
	}

	return acumulador;
}

template <class T>
int VecesRepetidoV2(T elem, const vector<T> & v){
	int acumulador = 0;

	for(vector<T>::iterator ite=v.begin(); ite != v.end(); ite++){
		if(*ite == elem){
			acumulador++;
		}
	}

	return acumulador;
}

template <class T>
bool Buscar(T elem, const vector<T> & v){
	return VecesRepetidoV2 != 0 ? true : false;
}

template <class T>
typename vector<T>::iterator Buscar(T elem, const vector<T> & v){
	bool encontrado = false;
	vector<T>::iterator ite;

	for(ite=v.begin(); ite != v.end() && !encontrado; ite++){
		if(*ite == elem){
			encontrado = true;
		}
	}

	return ite;
}

template <class T>
T EncuentraMenor(const vector<T> & v){
	T menor = *v.begin();
	vector<T>::iterator ite;

	for(ite=v.begin(); ite != v.end(); ite++){
		if(*ite < menor){
			menor = *ite;
		}
	}

	return menor;
}

template <class T>
typename vector<T>::iterator EncuentraMenor(const vector<T> & v){
	vector<T>::iterator menor = v.begin();
	vector<T>::iterator ite;

	for(ite=v.begin(); ite != v.end(); ite++){
		if(*ite < *menor){
			menor = ite;
		}
	}

	return menor;
}


int main(){
	vector<int> v1(3);
	//int v1[3];
	vector<bool> v2;
}
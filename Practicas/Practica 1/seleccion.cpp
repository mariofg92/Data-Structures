#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector> 
#include <string>
#include <time.h>
#include <algorithm>
#include <map>

#define POS_NULA -1 

using namespace std;

/* Lee un fichero  sobre un vector de string
 nf: nombre del fichero
 V: vector sobre el que se lee el fichero
 */
void lee_fichero( const char * nf, vector<string> & V) {
	ifstream fe;
	string s;
	fe.open(nf, ifstream::in);
	while ( !fe.eof() ){
		fe >> s;
		if (!fe.eof())
			V.push_back(s);
   	}
 	fe.close();
}


/* algoritmo de ordenacion por seleccion
 T: vector sobre el que se lee el fichero
 inicial: primera posicion desde la que buscar minimo 0
 final : posicion siguiente a la ultima para buscar (desde V[0] hasta V[fin-1])
 */
void ordena_seleccion(vector<string> & v, int inicio, int final) {
	string aux;

      	for (int i=inicio; i < final; i++) {
         	int min = i;
       		for (int c=i+1; c < final; c++){
			if (v[min] > v[c])
				min = c;
		}
		aux=v[i];
       		v[i] = v[min];
      		v[min] = aux;         	
      	}
}







int main() {

	vector<string> Dicc;
	vector<string> Q;
	int pos;
	clock_t start,end;
  
	vector<int> frecuencia;
	vector<string> palabra;

 	int contador =0;
 
 	lee_fichero("lema.txt", Dicc); // Ojo, el vector no esta ordenado!!!
 	//cout << Dicc.size() << " " << Dicc.capacity() << endl;
 
 	lee_fichero("quijote.txt", Q);
 	//cout << Q.size() << " " << Q.capacity() << endl;
 
 
	 ////////////////////////////////////////////////////
 	// ORDENACION POR INSERCION
 	////////////////////////////////////////////////////

	vector<string> aux;

	for (int tama = 100; tama < Dicc.size() ; tama+= 5000){
		aux = Q;
		start = clock();
		for (int iteraciones = 0; iteraciones < 2; iteraciones++)  // Numero de iteraciones se debe ajustar a cada caso
			ordena_seleccion(aux, 0, tama); 
		end= clock(); 
		double dif = end-start;
		cout << tama << " " << dif/(double) (CLOCKS_PER_SEC * 2.0) << endl;
 	}
 
}
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


/* algoritmo de ordenacion por insercion
 T: vector sobre el que se lee el fichero
 inicial: primera posicion desde la que buscar minimo 1
 final : posicion siguiente a la ultima para buscar (desde V[0] hasta V[fin-1])
 */
void insertSort(vector<string> & v, int inicial, int final) {
	int i, j;
	string aux;

      	for (int i=inicial; i<final; i++) {
         	aux=v[i];
       		for (j=i-1; j>=0 && v[j]>aux; j--){
            		v[j+1] = v[j];
            		v[j] = aux;
         	}
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
		for (int iteraciones = 0; iteraciones < 1000; iteraciones++)  // Numero de iteraciones se debe ajustar a cada caso
			insertSort(aux, 1, tama); 
		end= clock(); 
		double dif = end-start;
		cout << tama << " " << dif/(double) (CLOCKS_PER_SEC * 1000.0) << endl;
 	}
 
}

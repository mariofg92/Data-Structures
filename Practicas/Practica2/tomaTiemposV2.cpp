#include "priority_queue_v2.h"
#include <functional>
#include <string>
#include <vector>
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

// Ordena un vector de string en orden creciente 
//@param[in,out] V vector a ordenar
//
void ordenar(vector<string> & V, int tama){

 priority_queue<string> aux;
 int pos;

 for (int i=0;i<tama; i++)
   aux.push(V[i]);

 pos = tama-1;
 while (!aux.empty()) {
   V[pos]=aux.top();
   aux.pop();
   pos--;
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
		aux = Dicc;
		start = clock();
		for (int iteraciones = 0; iteraciones < 2; iteraciones++)  // Numero de iteraciones se debe ajustar a cada caso
			ordenar(aux, tama); 
		end= clock(); 
		double dif = end-start;
		cout << tama << " " << dif/(double) (CLOCKS_PER_SEC * 2.0) << endl;
 	}
 
}

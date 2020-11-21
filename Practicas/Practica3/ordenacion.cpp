#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector> 
#include <string>
#include <time.h>
#include <algorithm>
#include <map>
#include "priority_queue.h"

#define POS_NULA -1 

// practica 1
// ANALISIS DE EFICIENCIA DE ALGORITMOS
//

/* El objetivo de la practica es doble, por una lado ilustrar de forma empirica cómo se puede computar el tiempo de ejecución de un algoritmo
y, por otro, ilustrar como el uso de distintas estructuras de datos nos permite mejorar la eficiencia de los algoritmos
*/



using namespace std;
/* Lee un fichero  sobre un vector de string
 nf: nombre del fichero
 V: vector sobre el que se lee el fichero
 */
void lee_fichero( const char * nf, vector<string> & V) {
 ifstream fe;
  string s;
 fe.open(nf, ifstream::in);
 while ( !fe.eof() )
   { fe >> s;
     if (!fe.eof())
       V.push_back(s);
   }
 fe.close();
}



int main()
{
  vector<string> Dicc;
  vector<string> Q;
  int pos,tama;
  clock_t start,end;
  double dif;
  
  vector<int> frecuencia;
  vector<string> palabra;
  
  int contador =0;
  
  
  lee_fichero("quijote_breve.txt", Q);
  cout << Q.size() << " " << Q.capacity() << endl;
  
  
  tama = Q.size();
  priority_queue<string> aux;
  palabra.reserve(Q.size());
  
  cout << "Antes PQ "<< aux.size() << endl;
  start = clock();
  for (int i=0;i<Q.size();i++){
    aux.push(Q[i]);
  }
  cout << "Creada PQ "<< aux.size() << endl;
  while (!aux.empty()){
    palabra.push_back(aux.top());
    aux.pop();
  }
  end= clock(); 
  dif = end-start;
  cout << tama << " heap " << dif/CLOCKS_PER_SEC <<  endl;
  
  for (int i=0;i<100; i++)
    cout << palabra[i] << " ";
  cout << endl;
}










#include  "imdb.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* Convierte una cadena en un tipo de dato movie */

void parse_movie( string & s, movie & m){
 istringstream buffer(s);
 string aux;

 
 m.distr.clear();
 m.nombre.clear();
 m.otra.clear();
 m.anio.clear();
 
 buffer >> m.distr; 
 buffer >> m.votos; 
 buffer >> m.media; 
 buffer >> aux; 
 while (aux[0]!='(') {
   m.nombre+=aux+" ";
   buffer >> aux; 
 }
 m.anio = aux; 
 getline(buffer,m.otra);
}
  


  
/* Lee de un fichero un conjunto de movie y las almacena en un vector 
	Se elimina la primera linea del fichero 
*/
void leer_ratings_IMDb(string & nombre, vector<movie> & V){
    ifstream datos;
    string s;
    movie x;
   
    datos.open(nombre.c_str());
    if (datos.is_open()) {
      getline(datos,s);
      while (!datos.eof()) {
        getline(datos,s);
	if (s.size()!=0)  { 
          parse_movie(s,x);
          V.push_back(x);
        }
       }
    datos.close();
    }
  
    else { 
      cout << "Error de Lectura en " << nombre << endl;
    }
 }
  
  


int main(){

vector<movie> V;
string n_fichero("ej_rating.list");
imdb I;
imdb::const_iterator aux;
vector<movie>::iterator it;
int i;

leer_ratings_IMDb(n_fichero, V);
cout << "IMBd (modified file) Number of Movies "<<  V.size() << endl;
cout << "Distribution  Votes  Rank  Title"<< endl;
for (it= V.begin(); it!=V.end(); ++it)
 I.insert(*it); 

cout << "Tama " << I.size()<< endl;;
for (i=0, aux = I.begin(); aux!= I.end(); ++aux, i++)
  cout << i <<*aux << endl;
movie x;
x= *(I.begin());

cout << "Movie " << x << endl;
I.erase(x);


for (it = V.begin(); it< V.end();  it+=2){
  I.erase(*it);
}

cout << "Tama " << I.size()<< endl;;

cout << "Tama " << I.size()<< endl;;
for (i=0, aux = I.begin(); aux!= I.end(); ++aux, i++)
  cout << i <<*aux << endl;

return 0;
}



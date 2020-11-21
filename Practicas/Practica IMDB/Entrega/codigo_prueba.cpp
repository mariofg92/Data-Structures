#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/* Clase para gestionar las peliculas */

struct movie{
 string distr;
 int votos;  
 float media;
 string anio;
 string nombre;
 string otra;
 };
 

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
  
/* Sobrecarga del operador << para movie */
 ostream & operator<<( ostream & s, const movie &x) {
  s<< x.distr<< " " << x.votos << " " << x.media << " "  << x.nombre << " " << x.anio << "  "<< x.otra;
  return s;
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
string n_fichero("P5_file_rating.list");


int i;

leer_ratings_IMDb(n_fichero, V);
cout << "IMBd (modified file) Number of Movies "<<  V.size() << endl;
cout << "Distribution  Votes  Rank  Title"<< endl;
for (vector<movie>::iterator it= V.begin(); it!=V.end(); ++it)
cout << *it << endl;
 
return 0;

}


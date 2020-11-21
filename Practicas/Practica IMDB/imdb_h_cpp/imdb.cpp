#include "imdb.h"
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;
/*****************************************

Funcion de Abstraccion:
AF: Rep => Abs
   
  dada I vector<movie> datos; // Donde se almacenan las peliculas.
  list< vector<movie>::iterator > borrados //posiciones borradas
  
  (datos, borrados) ==> imbd
  
Un objeto abstracto, IMDb, se instancia en la clase imdb:


 I.datos == imdb, donde las posiciones en borradas no son películas válidas

Invariante de la Representación:


Propiedades que debe cumplir cualquier objeto 

- i representa a una posición valida (pelicula en imdb) sii el datos.begin()+i no pertenece a la
lista de borrados.

- I.size() = I.imdb.size()-borrados.size(); 
 
- Hay que tener en cuenta que el nombre de la película se puede repetir
(aunque en el mismo año sólo habría una con un mismo tìtulo).

*/

/* @brief Sobrecarga del operador << para movie */
 ostream & operator<<( ostream & s, const movie &x) {
  s<< x.distr<< " " << x.votos << " " << x.media << " "  << x.nombre << " " << x.anio << "  "<< x.otra;
  return s;
  }
  
/* @brief Sobrecarga del operador < para movie */
bool  operator<(const movie & x,const movie m)  {
 if (x.nombre < m.nombre) return true;
 else if (x.nombre == m.nombre) return (x.anio < m.anio);
 return false;
 }
 
 
/* @brief Sobrecarga del operador == para movie */
bool  operator==(const movie & x,const movie m)  {
 if ( (x.nombre == m.nombre)&&  (x.anio ==  m.anio)) return true;
 return false;
 }
 
/********************************************************************
Metodos de IMDB
********************************************************************/
struct functor_nota{
	bool operator() (movie a, movie b)	{
		if(a.media > b.media)
			return true;
		else
			return false;
	}
};

imdb::imdb(){}

imdb::imdb( const imdb & org){
	datos = org.datos;
	borrados = org.borrados; 
}

~imdb(){
	//Ya gestionado por las clases vector y set
}

imdb::size_type imdb::size() const
{

  return datos.size()-borrados.size();
}

bool empty() const{
	if (size()==0)
		return true;
	else
		return false;
}

bool insert(const movie &x){
	int tama = datos.size();
	if (borrados.size > 0){
		datos[borrados.begin()] = x;
		borrados.erase(borrados.begin());
		return true;			
	}else{
		datos.push_back(datos.end(), x);
		//vector.push_back(x); se podría hacer pero no reservaría mas espacio en mem
		if (tama < datos.size)
			return true;
		else
			return false;
	}
	
}
bool erase(const movie &x){ //terminar
	
	vector<movie>::iterator it;
	
	for(it = datos.begin(); it != datos.end(); it++) 	
		if(*it == x){
			borrados.insert(it);
			return true;
		}
	return false;
}

imdb & operator=( const imdb & org){
	imdb imdb_aux;
	imdb_aux.datos = org.datos;
	imdb_aux.borrados = org.borrados;
	set< vector<movie>::const_iterator >::iterator it;
	for (it = imdb_aux.borrados.begin(); it != imdb_aux.borrados.end(); it++){
		imdb_aux.datos.erase(*it);
	}
	imdb_aux.borrados.clear();

	return imdb_aux;
}

const_iterator find(string & t){
	imdb::const_iterator it;
	for(it = this->begin();it != this->end(); it++){
		if((*it).nombre == t && !(borrados.find(it))
			return it; 
	}
	return this->end();
}

imdb::const_iterator imdb::find(const string & t, const string & year ){
	imdb::const_iterator it;
	for(it = this->begin();it != this->end(); it++){
		if((*it).nombre == t && (*it).anio == year && !(borrados.find(it))
			return it; 
	}
	return this->end();
}

void imdb::topK( int k, vector<movie> & tk, string year ) const {
	priority_queue<movie, vector<movie>, functor_nota> pq;
	imdb::const_iterator it;
	
	for(it = (*this).begin();it != (*this).end(); it++){
		if(year == string() && !(borrados.find(it)){
			if(pq.size() < k && (*it).votos >= 25000)
				pq.push((*it));
			else if((*it).media > (pq.top()).media && (*it).votos >= 25000){
				pq.pop();
				pq.push((*it));
			}
		}else{
			if(pq.size() < k && (*it).votos >= 25000 && year == (*it).anio && !(borrados.find(it))
				pq.push((*it));
			else if((*it).media > (pq.top()).media && (*it).votos >= 25000 && year == (*it).anio && !(borrados.find(it)){
				pq.pop();
				pq.push((*it));
			}
		}
	}
	while(pq.size() > 0){
		tk.push_back(pq.top());
		pq.pop();
	}
}

void imdb::released(string & year, list< imdb::const_iterator>  & rl) const{
	imdb::const_iterator it;
	for(it = this.begin() ;it != this->end(); it++){
		if((*it).anio == year && !(borrados.find(it))
			rl.push_back(it);
	}
}

bool imdb::cheq_rep() const{
	for(imdb::const_iterator i = this->begin(); i != this->end(); i++){
		for (imdb::const_iterator j = this->begin(); j != this->end(); j++){
			if((*i).nombre == (*j).nombre && (*i).anio == (*j).anio && !(borrados.find(it))
				return false;
		}		
	}
	if (borrados.size() > datos.size())
		return false

	return true;
}

/********************************************************************
Metodos de IMDB::CONST_ITERATOR
********************************************************************/



imdb::const_iterator::const_iterator()
{
ptr = 0;
}

imdb::const_iterator::const_iterator(const imdb::const_iterator& it)
{
el_ite = it.el_ite;
ptr=it.ptr;
}

const movie & operator*(){
	return *el_ite;
}

const_iterator & operator++(){
	vector<movie>::const_iterator aux;
	aux = el_ite + 1;
	return aux;
}

const_iterator operator++(int i){
	vector<movie>::const_iterator aux;
	aux = el_ite + i;
	return aux;
}

const_iterator & operator=(const const_iterator & it){
	const_iterator aux;
	aux.el_ite = it.el_ite;
	aux.ptr=it.ptr;

	return aux;
}

bool operator==(const const_iterator & it) const{
	if (ptr == it.ptr && el_ite == it.el_ite)
		return true;
	else
		return false;
}

bool operator!=(const const_iterator & it) const{
	return !(*this == it);
}

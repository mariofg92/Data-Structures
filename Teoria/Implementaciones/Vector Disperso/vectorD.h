#ifndef __VECTORDISPERSO_H
#define __VECTORDISPERSO_H

#include <vector>
#include <utility> // clase pair


using namespace std;
template <typename TIPO>
class vectorD
{
public:
class iteratorD; // iterador sobre elementos no nulos
class iterator; // iterador sobre todos los elementos del vector
class const_iteratorD; //const iterador sobre elementos no nulos
class const_iterator; // const iterador sobre todos los elementos del vector

//////////// constructores //////////////
  		
vectorD( const TIPO & t= TIPO() );
// constructor por defecto.
      	
vectorD(  const vectorD<TIPO> & b);    	
/** constructor primitivo que hace una copia del vector disperso b. */

vectorD( int numcomp, const TIPO & t = TIPO() );
/** constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero. */
 
////////////// destructor ////////////  	
~vectorD();


/////////// Consultores ////////////
int size() const;
// Devuelve el tamaño del vectorD

TIPO v_default( ) const;

bool empty();
// el vectorD esta vacio

////////  MODIFICADORES //////////////////////
void assign(int p, const TIPO & t);
// Cambia a el valor t el valor de la posicion p-esima del vector. No modifica el size del vector

void push_back( const TIPO & t);
// Inserta un elemento al final del vectorD. Aumenta en 1 el tamanio

void pop_back(  );
// elimina un elemento del vectorD. Disminuye en 1 el tamanio

void clear(); 
// elimina todos los elementos del vectorD. Tamanio es 0

iterator erase ( iterator  it);
// Elimina (quita del vector) el elemento apuntado por it, decrementa el size en 1. 
// Devuelve el iterador al elemento siguiente al que se ha borrado.

iterator insert(iterator it, const TIPO & x);
// inserta un elemento x delante del iterador it. Devuelve un iterador al elemento insertado

void resize(int s);
// cambia el tama~no del vector a "s" elementos. Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
//amplia la capacidad del vector asignando a todos los nuevos elementos el valor nulo. 

/////////////// operadores ///////////////////


vectorD & operator= (const vectorD & x);
// operador de asignacion


const TIPO & operator[](int c) const  ;
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes*/

const TIPO & at(int c) const  ;
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes
Hace comprobacion de rango */

bool operator==( const vectorD & x);
/** devuelve verdadero si tienen los mismos elementos y false en caso contrario */

bool operator!=( const vectorD & x);
/** devuelve verdadero si no tienen los mismos elementos y false en caso contrario */
////////////////////////////////////////




iterator begin();
/** iterador (read) al inicio sobre todos los elementos del vector */

iterator end();
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector */

const_iterator begin() const;
/** iterador  (read) inicio sobre todos los elementos del vector */

const_iterator end() const;
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector */


iteratorD beginD(); 
/** iterador  (read) inicio sobre elementos no nulos */

iteratorD endD();
/** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */

const_iteratorD beginD() const; 
/** iterador  (read) inicio sobre elementos no nulos */

const_iteratorD endD() const;
/** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */


private: // parte  privada

    vector< pair<int,TIPO> > vd; // vector que aloja el vector disperso (solo los != valor nulo)
    int n_ele; // numero de elementos totals
    TIPO v_nulo; //valor nulo del vector
 
    /* FA e IR*/
    /* FA(rep): rep -- > vector
      (vd,n_ele,v_nulo):
      vd=[ (a,v1), (b,v2), ..., (n,vn) ]
      n_ele = M
      v_nulo = t
      --------->
      pos: 0 1 2 ... a-1 a ... x .... b....  ... n-1 n n+1 ..... M-1
      val: t t t ....t  v1 ... t .... v2 ..  ... t   vn t  ......t
      */
     
    int checkRep();
    /* IR :
      IR(rep): rep ---> bool
     (vd,n_ele,v_nulo) :
      0 <= vd.size() < n_ele;
      vd[i].second != v_nulo, para todo i = 0, ..., vd.size()-1;
      vd[i].first >=0, para todo i = 0, ..., vd.size()-1;
      vd[i].first < vd[j].first si i<j
     */
    
  /* ITERADORES SOBRE VECTOR DISPERSO */
public:
  
  
  public:
class iteratorD{
  public:
    friend class vectorD;
    friend class vectorD<TIPO>::const_iteratorD;
    
    iteratorD() {} 
    iteratorD(const iteratorD & d) : ite(d.ite) {}
    const pair<int,TIPO> & operator *(  ) { return (*ite);}
    iteratorD & operator++( ) {++ite; return *this;}  
    iteratorD operator++(int ) {iteratorD tmp(*this); ++ite; return tmp;}  
    bool operator == (const iteratorD & d) {return ite == d.ite;}
    bool operator != (const iteratorD & d) {return ite != d.ite; }
    
  private:
    
    typename vector<pair<int,TIPO> >::iterator ite;
};

class iterator{
  public:
    friend class vectorD;
    
    
    iterator() {} 
    iterator(const iterator & d)  {
     ite_rep=d.ite_rep; i_vect = d.i_vect;
    }
    const TIPO & operator *(  ) {
     
      if (ite_rep == (*el_vect).vd.end()) { 
	return (*el_vect).v_nulo;
      } else if (i_vect != (*ite_rep).first) {
	   return (*el_vect).v_nulo;
      } else return (*ite_rep).second;
    }
    iterator & operator++( ) {
       if ((ite_rep == (*el_vect).vd.end()) || (i_vect != (*ite_rep).first)) 
	 i_vect++;
       else {i_vect++; ++ite_rep;}
       return *this;
    }  
    iterator operator++(int ) {iterator tmp(*this); ++(*this); return tmp;}  
    bool operator == (const iterator & d) {return i_vect == d.i_vect;}
    bool operator != (const iterator & d) {return i_vect != d.i_vect; }
    iterator & operator=(const iterator & d) {
      i_vect = d.i_vect;
      ite_rep = d.ite_rep;
      el_vect = d.el_vect;
      return *this;
    }
  private:
    int i_vect; // indice sobre el vector abstracto
    typename vector<pair<int,TIPO> >::iterator ite_rep; //iterador a la representacion
     vectorD *el_vect; // ptro al vector para obtener el valor nulo del vector
    /* FA e IR*/
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k
      ite_rep = p 
      el_vect = v
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */
   
      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep): 
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
       */
       
};

class const_iteratorD{
  public:
    friend class vectorD;
    
    const_iteratorD() {} 
    const_iteratorD(const const_iteratorD & d) : ite(d.ite) {}
     const_iteratorD(const iteratorD & d) : ite(d.ite) {} // Conversion de iterator a const_iterator
    const pair<int,TIPO> & operator *(  ) { return (*ite);}
    const_iteratorD & operator++( ) {++ite; return *this;}  
    const_iteratorD operator++(int ) {const_iteratorD tmp(*this); ++ite; return tmp;}  
    bool operator == (const const_iteratorD & d) {return ite == d.ite;}
    bool operator != (const const_iteratorD & d) {return ite != d.ite; }
    const_iteratorD & operator= (const const_iteratorD & d) { ite = d.ite; return *this;}
 
  private:
    typename vector<pair<int,TIPO> >::const_iterator ite;
};

class const_iterator{
  public:
    friend class vectorD;
    
    const_iterator() {} 
    const_iterator(const const_iterator & d)  {
     ite_rep=d.ite_rep; i_vect = d.i_vect;
    }
    const_iterator(const iterator & d) { // Conversion de iterator a const_iterator
      i_vect = d.i_vect;
      ite_rep = d.ite_rep;
      el_vect = d.el_vect;
    } 
    const TIPO &  operator *(  ) { 
       if (ite_rep == (*el_vect).vd.end()) { 
	return (*el_vect).v_nulo;
      } else if (i_vect != (*ite_rep).first) {
	   return (*el_vect).v_nulo;
      } else return (*ite_rep).second;
    }
    const_iterator & operator++( ) {
        if ((ite_rep == (*el_vect).vd.end()) || (i_vect != (*ite_rep).first))  
	 i_vect++;
       else {i_vect++; ++ite_rep;}
       return *this;
    }  
    const_iterator operator++(int ) {const_iterator tmp(*this); ++(*this); return tmp;}  
    bool operator == (const const_iterator & d) {return i_vect == d.i_vect;}
    bool operator != (const const_iterator & d) {return i_vect != d.i_vect; }
    
  private:
    int i_vect; // indice sobre el vector abstracto
    typename vector<pair<int,TIPO> >::const_iterator ite_rep; //iterador a la representacion
    const vectorD *el_vect; // ptro al vector para obtener el valor nulo del vector
    /* FA e IR*/
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k
      ite_rep = p 
      el_vect = v
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */
   
      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep): 
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
       */
       
};


};

#include "vectorD.template"

#endif

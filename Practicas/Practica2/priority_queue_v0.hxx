
/** 
Funcion de Abstraccion:
AF: Rep => Abs
   
  dada qq=(vector<T>  V, int mayor) ==> priority_queue PQ;
  
Un objeto abstracto, Q, se instancia en la cola con prioridad pq teniendo:

 pq.V[mayor] = PQ.top()
 
Invariante de la Representación:

Propiedades que debe cumplir cualquier objeto priority_queue
pq.size() == pq.V.size();

Para todo i, 0 <= i < pq.V.size() se cumple
pq.V[mayor] >= pq.V[i];

*/

/********************************************************
Métodos Públicos
*********************************************************/

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T>::priority_queue(  ){

}

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T>::priority_queue( const priority_queue<T> & org){

}

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T>::~priority_queue() {

}


/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T> & priority_queue<T>::operator=( const priority_queue<T> & org)
{
}
  

/**
 @todo implementa esta función
*/
template <typename T>
typename priority_queue<T>::size_type priority_queue<T>::size() const {


}

/**
 @todo implementa esta función
*/
template <typename T>
bool priority_queue<T>::empty() const{

}

/**
 @todo implementa esta función
*/
template <typename T>
const T & priority_queue<T>::top( ) const{

}

/**
 @todo implementa esta función
*/
template <typename T>
void priority_queue<T>::push(const T & t){ 

}

/**
 @todo implementa esta función
*/
template <typename T>
void priority_queue<T>::pop( ){

}

/********************************************************
Métodos Privados
*********************************************************/

template <typename T>
bool priority_queue<T>::cheq_rep( ) const {  

 for (int i=0;i<V.size(); i++)
   if (V[i] > V[mayor])
     return false;
 return true;
}



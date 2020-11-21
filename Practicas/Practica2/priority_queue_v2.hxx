
/** 
Funcion de Abstraccion:
AF: Rep => Abs

 dada qq=(vector<T> V) ==> priority_queue PQ;

Un objeto abstracto, Q, se instancia en la cola con prioridad pq teniendo:

 pq.V[0] = PQ.top()

 
Invariante de la Representación:

 pq.size() == pq.V.size();

Para todo i, 0 <= i < pq.V.si
*/

/********************************************************
Métodos Públicos
*********************************************************/

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T>::priority_queue(  ){
	mayor = 0;
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
priority_queue<T> & priority_queue<T>::operator=( const priority_queue<T> & org){
}
  

/**
 @todo implementa esta función
*/
template <typename T>
typename priority_queue<T>::size_type priority_queue<T>::size() const {
	return V.size();
}

/**
 @todo implementa esta función
*/
template <typename T>
bool priority_queue<T>::empty() const{
	if (V.size() == 0)
		return true;
	else
		return false;
}

/**
 @todo implementa esta función
*/
template <typename T>
const T & priority_queue<T>::top( ) const{
	if(!empty()){
		assert(cheq_rep());
		return V[0];
	}
}

/**
 @todo implementa esta función
*/
template <typename T>
void priority_queue<T>::push(const T & t){ 
	if(empty()) // Si está vacio lo añade directamente
		V.push_back(t);
	else{
		int i= V.size() -1;
		while(i>0 && V[i]<t){
			i--;
		}
		if(V[i] > t)
			V.insert(V.begin()+i+1,t);
		else
			V.insert(V.begin()+i,t);
	}
}

/**
 @todo implementa esta función
*/
template <typename T>
void priority_queue<T>::pop( ){
	if(!empty())
		V.erase(V.begin());
}

/********************************************************
Métodos Privados
*********************************************************/

template <typename T>
bool priority_queue<T>::cheq_rep( ) const {  

 for (int i=0;i<V.size(); i++)
   if (V[i] > V[0])
     return false;
 return true;
}



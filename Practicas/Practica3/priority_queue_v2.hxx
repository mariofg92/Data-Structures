
/** 
Funcion de Abstraccion:
AF: Rep => Abs
   
  dada qq=(vector<T>  V) ==> priority_queue PQ;
  
Un objeto abstracto, Q, se instancia en la cola con prioridad pq teniendo:

 pq.V.back() = PQ.top()
 
Invariante de la Representación:

Propiedades que debe cumplir cualquier objeto priority_queue
pq.size() == pq.V.size();

Para todo i,j, 0 <= i,j < pq.V.size() se cumple
pq.V[i] <= pq.V[j] si i<j;

*/

/********************************************************
Métodos Públicos
*********************************************************/

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T>::priority_queue()
{
}

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T>::priority_queue( const priority_queue<T> & org)
{
  //V = org.V;
}

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T>::~priority_queue()
{
}

/**
 @todo implementa esta función
*/
template <typename T>
typename priority_queue<T>::size_type priority_queue<T>::size() const
{
  return V.size();
}

/**
 @todo implementa esta función
*/
template <typename T>
bool priority_queue<T>::empty() const
{
  return V.empty();
}

/**
 @todo implementa esta función
*/
template <typename T>
const T & priority_queue<T>::top() const
{
  return V.back();
}

/**
 @todo implementa esta función
*/
template <typename T>
void priority_queue<T>::push(const T & t)
{ 
  int i= 0;
  while (i<V.size() && V[i]<t)
    i++;
  
  V.insert(V.begin()+i, t);
}

/**
 @todo implementa esta función
*/
template <typename T>
void priority_queue<T>::pop()
{
  V.pop_back();
}

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T> & priority_queue<T>::operator=(const priority_queue<T> & org)
{
  if (this != &org)
    V = org.V;
  
  return *this;
}
  
/********************************************************
Métodos Privados
*********************************************************/

template <typename T>
bool priority_queue<T>::cheq_rep( ) const
{
  for (int i=0;i<V.size()-1; i++)
    if (V[i] > V[i+1])
      return false;
  
  return true;
}

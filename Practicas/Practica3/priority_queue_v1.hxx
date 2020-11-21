
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
priority_queue<T>::priority_queue(  )
{
  mayor = -1;
}

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T>::priority_queue( const priority_queue<T> & org)
{
  //mayor = org.mayor;
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
  return V[mayor];
}

/**
 @todo implementa esta función
*/
template <typename T>
void priority_queue<T>::push(const T & t)
{ 
  V.push_back(t);
  if (mayor==-1)
    mayor=0;
  else
    if (V[V.size()-1]> V[mayor])
      mayor = V.size()-1;
}

/**
 @todo implementa esta función
*/
template <typename T>
void priority_queue<T>::pop()
{
  int p_mayor;
  //V.erase(V.begin()+mayor);
  V[mayor] = V.back();
  V.erase(V.begin()+V.size()-1);
  
  if (!V.empty()) {
    p_mayor = 0;
    for (int i=1; i<V.size(); i++)
      if (V[i] > V[p_mayor])
	p_mayor = i;
  }
  else
    p_mayor = -1;
  
  mayor = p_mayor;
}

/**
 @todo implementa esta función
*/
template <typename T>
priority_queue<T> & priority_queue<T>::operator=(const priority_queue<T> & org)
{
  if (this != &org) {
    mayor = org.mayor;
    V = org.V;
  }
  
  return *this;
}
  
/********************************************************
Métodos Privados
*********************************************************/

template <typename T>
bool priority_queue<T>::cheq_rep() const
{
  if (V.empty())
    if (mayor==-1)
      return true;
    else return false;
    
  for (int i=0;i<V.size(); i++)
    if (V[i] > V[mayor])
      return false;
    
  return true;
}



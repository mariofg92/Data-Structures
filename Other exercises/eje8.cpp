#include <iostream>
#include <list>

using namespace std;

template <class T>
void ImprimeInverso(const list<T> & l){ 
	for(list<T>::reverse_iterator ite = l.rbegin(); ite != l.rend(); i++)
		cout << *ite << " ";

}
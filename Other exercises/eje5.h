#ifndef __EJE5_H_
#define __EJE5_H_

#include <iostream>

using namespace std;

template <class T>

class list
{
	private:
		struct Celda{
			Celda * sig;
			T ele;
		};
		Celda * ini;

	public:
		void Peinar(list<T> & l2);
};

#endif

template <class T>
bool Orden(typename bintree<T>::node n){
	if(!n.left().null() && (*(n.left()) >= *n || !Orden(n.left())))
		return false;
	if(!n.rgth().null() && (*(!n.right().null() && (*(n.right())) <= *n || !orden(n.right()))))
		return false;

	return true;
}

template <class T>
int Altura(typename bintree<T>::node n){
	if(!n.null())
		return max(Altura(n.left()), Altura(n.rigth()))+1;

	return 0;
}

template<class T>
bool Equilibrado(typename bintree<T>::node n){
	if(abs(Altura(n.left())), Altura(nright())) && Equilibrado(n.left()) && Equilibrado(n.right()))
		return true;

	return false;
}

template <class T>
bool es_avl(const bintree<T> & arb){
	return Orden(arb.root()) && Equilibrado(arb.root());
}

//SEGUNDA FORMA

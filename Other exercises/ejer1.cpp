void CompletarRecursivo(bintree<char> & arb, typename bintree<char>::node & nodo, int & pos_cadena, const string & cad){
	typename bintree<char>::node hijo_izq, hijo_dcha;

		hijo_dcha = arb.insert_right(nodo, cad[pos_cad]);
		pos_cad--;
		if(cad[pos_cad+1]=='*' || cad[pos_cad+1]=='+' || cad[pos_cad+1]=='-' || cad[pos_cad+1]=='/'){
			CompletarRecursivo(arb, hijo_dcha, pos_cad, cad);
		}
		
		hijo_izq = arb.insert_left(nodo, cad[pos_cad]);
		pos_cad--;
		if(cad[pos_cad+1]=='*' || cad[pos_cad+1]=='+' || cad[pos_cad+1]=='-' || cad[pos_cad+1]=='/'){
			CompletarRecursivo(arb, hijo_izq, pos_cad, cad);
		}

}

bintree<char> PostFijo(string expr){
	bintree<char> arb;
	pos_cad = expr.size()-1;
	arb.setroot(expr[pos_cad]);
	pos_cad--;

	CompletarRecursivo(arb, arb.root, pos_cad, expr);

	return arb;
}
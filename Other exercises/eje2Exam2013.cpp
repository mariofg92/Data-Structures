//Eje2 exam febrero 2013

class Datos{
private:
	vector <Persona> personas;
	map <string, vector<Persona>::iterator> > dnis; //  o en lugar de iterador int de la pos
	multimap <string, vector<Persona>::iterator> > apellidos; //o en lugar de un iterador int de la pos
public:
	void insertar(const Persona & p);
};

void datos::insertar(const Persona & p){
	personas.push_back(p);
	pair <string, int> par(p.getDNI(), personas.size()-1);
	dnis.insert(par);
	par.first=p.GetApellidos();
	apellidos.insert(par);
}


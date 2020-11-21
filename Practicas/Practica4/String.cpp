#include "String.h"


using namespace std;

bool String::cheq_rep() const {
	if (letras[letras.size()-1]!='\0'){ //tmb se puede usar letras.back()
		return false;
	}
	for (int i=0; i < letras.size()-1; i++){
		if (letras[i]=='\0')
			return false;
	}
	return true;

}

String::String(){
	letras.push_back('\0');
	assert(cheq_rep());
}

String::String( const String & org){
	letras = org.letras;
	assert(cheq_rep());
}
String::~String(){
	
}
String::size_type String::length() const{
	return letras.size()-1;
}

bool String::empty() const{
	if (letras.size() == 0)
		return true;
	else
		return false;
}

void String::insert(int pos, const String &str){
    vector<char>::iterator aux;
    aux = letras.begin() + pos;
    for (int i =0; i < str.length() && aux < letras.end() && str.letras[i]!='\0'; i++){ //Segunda condicion evita violación de segmento.
        if (str.letras[i]!='\0')
          letras.insert(aux, str.letras[i]);
        aux++;
    }
    //assert(cheq_rep());
}

void String::erase(int pos, int n){ //Problema con iteradores
    vector<char>::iterator ini = letras.begin() + pos;
    vector<char>::iterator fin = ini + n;
    if (pos + n < length())
        letras.erase(ini, fin);
    assert(cheq_rep());
}

String & String::operator=(const String & org){
    if (this != &org) {
        letras = org.letras;
    }
    
    return *this;
    
}

char String::operator[](int pos) const{
    if (pos > 0 && pos < length())
        return letras[pos];
    else
        return ' ';
}

void String::resize(int n, char c){
    letras.pop_back();
    letras.resize(n, c);
    letras.push_back('\0');
    assert(cheq_rep());
}

String String::operator+(const String &s) const{
    String c(*this);
    c.letras.pop_back();
    for (int i=0; i <= s.length(); i++){ // Tambien añade el \0 al final
        c.letras.push_back(s.letras[i]);
    }
    //c.letras.insert(c.letras.end(), s.letras.size(), s);
    
    return c;
}

int String::find(const String& str, int pos) const{
    bool encontrado = false;
    int pos_en= String::npos;
    
    for (int i=pos; i < length() && !encontrado; i++){
        for (int j=0; i+j < length() && j < str.length() && letras[i+j] == str.letras[j]; j++){
            if (j == (str.length()-1) && letras[i+j] == str.letras[j]){
                encontrado = true;
                pos_en = i;
            }
        }
    }
    
    return pos_en;
    
}

void String::replace(int pos, int n, const String &str){
    
    if (pos < length()){ //Si pos es mayor que length() no hace las funciones de operator+
        int i, j=0;
        for (i=pos; i >= 0 && i <= n && i < length() && j < str.length(); i++){
            letras[i]=str.letras[j];
            j++;
        }
        while (i <= n && j < str.length()){ // Al ser j <= str.length() tambien inserta el \0 al final
            letras.insert(letras.begin() + i, str.letras[j]);
            j++;
            i++;
        }
        if (letras.back()!='\0')
            letras.push_back('\0');
    
        assert(cheq_rep());
    }
}

String String::substr(int pos, int n) const{ //revisar
    String c;
    
    c.letras.clear();
    for (int i=pos; i>=0 && i < length() && i <= n; i++){
        c.letras.push_back(letras[i]);
        if (i==pos){ //Bucle parche
            c.letras.push_back(letras[i]);
        }
        //cout << i << "    " << letras[i] << endl; //prueba
    }

    c.letras.push_back('\0');
    assert(c.cheq_rep());
    
    return c;
}
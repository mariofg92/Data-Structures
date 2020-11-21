#ifndef __String_H
#define __String_H

#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

/** \class String String.h

String::String, operator=, length, empty, operator[], resize, operator+, insert, erase, find, replace, substr


Descripcion


Un String es una secuencia de carateres 

El número de elementos en el String puede variar dinamicamente; la gestion de la memoria es automatica. 
 
**/

class String {
 public:

/** @typedef typedef size_type
Hace referencia al tipo asociado al tamaño del String

*/
typedef unsigned int size_type;

 /**
     @brief Constructor primitivo 
  */
  String(  );

/**
     @brief Constructor de copia.
     
     @param[in] org String que se copia
     
     Crea un String  duplicado exacto de org.
  */
  String( const String & org);

/**
     @brief Destructor.
     Destruye el receptor liberando los recursos que ocupaba.
  */
  ~String();

/** @brief tamaño
 * @return delvuelve el numero de elementos del String
    Devuelve el numero de elementos en el String
*/
  size_type length() const;

/** @brief determina si la cadena esta vacia
 * @return devuelve true si esta vacia y false en caso contrario
   Chequea si el String esta vacio (size()==0)
*/
  bool empty() const;
  

/** @brief Inserta un subString dentro de un String
 Inserta str en la posicion pos del String
@param[in] pos posicion en la que se inserta el elemento
@param[in] str elemento a insertar en el String
@post  el size() sera incrementado en str.length().
*/
  void insert(int pos, const String &str);

/** @brief elimina un subString de un String 
 borra caracteres de un String
@param[in] pos posicion a partir de la que se eliminan los mensajes
@param[in] n número de caracteres a borrar. Si pos+n>size() se borra desde pos hasta el final
@post  el size() sera decrementado en n caracteres.

*/
  void erase(int pos, int n);

/** @brief operador de asignacion
@param[in] org String a copiar.
 Crea un String  duplicado exacto a org.
*/
  String & operator=( const String & org);

/** @brief Devuelve un caracter del String
@param[in] pos posicion del caracter. Si no esta entre 0 y size() se devuelve ''
@return el caracter de la posicion pos
Devuelve el caracter que se encuentra en la posicion pos
*/
  char operator[](int pos) const;

/** @brief Redimensiona el String
@param[in] n el numero de caracteres con el que debe quedar el String
@param[in] c el caracter con el que se rellenara, si es necesario
Redimensiona el String de forma que su tamaño sea n. Si n fuera mayor que size() se rellena con el caracter c
*/
  void resize(int n, char c=' ');
  
/** @brief Concatena dos Strings
@param[in] s el String con el que se concatena
@return el String concatenado con el String s
Concatena dos Strings
*/ 
  String operator+(const String &s) const;

/** @brief Busca un String a partir de una posicion
@param[in] str String que va a buscar
@param[in] pos posicion a partir de la cual se realiza la busqueda 
@return devuelve la posicion en la que aparece str por primera vez. String::npos si no aparece
Devuelve la posicion a partir de pos en la que aparece str
*/   
  int find(const String& str, int pos = 0 ) const;

/** @brief Reemplaza una parte de la cadena con otra
@param[in] pos posicion a partir de la cual se realiza la sustitucion
@param[in] n numero de caracteres a sustituir
@param[in] str String que va a ser insertada
Reemplaza un subString de longitud n a partir de la posicion pos, con el String str
*/   
  void replace(int pos, int n, const String &str);

/** @brief Extrae un subString de un String
@param[in] pos posicion a partir de la cual se extraeran los caracteres
@param[in] n numero de caracteres a extraer 
@return devuelve un subString con longitud n o los caracteres que queden a partir de pos
Devuelve un subString a partir de una posicion dada
*/  
  String substr(int pos, int n) const;
  
  static const int npos=-1;
   
 private:
  vector<char> letras; // Donde se almacenan los datos.
  
  bool cheq_rep( ) const;

};

//const int String::npos = -1;

#endif

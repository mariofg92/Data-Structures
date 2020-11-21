#include <iostream>
#include <map>

using namespace std;

/*FA:
El banco se compone de cuentas y de movimientos donde Cuentas[i] es
el saldo de la cuenta nº. 
movimientos[i] = almacena la referencia a la cuneta y la cantidad referentes al movimiento
nºi

IR:
	-El identificador de cada cuenta debe ser positivo.
	-El identificador de cada movimiento debe ser positivo.
*/
class Banco{
	private:
		map<int, double> cuentas;
		map<int, pair<int, double> movimientos;

		/*Alternativa a movimientos:
		 map <int, pair<map<int,double >::iterator, double> movimientos; */

}
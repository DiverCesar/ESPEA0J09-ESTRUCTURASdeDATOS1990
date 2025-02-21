#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
	//Declaración de un unordered_map con clave y valor de tipo int
	unordered_map<int, int> cuadrado;
	
	//Insertar elementos (clave: número, valor: su cuadrado)
	cuadrado[1] = 1;
	cuadrado[2] = 4;
	cuadrado[3] = 9;
	cuadrado[4] = 16;
	
	//Acceder a un valor usando una clave
	cout << "El cuadrado 3 es: " << cuadrado[3] << endl;
	
	//Recorrer e imprimir los elementos del unrodered_map
	cout << "Valores almacenados: " << endl;
	for(const auto& par : cuadrado){
		cout << "Numero: " << par.first << " - Cuadrado: " << par.second << endl;
	}
	return 0;
}

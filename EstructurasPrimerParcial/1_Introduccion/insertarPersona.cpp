#include <iostream>
#include <string>
using namespace std;

typedef struct persona {
	string nombre;
	string apellido;
	int edad;
};

void mostrar(persona);
persona guardar();

int main ()
{
	persona p;
	p = guardar ();
	mostrar(p);
	cout << ("Ci");
}

void mostrar(persona per) {
	cout << "Nombre: " <<per.nombre << endl;
	cout << "Apellido: " <<per.apellido << endl;
	cout << "Edad: " <<per.edad << endl; 
}

persona guardar() {
	persona per;
	cout << "Ingrese el nombre: ";
	getline(cin, per.nombre);
	cout <<"Ingrese el Apellido: ";
	getline(cin, per.apellido);
	cout << "Ingrese la edad: ";
	cin >> per.edad;
	return per;
}




#include <iostream>
#include <string>

using namespace std;

//DECLARAR EL TDA

typedef struct persona{
	string nombre; //ATRIBUTOS
	int edad;
};

void mostrar(persona);
persona guardar();

int main(){
	persona p;
	p = guardar();
	mostrar(p);
}

void mostrar(persona per){
	cout<<"Nombre: "<<per.nombre<<endl;
	cout<<"Edad: "<<per.edad;
}

persona guardar(){
	persona per;
	cout<<"Ingresar el nombre: ";
	getline(cin, per.nombre);
	cout<<"Ingresar la edad: ";cin>>per.edad;
	return per;
}

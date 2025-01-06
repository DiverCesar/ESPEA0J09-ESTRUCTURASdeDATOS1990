//ARRAYS DE ARREGLOS
#include <iostream>
#include <string>

using namespace std;

int main(){
	struct datosPersona
	{
		string nombre; //ATRIBUTOS
		int edad;
		float nota;};
		
	datosPersona *persona = new datosPersona[4];
	
	for (int i=0; i<4; i++)
	{
		cout<<"Dime el nombre de la persona: "<<i+1<<endl;
		cin>>persona[i].nombre;
		cout<<"Dime la edad de la persona: "<<i+1<<endl;
		cin>>persona[i].edad;
		cout<<"Dime la nota de la persona: "<<i+1<<endl;
		cin>>persona[i].nota;
	}
	
	for (int i=0; i<4; i++)
	{
		cout<<"El nombre de la persona "<<i+1<<" es "<<persona[i].nombre<<", de edad "<<persona[i].edad<<" y su nota es "<<persona[i].nota<<endl;
	}
}

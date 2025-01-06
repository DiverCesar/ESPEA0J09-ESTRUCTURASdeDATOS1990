#include <iostream>
#include <string>

using namespace std;

int main()
{
	struct datosPersona
	{
		string nombre;
		int edad;
		float nota;
	};
	
	datosPersona *persona = new datosPersona[50];
	
	for (int i=0; i<4; i++)
	{
		cout <<"Dime el nombre de la persona: "<< i <<endl;
		cin >> persona[i].nombre;
		cout <<"Dime la nota de la persona: "<< i <<endl;
		cin >> persona[i].nota;
		cout <<"Dime la edad de la persona: "<< i <<endl;
		cin >> persona[i].edad;
	}
	for (int i=0; i<4; i++)
	{
	cout <<"La persona  es: " <<persona[i].nombre << " / Nota: "<<persona[i].nota <<" / Edad: "<<persona[i].edad << endl;
	}
}

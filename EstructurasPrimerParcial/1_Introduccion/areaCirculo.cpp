#include <iostream>
using namespace std;
//Declarar el TDA
struct Circulo{
	float radio;//Atributos
};
//Definir Interfaz(OPERACIONES)

void calcularArea(Circulo&);//ENTRADA TDA CIRCULO POR REFERENCIA

int main()
{
	Circulo c;
	calcularArea(c);
	
}
//DECLARAR LA INTERFAZ (DESARROLLO)
void calcularArea(Circulo&){
	Circulo circulo;//instanciar
	cout<<"INGRESE RADIO: ";
	cin>>circulo.radio;
	cout<<"AREA: "<<3.1416*((circulo.radio)*(circulo.radio));
}

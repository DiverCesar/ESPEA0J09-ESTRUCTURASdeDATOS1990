#include <iostream>

using namespace std;

//DECLARAR EL TDA

struct Circulo{
	float radio; //ATRIBUTOS
};

//DEFINIR INTERFAZ (OPERACIONES)

void calcularArea(Circulo&); //ENTRADA TDA CIRCULO POR REFERENCIA

int main(){
	Circulo c;
	calcularArea(c);
}

//DECLARAR LA INTERFAZ (DESARROLLO)

void calcularArea(Circulo&){
	Circulo circulo; //INSTANCIAR
	cout<<"INGRESE RADIO: ";cin>>circulo.radio;
	cout<<"AREA: "<<3.1416*((circulo.radio)*(circulo.radio));
}

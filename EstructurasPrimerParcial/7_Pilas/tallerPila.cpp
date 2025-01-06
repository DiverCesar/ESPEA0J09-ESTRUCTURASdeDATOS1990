#include <iostream>
#include <conio.h>
#include <stdlib.h>//nuevo

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&, int); //Prototipo
int main(){
	Nodo *pila=NULL;
	int n1, n2;
	cout<<"\nDigite un numero: ";
	cin>>n1;
	agregarPila(pila, n1);
	cout<<"\nDigite otro numero: ";
	cin>>n2;
	agregarPila(pila, n2);
	getch();
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
	cout<<"\nElemento\t"<<n<<"\tagregado a Pila correctamente";
}

#include <iostream>
#include <conio.h>
#include <stdlib.h> //nuevo

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo
void agregarPila(Nodo *&, int);

int main(){
	Nodo *pila = NULL;
	int maximo,enesimo,i;
	cout<<"\nDigite el numero de elementos: ";cin>>maximo;
	for(i=0; i<maximo; i++){
		cout<<"\nIngrese el elemento "<<i+1<<" a la pila: ";cin>>enesimo;
		agregarPila(pila,enesimo);
	}
	getch();
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
	cout<<"\nElemento\t"<<n<<"\tagregado a PILA correctamente"<<endl;
}

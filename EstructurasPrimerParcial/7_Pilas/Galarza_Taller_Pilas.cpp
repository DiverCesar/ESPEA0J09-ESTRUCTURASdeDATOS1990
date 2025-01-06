#include <iostream>
#include <conio.h>
#include <stdlib.h>// nuevo
#include <time.h>

using namespace std;
struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&, int);//Prototipo
void sacarPila(Nodo *&, int &);
int numeroRandom();

int main(){
	Nodo *pila=NULL;
	int dato;
	
	cout<<"Ingrese numero de datos: ";
	cin>>dato;
	srand(time(NULL));

	for(int i=1; i <= dato; i++){
		int dato = numeroRandom();
		agregarPila(pila, dato);
		cout<<"\nElemento "<< dato <<" agregado a pila correctamente";
	}
	cout<<endl<<endl;
	
	while(pila!=NULL){
		sacarPila(pila, dato);
		if(pila != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<" . ";
		}
	}
	getch();
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	n = (rand()%50);
	Nodo *nuevo_nodo = new Nodo();//stdlib
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux=pila;
	n=aux->dato;
	pila=aux->siguiente;
	delete aux;
}

// llenar datos con n datos, y que se llenen randomicos 1-50
int numeroRandom() {
    return rand() % 50 + 1;
}

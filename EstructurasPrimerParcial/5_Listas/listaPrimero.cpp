#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};
//Prototipos
void insertarLista(Nodo *&,int);

int main(){
	Nodo *lista=NULL;
	int dato;
	cout<<"Digite un numero: ";cin>>dato;
	insertarLista(lista,dato);
	
	getch();
	return 0;
}

void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato=n;
	Nodo*aux1=lista;
	Nodo*aux2;
	while(aux1!=NULL){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista == aux1){
		lista
	}
}

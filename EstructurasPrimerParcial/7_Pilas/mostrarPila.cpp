#include <iostream>
#include <conio.h>
#include <stdlib.h> //nuevo

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo
void menu();
void insertarPila(Nodo *&, int);
void mostrarPila(Nodo *);
Nodo *lista = NULL;

int main(){
	menu();
	getch();
	return 0;
}

void menu(){
	int opcion, dato;
	do{
		cout<<"PILAS"<<endl;
		cout<<"1.Insertar"<<endl;
		cout<<"2.Mostrar"<<endl;
		cout<<"3.Salir"<<endl;
		cout<<"Eliga una opcion:";cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Ingrese el dato n: ";cin>>dato;
				insertarPila(lista,dato);
				cout<<endl;
				system("pause");
				break;
			case 2:
				mostrarPila(lista);
				cout<<endl;
				system("pause");
				break;
			case 3:
				cout<<endl;
				system("pause");
				break;
		}system("cls");
	}while(opcion!=3);
}

void insertarPila(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo;
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1!=NULL)&&(aux1->dato<n)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}else{
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	cout<<"Ingreso de valor "<<n<<" exitoso.";
}

void mostrarPila(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual!=NULL){
		cout<<actual->dato<<"->";
		actual = actual->siguiente;
	}
}

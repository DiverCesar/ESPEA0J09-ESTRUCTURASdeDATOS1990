#include <conio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
}*primero, *ultimo;

void insertarNodo();
void desplegarCola();
void buscarNodo();
void modificarNodo();
void eliminarNodo();

void insertarNodo(){
	nodo* nuevo = new nodo();
	cout << "Ingrese el dato del nuevo nodo: ";
	cin >> nuevo -> dato;
	
	if(primero == NULL){
		primero = nuevo;
		primero -> siguiente = NULL;
		ultimo = primero;
	}else{
		ultimo -> siguiente = nuevo;
		nuevo -> siguiente = NULL;
		ultimo = nuevo;
	}
	cout << endl << "Nodo (" << nuevo -> dato << ") ingresado" << endl << endl;
}

void desplegarCola(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero != NULL){
		while(actual != NULL){
			cout << endl << " " << actual -> dato;
			actual = actual -> siguiente;
		}
	}else{
		cout << endl << "La cola se encuentra vacia";
	}
	cout << endl << endl;
}

void buscarNodo(){
	nodo* actual=new nodo();
	actual=primero;
	bool encontrado=false;
	int nodoBuscado=0;
	cout<<"Ingrese el dato del nodo a buscar: ";
	cin>>nodoBuscado;
	if(primero!=NULL){
		while(actual!=NULL && encontrado !=true){
			if(actual->dato==nodoBuscado){
				cout<<"\nNodo con el dato ("<<nodoBuscado<<") encontrado"<< endl << endl;;
				encontrado=true;
			}
			actual=actual->siguiente;
		}
		if(!encontrado){
			cout<<"\nNodo NO Encontrado"<< endl << endl;;
		}
	}else{
		cout<<endl<<"La cola se encuentra vacia"<<endl<<endl;
	}
}

void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "Ingrese el dato del nodo a buscar para modificar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual != NULL && encontrado != true){
			if(actual -> dato == nodoBuscado){
				cout << "\nNodo con el dato (" << nodoBuscado << ") encontrado\n";
				cout << "\nIngrese el nuevo dato para este nodo: ";
				cin >> actual -> dato;
				cout << "\nNodo modificado a dato (" << actual -> dato <<")"<< endl << endl;;
				encontrado = true;
			}
			actual=actual->siguiente;
		}
		if(!encontrado){
			cout << "\nNodo NO encontrado"<< endl << endl;;
		}		
	}else{
		cout << endl << "La cola se encuentra vacia" << endl << endl;
	}
}

void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado  = false;
	int nodoBuscado = 0;
	cout << "Ingrese el dato del nodo a buscar para eliminar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual != NULL && encontrado != true){
			if (actual -> dato == nodoBuscado){
				cout << "\nNodo con el dato (" << nodoBuscado << ") encontrado"<< endl;
				if(actual == primero){
					primero = primero -> siguiente;
				} else if(actual == ultimo){
					anterior -> siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior -> siguiente = actual -> siguiente;
				}
				cout << "\nNodo eliminado de la lista"<< endl << endl;;
				encontrado = true;
			}
			anterior = actual;
			actual = actual -> siguiente;
		}
		if(!encontrado){
			cout << "\nNodo NO encontrado"<< endl << endl;;
		}
	}else{
		cout << endl << "La cola se encuentra vacia" << endl << endl;
	}
}

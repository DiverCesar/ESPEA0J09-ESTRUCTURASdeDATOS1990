#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

//Prototipos
void insertarLista(Nodo *&, int );
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int );
void eliminarElemento(Nodo *&, int);
void eliminarLista(Nodo *&);

void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1!=NULL)&&(aux1->dato<n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	cout<<"\nEl dato "<<n<<" se ha insertado a la lista\n";
}

void buscarLista(Nodo *lista, int n){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual!=NULL)&&(actual->dato<n)){
		if(actual->dato!=n){
			actual = actual->siguiente;
		}
	}
	
	if((actual!=NULL)&&(actual->dato == n)){
		cout<<"El dato "<<n<<" se ha encontrado en la lista";
	}	
	else{
		cout<<"El dato "<<n<<" no se encontra en la lista";
	}
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual!=NULL){
		cout<<actual->dato<<"->";
		actual = actual -> siguiente;
	}
}

void eliminarLista(Nodo *&lista){
	Nodo *aux;
	
	while(lista!=NULL){
		aux = lista;
		lista = lista -> siguiente;
		delete aux;
	}
	
	cout<<"La lista ha sido eliminada";	
}

void eliminarElemento(Nodo *&lista, int num){
	Nodo *actual = new Nodo();
	actual = lista;
	
	Nodo *anterior = new Nodo();
	anterior = NULL;

	while((actual!=NULL)&&(actual->dato<num)){
			anterior = actual;
			actual = actual -> siguiente;
	}
	
	if((actual!=NULL)&&(actual->dato == num)){
		if(anterior == NULL){
			lista = actual->siguiente;
		}
		else{
			anterior->siguiente = actual->siguiente;
		}
		delete actual;	
		cout<<"El dato "<<num<<" se ha eliminado de la lista";
	}	
	else{
		cout<<"El dato "<<num<<" no se encontra en la lista";	
	}
}

#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo
void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);
Nodo *lista = NULL;

int main(){
	menu();
	getch();
	return 0;
}

void menu(){
	int opcion,dato,datoBuscar;
	
	do{
		cout<<"\t MENU: \n";
		cout<<"1. Insertar elementos a la lista \n";
		cout<<"2. Mostrar elementos de la lista \n";
		cout<<"3. Buscar elementos de la lista \n";
		cout<<"4. Salir \n";
		cout<<"OPCION: ";cin>>opcion;
		switch(opcion){
			case 1: cout<<"\nDigite un numero: ";cin>>dato;
				insertarLista(lista,dato);
				cout<<endl;
				system("pause");
				break;
				
			case 2: mostrarLista(lista);
				cout<<endl;
				system("pause");
				break;
				
			case 3: cout<<"\nDigite numero a buscar: ";cin>>datoBuscar;
				buscarLista(lista,datoBuscar);
				cout<<endl;
				system("pause");
				break;
			
		}system("cls");
	}while (opcion != 4);
}

void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato=n;
	
	Nodo*aux1=lista;
	Nodo*aux2;
	
	while((aux1!=NULL)&&(aux1->dato<n)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente=nuevo_nodo;
	}
	
	nuevo_nodo->siguiente=aux1;
	cout<<"\n Elemento "<<n<<" insertado a la lista de forma adecuada";
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<actual->dato<<"->";
		actual=actual->siguiente;
	}
}

void buscarLista(Nodo *lista, int n){
	Nodo *actual = new Nodo();
	actual = lista;
	int i=1;
	
	while((actual!=NULL)&&(actual->dato<n)){
		if(actual->dato!=n){
			actual=actual->siguiente;
			cout<<"Busqueda "<<i++<<endl;
		}
	}
	
	if((actual!=NULL)&&(actual->dato==n)){
		cout<<"El dato "<<n<<" se ha encontrado en la lista";
	}	
	else{
		cout<<"El dato "<<n<<" no se encontra en la lista";
	}
}

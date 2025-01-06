#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

//Prototipos
void menu();
void setColor(int);
void insertarLista(Nodo *&, int );
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int );
void eliminarElemento(Nodo *&, int);
void eliminarLista(Nodo *&);
Nodo *lista = NULL;


int main(){
	setColor(11);
	cout<<"*._______________________________.*"<<"    _   "<<endl;
	cout<<"|         CESAR GALARZA           |"<<"   (o<  "<<endl;
	cout<<"|           NRC 1990              |"<<"   //)  "<<endl;
	cout<<"|  Lista de prueba de escritorio  |"<<"   V_/_ "<<endl;
	cout<<"|        28 -> 37 -> 96 ->        |"<<endl;
	cout<<"*._______________________________.*"<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	menu();
	getch();
	return 0;
}

void menu(){
	int opcion, dato, num, datoBuscar;
	do{
		setColor(2);
		cout<<"*.____________________________________________.*"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|################ MENU LISTAS #################|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|----------------------------------------------|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|### 1.Insertar nodo ###|### 4.Eliminar nodo ##|"<<endl;
		cout<<"|### 2.Mostrar lista ###|### 5.Borrar lista ###|"<<endl;
		cout<<"|### 3.Buscar nodo #####|### 6.Salir ##########|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"*.____________________________________________.*"<<endl;
		cout<<"\nIngrese su opcion: "; cin>>opcion;
		switch(opcion ){
			case 1: 
				cout<<"\nDigite un numero: ";
				cin>>dato;
				insertarLista(lista, dato);
				cout<<endl;
				system("pause");
				break;
			
			case 2:
				cout<<endl;
				mostrarLista(lista);
				cout<<endl;
				system("pause");
				break;
				
			case 3:
				cout<<"\nDigite numero a buscar: ";
				cin>>datoBuscar;
				buscarLista(lista, datoBuscar);
				cout<<endl;
				system("pause");
				break;
			case 4:
				cout<<"\nDigite numero a eliminar: ";
				cin>>dato;
				eliminarElemento(lista, dato);
				cout<<endl;
				system("pause");
				break;
				
			case 5:
				cout<<endl;
				eliminarLista(lista);
 				cout <<"\nLista eliminada";
 				system("pause");
 				break;
		}
		system("cls");
	}while(opcion !=6);
}

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

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

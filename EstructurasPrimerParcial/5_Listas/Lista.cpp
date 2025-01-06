#include <iostream>
#include <conio.h>
#include "Libreria_Datos.h"

using namespace std;
 struct Nodo{
 	int dato;
 	Nodo *siguiente;
 }; //Prototipos
 
 void menu();
 void insertarLista(Nodo *&, int);
 void mostrarLista(Nodo *);
 void buscarLista(Nodo *, int);
 void eliminarNodo(Nodo *&, int);
 void eliminarLista(Nodo *&);
 Nodo *lista = NULL;
 
 int main()
 {
 	Datos::imprimirDatos();
 	menu();
 	
 	getch();
 	return 0;
 }
 
 void menu(){
 	int opcion, dato;
 	do{
 		cout << "\t Menu; \n";
 		cout << "1. Insertar elementos de la lista \n";
 		cout << "2. Mostrar elementos de la lista \n";
 		cout << "3. Buscar elementos en la lista \n";
 		cout << "4. Eliminar nodo de la lista \n";
 		cout << "5. Eliminar lista \n";
 		cout << "6. Salir \n";
 		cout << "Opcion ";
 		cin >> opcion;
 		switch(opcion){
 			case 1: cout << "\n Digite un numero ";
 				cin >> dato;
 				insertarLista(lista, dato);
 				cout << "\n";
 				system("pause");
 				break;
 			case 2: mostrarLista(lista);
 				cout << "\n";
 				system("pause");
 				break;
 			case 3: cout << "\n Digite un numero a buscar ";
 					cin >> dato;
 					buscarLista(lista, dato);
 					cout <<"\n";
 					system("pause");
 					break;
 			case 4: cout << "\n Digite el numero a eliminar ";
 					cin >> dato;
 					eliminarNodo(lista, dato);
 					cout << "\n";
 					system("pause");
 					break;
 			case 5: eliminarLista(lista);
 					cout << "\n Lista eliminada ";
 					system("pause");
 					break;
		 }
		 system("cls");
	 }while(opcion != 6);
 }
 void insertarLista(Nodo *&lista, int n){
 	Nodo *nuevo_nodo = new Nodo();
 	nuevo_nodo -> dato = n;
 	Nodo *aux1 = lista;
 	Nodo *aux2;
 	
	while(aux1 != NULL){
 		aux2 = aux1;
 		aux1 = aux1 -> siguiente;
	 }
	 if(lista == aux1){
	 	lista = nuevo_nodo;
	 } else{
	 	aux2 -> siguiente = nuevo_nodo;
	 }
	 nuevo_nodo -> siguiente = aux1;
	 cout << "\n Elemento " << n << " Insertardo a la lista de forma adecuada \n";
}
	 
void mostrarLista(Nodo *lista){
	Nodo *actual = lista;
	
	while(actual != NULL){
		cout << actual -> dato << "->";
		actual = actual -> siguiente;
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

void eliminarNodo(Nodo *&, int n){
	if (lista == NULL) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }

    Nodo *aux_borrar = lista;
    Nodo *anterior = NULL;

    while ((aux_borrar != NULL) && (aux_borrar -> dato != n)) {
        anterior = aux_borrar;
        aux_borrar = aux_borrar -> siguiente;
    }

    if (aux_borrar == NULL) {
        cout << "\nElemento " << n << " no encontrado en la lista.\n";
    } else {
        if (anterior == NULL) {
            lista = lista -> siguiente;
        } else {
            anterior -> siguiente = aux_borrar -> siguiente;
        }
        delete aux_borrar;
        cout << "\nNodo con el elemento " << n << " eliminado correctamente.\n";
    }
}

void eliminarLista(Nodo *&lista){
	Nodo *aux;
	while(lista != NULL){
		aux = lista;
		lista = lista -> siguiente;
		delete aux;
	}
	cout << "\n La lista ha sido eliminada";
} 
 

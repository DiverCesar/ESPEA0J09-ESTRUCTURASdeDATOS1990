// Integrantes: Gabriel Báez; Cesar Galarza

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

void menu();
Nodo *CrearNodo(int, Nodo *);
void insertarNodo(Nodo *&,int, Nodo *);
void mostrarArbol (Nodo *,int);
bool busqueda (Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);
Nodo *arbol = NULL;

int main() {
	menu();
	getch();
	return 0;
}

void menu(){
	int dato, opcion,contador=0;
	do{
		cout<<"\t .:MENU:."<<endl;
		cout<<"1. INSERTAR UN NUEVO NODO"<<endl;
		cout<<"2. MOSTRAR ARBOL"<<endl;
		cout<<"3. BUSCAR ELEMENTO ARBOL"<<endl;
		cout<<"4. RECORRER ARBOL EN PREORDEN"<<endl;
		cout<<"5. RECORRER ARBOL EN INORDEN"<<endl;
		cout<<"6. RECORRER ARBOL EN POSTORDEN"<<endl;
		cout<<"7. ELIMINAR NODO DEL ARBOL"<<endl;
		cout<<"8. SALIR"<<endl;
		cout<<"Opcion:";
		cin>>opcion;
		switch(opcion){
			case 1: 
				cout<<"\nDIGITE UN NUMERO\t";
				cin>>dato;
				insertarNodo(arbol,dato,NULL);
				cout<<"\n";
				system("pause");
				break;
			case 2:
				cout<<"MOSTRANDO EL ARBOL\n\n";
				mostrarArbol(arbol,contador);
				cout<<"\n";
				system("pause");
				break;
			case 3:
				cout<<"\n DIGITE ELEMENTO A BUSCAR EN ARBOL\n\n";
				cin>>dato;
				if(busqueda (arbol,dato)==true){
					cout<<"\nELEMENTO\t" <<dato<<"\tENCONTRADO EN ARBOL\n";
				}
				else{
					cout<<"\n ELEMENTO NO ENCONTRADO EN ARBOL\n";
				}
				cout<<"\n";
				system("pause");
				break;
			case 4:
				cout<<"\nRECORRIDO EN PREORDEN:";
				preOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 5:
				cout<<"\nRECORRIDO EN INORDEN:\t";
				inOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 6:
				cout<<"\nRECORRIDO EN POSTORDEN:\t";
				postOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 7: 
				cout<<"DIGITE EL NUMERO A ELIMINAR: ";
				cin>>dato;
				eliminar(arbol, dato);
				cout<<"\n\n";
				system("pause");
				break;
			}
			system("cls");
	}while(opcion !=8);
}
	
Nodo *CrearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo =new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->padre=padre;
	return nuevo_nodo;
}
	
//FUNCION INSERTAR ELEMENTOS EN EL ARBOL
void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
	if(arbol==NULL){
		Nodo *nuevo_nodo=CrearNodo(n,padre);
		arbol=nuevo_nodo;
		}		
	else{
		int valorRaiz= arbol->dato;
		if(n<valorRaiz){
			insertarNodo(arbol->izq,n,arbol);
		}
	else{
		insertarNodo(arbol->der,n,arbol);
		} 
	}
}

void mostrarArbol (Nodo *arbol, int cont){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
		cout<<" ";
	}
	cout<<arbol->dato<<endl;
	mostrarArbol(arbol->izq, cont+1);
	}
}

bool busqueda (Nodo *arbol,int n){
	if(arbol== NULL){
	return false;
	}
	else if(arbol->dato==n){
	return true;
	}
	else if(n<arbol->dato){
		return busqueda(arbol->izq,n);
	}
	else{
		return busqueda(arbol->der,n);
	}
}

void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(Nodo *arbol){
	if(arbol ==NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<"_";
		inOrden(arbol->der);
	}
}

void postOrden(Nodo *arbol){
	if(arbol ==NULL){
		return;
	}
	else{
		postOrden (arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<"_";
	}
}	

void eliminar(Nodo *arbol, int n){
	if(arbol==NULL){
		return;
	}
	else if(n<arbol->dato){
		eliminar(arbol->izq,n);
	}
	else if (n>arbol->dato){
		eliminar(arbol->der,n);
	}
	else{
		eliminarNodo(arbol);
	}
}

Nodo *minimo(Nodo *arbol){
	if (arbol == NULL){
		return NULL;
	}
	if (arbol->izq){
		return minimo(arbol->izq);
	}
	else{
		return arbol;
	}
}

void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if (arbol->padre){
		//arbol->padre asignarle nuevo hijo
		if(arbol->dato==arbol->padre->izq->dato){
			arbol->padre->izq= nuevoNodo;
		}
		else if (arbol->dato==arbol->padre->der->dato){
			arbol->padre->der=nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre= arbol->padre;
	}
}

void destruirNodo(Nodo *nodo){
	nodo->izq=NULL;
	nodo->der=NULL;
	delete nodo;
}

void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor=minimo(nodoEliminar->der);
		nodoEliminar->dato=menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}

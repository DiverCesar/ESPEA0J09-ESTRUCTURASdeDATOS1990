#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Libreria_1_Lista.h"


using namespace std;

//Prototipos
void menu();
void setColor(int);
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
				cout<<"\n Digite un numero: ";
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
 				cout << "\n Lista eliminada ";
 				system("pause");
 				break;
		}
		system("cls");
	}while(opcion !=6);
}


void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

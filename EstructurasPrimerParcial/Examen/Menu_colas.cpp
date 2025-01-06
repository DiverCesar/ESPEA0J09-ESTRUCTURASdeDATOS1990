#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Libreria_1_Colas.h"


using namespace std;

//Prototipos
void menu();
void setColor(int);


int main(){
	setColor(11);
	cout<<"*._______________________________.*"<<"    _   "<<endl;
	cout<<"|         CESAR GALARZA           |"<<"   (o<  "<<endl;
	cout<<"|           NRC 1990              |"<<"   //)  "<<endl;
	cout<<"|   Cola de prueba de escritorio  |"<<"   V_/_ "<<endl;
	cout<<"|                                 |"<<endl;
	cout<<"|               22                |"<<endl;
	cout<<"|               10                |"<<endl;
	cout<<"|               67                |"<<endl;
	cout<<"|               91                |"<<endl;
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
		cout<<"|################# MENU COLAS #################|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|----------------------------------------------|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|### 1.Insertar nodo ###|### 4.Eliminar nodo ##|"<<endl;
		cout<<"|### 2.Modificar nodo ##|### 5.Desplegar nodo #|"<<endl;
		cout<<"|### 3.Buscar nodo #####|### 6.Salir ##########|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"*.____________________________________________.*"<<endl;
		setColor(11);
		cout<<"\nIngrese su opcion: "; cin>>opcion;
		switch(opcion){
			case 1:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############ INSERTAR NODO EN COLA ###########|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				insertarNodo();
				cout<<endl;
				system("pause");
				break;
			case 2:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############ MODIFICAR NODO EN COLA ##########|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				modificarNodo();
				cout<<endl;
				system("pause");
				break;
			case 3:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############# BUSCAR NODO EN COLA ############|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				buscarNodo();
				cout<<endl;
				system("pause");
				break;
			case 4:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############ ELIMINAR NODO EN COLA ###########|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				eliminarNodo();
				cout<<endl;
				system("pause");
				break;
			case 5:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|########### DESPLEGAR NODO EN COLA ###########|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				desplegarCola();
				cout<<endl;
				system("pause");
				break;
			case 6:
				cout <<  endl << endl << "Programa finalizado" << endl << endl;
				cout<<endl;
				system("pause");
				break;
			default:
				cout << endl << endl << "Opcion no valida" << endl << endl;
				cout<<endl;
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

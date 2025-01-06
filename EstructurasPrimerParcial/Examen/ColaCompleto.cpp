#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
}*primero, *ultimo;

//Prototipos
void menu();
void setColor(int);
void insertarNodo();
void desplegarCola();
void buscarNodo();
void modificarNodo();
void eliminarNodo();


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

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

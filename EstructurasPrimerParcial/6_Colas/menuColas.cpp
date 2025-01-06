#include <iostream>
using namespace std;

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
}*primero,*ultimo;

//Prototipos
void insertarNodo();
void desplegarCola();
void buscarNodo();
void modificarNodo();
void menu();

//Principal
int main(){
	menu();
	return 0;
}

// Función para insertar un nodo
void insertarNodo() {
    Nodo* nuevo = new Nodo();
    cout << "INGRESE EL DATO DEL NUEVO NODO: ";
    cin >> nuevo->dato;

    if (primero == NULL) {
        primero = nuevo;
        primero->siguiente = NULL;
        ultimo = primero;
    } else {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }
    cout << endl << "NODO INGRESADO" << endl << endl;
}

// Función para buscar un nodo
void buscarNodo() {
    Nodo* actual = new Nodo();
	actual = primero;
    bool encontrado = false;
    int nodoBuscado = 0;

    cout << "Ingrese el dato del nodo a buscar: ";
    cin >> nodoBuscado;

    if (primero != NULL) {
        while (actual != NULL && !encontrado) {
            if (actual->dato == nodoBuscado) {
                cout << "\nNODO CON EL DATO (" << nodoBuscado << ") ENCONTRADO";
                encontrado = true;
            }
            actual = actual->siguiente;
        }
        if (!encontrado) {
            cout << "\nNODO NO ENCONTRADO";
        }
    } else {
        cout << endl << "LA COLA SE ENCUENTRA VACIA" << endl << endl;
    }
}

// Función para modificar un nodo
void modificarNodo() {
    Nodo* actual = new Nodo();
	actual = primero;
    bool encontrado = false;
    int nodoBuscado = 0;

    cout << "Ingrese el dato del nodo a buscar para modificar: ";
    cin >> nodoBuscado;

    if (primero != NULL) {
        while (actual != NULL && !encontrado) {
            if (actual->dato == nodoBuscado) {
                cout << "\nNODO CON EL DATO (" << nodoBuscado << ") ENCONTRADO";
                cout << "\nINGRESE EL NUEVO DATO PARA ESTE NODO: ";
                cin >> actual->dato;
                encontrado = true;
            }
            actual = actual->siguiente;
        }
        if (!encontrado) {
            cout << "\nNODO NO ENCONTRADO";
        }
    } else {
        cout << endl << "LA COLA SE ENCUENTRA VACIA" << endl << endl;
    }
}

void eliminarNodo() {
    Nodo* actual = new Nodo();
    actual = primero;
    Nodo* anterior = new Nodo();
    anterior = NULL;
    bool encontrado = false;
    int nodoBuscado = 0;

    cout << "Ingrese el dato del nodo a buscar para eliminar: ";
    cin >> nodoBuscado;

    if (primero != NULL) {
        while (actual != NULL && encontrado != true) {
            if (actual->dato == nodoBuscado) {
                cout << "\nNODO CON EL DATO (" << nodoBuscado << ") ENCONTRADO";

                if (actual == primero) {
                    primero = primero->siguiente;
                } else if (actual == ultimo) {
                    anterior->siguiente = NULL;
                    ultimo = anterior;
                } else {
                    anterior->siguiente = actual->siguiente;
                }

                cout << "\nNODO ELIMINADO\n\n";
                encontrado = true;
            }

            anterior = actual;
            actual = actual->siguiente;
        }

        if (!encontrado) {
            cout << "\nNODO NO ENCONTRADO";
        }
    } else {
        cout << endl << "LA COLA SE ENCUENTRA VACIA" << endl << endl;
    }
}

// Función para desplegar la cola
void desplegarCola() {
    Nodo* actual = new Nodo();
	actual = primero;
    if (primero != NULL) {
        while (actual != NULL) {
            cout << endl << actual->dato;
            actual = actual->siguiente;
        }
        cout << endl;
    } else {
        cout << endl << "LA COLA SE ENCUENTRA VACIA" << endl << endl;
    }
}

void menu() {
    // Ejemplo de uso de las funciones
    int opcion_menu = 0;
    do {
        cout << "\n|--------------------------------------|\n";
		cout << "\n|--------------MENU COLAS--------------|\n";
        cout << "\n|---1.Insertar-----|----4.Eliminar-----|\n";
        cout << "\n|---2.Buscar-------|----5.Desplegar----|\n";
        cout << "\n|---3.Modificar----|----6.Salir--------|\n";
        cout << "\n|--------------------------------------|\n";
        cout << "Escoja una opcion: ";
        cin >> opcion_menu;

        switch (opcion_menu) {
            case 1:
            	cout<<endl<<endl<<"|----INSERTAR NODO EN COLA----|"<<endl<<endl;
                insertarNodo();
                cout<<endl;
                system("pause");
                break;
            case 2:
            	cout<<endl<<endl<<"|----BUSCAR NODO EN COLA----|"<<endl<<endl;
            	buscarNodo();
            	cout<<endl;
            	system("pause");
                break;
            case 3:
            	cout<<endl<<endl<<"|----MODIFICAR NODO EN COLA----|"<<endl<<endl;
                modificarNodo();
                cout<<endl;
                system("pause");
                break;
            case 4:
                cout<<endl<<endl<<"|----ELIMINAR NODO EN COLA----|"<<endl<<endl;
                eliminarNodo();
                cout<<endl;
                system("pause");
                break;
            case 5:
            	cout<<endl<<endl<<"|----DESPLEGAR NODO EN COLA----|"<<endl<<endl;
            	desplegarCola();
            	cout<<endl;
            	system("pause");
            	break;
            case 6:
            	cout<<endl<<endl<<"|----PROGRAMA FINALIZADO----|"<<endl<<endl;
            	cout<<endl;
            	system("pause");
			default:
                cout<<endl<<endl<< "Opcion no valida, intente de nuevo." <<endl<<endl;
        }system("cls");
    } while (opcion_menu != 6);
}

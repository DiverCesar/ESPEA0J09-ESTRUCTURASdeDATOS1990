////////////////////////////////////Arboles//////////////////////////////////
/*
Cuzco Alex
Manangon Zaith
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// Estructura de un nodo
struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

// Prototipos de funciones
void Menu();
Nodo *CrearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *&, int);
void eliminarNodo(Nodo *);
Nodo *Minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);

// Variable global
Nodo *arbol = NULL;

// Función principal
int main() {
    Menu();
    getch();
    return 0;
}

// Función para mostrar el menú
void Menu() {
    int dato, opcion, contador = 0;

    do {
        cout << "\t.:MENU:." << endl;
        cout << "1. Insertar un nuevo nodo" << endl;
        cout << "2. Mostrar arbol" << endl;
        cout << "3. Buscar elemento en el arbol" << endl;
        cout << "4. Recorrer arbol en preorden" << endl;
        cout << "5. Recorrer arbol en inorden" << endl;
        cout << "6. Recorrer arbol en postorden" << endl;
        cout << "7. Eliminar nodo del arbol" << endl;
        cout << "8. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nDigite un numero: ";
                cin >> dato;
                insertarNodo(arbol, dato, NULL);
                break;
            case 2:
                cout << "Mostrando el arbol:\n\n";
                mostrarArbol(arbol, contador);
                break;
            case 3:
                cout << "\nDigite el elemento a buscar: ";
                cin >> dato;
                if (busqueda(arbol, dato)) {
                    cout << "\nElemento " << dato << " encontrado en el arbol\n";
                } else {
                    cout << "\nElemento no encontrado en el arbol\n";
                }
                break;
            case 4:
                cout << "\nRecorrido en preorden: ";
                preOrden(arbol);
                cout << "\n";
                break;
            case 5:
                cout << "\nRecorrido en inorden: ";
                inOrden(arbol);
                cout << "\n";
                break;
            case 6:
                cout << "\nRecorrido en postorden: ";
                postOrden(arbol);
                cout << "\n";
                break;
            case 7:
                cout << "\nDigite el numero a eliminar: ";
                cin >> dato;
                eliminar(arbol, dato);
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }

        system("pause");
        system("cls");
    } while (opcion != 8);
}

// Función para crear un nodo
Nodo *CrearNodo(int n, Nodo *padre) {
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;
    nuevoNodo->padre = padre;
    return nuevoNodo;
}

// Función para insertar un nodo en el árbol
void insertarNodo(Nodo *&arbol, int n, Nodo *padre) {
    if (arbol == NULL) {
        Nodo *nuevoNodo = CrearNodo(n, padre);
        arbol = nuevoNodo;
    } else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n, arbol);
        } else {
            insertarNodo(arbol->der, n, arbol);
        }
    }
}

// Función para mostrar el árbol
void mostrarArbol(Nodo *arbol, int cont) {
    if (arbol == NULL) return;

    mostrarArbol(arbol->der, cont + 1);
    for (int i = 0; i < cont; i++) {
        cout << "   ";
    }
    cout << arbol->dato << endl;
    mostrarArbol(arbol->izq, cont + 1);
}

// Función para buscar un elemento en el árbol
bool busqueda(Nodo *arbol, int n) {
    if (arbol == NULL) {
        return false;
    } else if (arbol->dato == n) {
        return true;
    } else if (n < arbol->dato) {
        return busqueda(arbol->izq, n);
    } else {
        return busqueda(arbol->der, n);
    }
}

// Recorridos
void preOrden(Nodo *arbol) {
    if (arbol == NULL) return;
    cout << arbol->dato << " ";
    preOrden(arbol->izq);
    preOrden(arbol->der);
}

void inOrden(Nodo *arbol) {
    if (arbol == NULL) return;
    inOrden(arbol->izq);
    cout << arbol->dato << " ";
    inOrden(arbol->der);
}

void postOrden(Nodo *arbol) {
    if (arbol == NULL) return;
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->dato << " ";
}

// Función para eliminar un nodo
void eliminar(Nodo *&arbol, int n) {
    if (arbol == NULL) return;

    if (n < arbol->dato) {
        eliminar(arbol->izq, n);
    } else if (n > arbol->dato) {
        eliminar(arbol->der, n);
    } else {
        eliminarNodo(arbol);
    }
}

// Función para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der) {
        Nodo *menor = Minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    } else if (nodoEliminar->izq) {
        if (nodoEliminar == arbol) { // Verificar si es la raíz
            arbol = nodoEliminar->izq;
        }
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    } else if (nodoEliminar->der) {
        if (nodoEliminar == arbol) { // Verificar si es la raíz
            arbol = nodoEliminar->der;
        }
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    } else {
        if (nodoEliminar == arbol) { // Verificar si es la raíz
            arbol = NULL;
        }
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}


// Función para encontrar el nodo más a la izquierda
Nodo *Minimo(Nodo *arbol) {
    if (arbol == NULL) return NULL;

    if (arbol->izq) {
        return Minimo(arbol->izq);
    } else {
        return arbol;
    }
}

// Función para reemplazar nodos
void reemplazar(Nodo *arbol, Nodo *nuevoNodo) {
    if (arbol->padre) {
        if (arbol == arbol->padre->izq) {
            arbol->padre->izq = nuevoNodo;
        } else {
            arbol->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

// Función para destruir un nodo
void destruirNodo(Nodo *nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}


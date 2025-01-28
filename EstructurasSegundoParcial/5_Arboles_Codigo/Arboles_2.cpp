//Santi Jeancarlo
//Toscano Edgar

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

// PROTOTIPOS
void menu();
Nodo *CrearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *); // puntero referencia arbol y tipo de dato
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *); // FUNCION MAS IZQ POSIBLE
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol = NULL;
int main(){
	menu();
	getch();
	return 0;
}

// FUNCION DE MENU
void menu() {
    int dato, opcion, contador = 0;

    do {
        cout << "\t.:MENU:." << endl;
        cout << "1. INSERTAR UN NUEVO NODO" << endl;
        cout << "2. MOSTRAR ARBOL" << endl;
        cout << "3. BUSCAR ELEMENTO ARBOL" << endl;
        cout << "4. RECORRER ARBOL EN PREORDEN" << endl;
        cout << "5. RECORRER ARBOL EN INORDEN" << endl;
        cout << "6. RECORRER ARBOL EN POSTORDEN" << endl;
        cout << "7. ELIMINAR NODO DEL ARBOL" << endl;
        cout << "8. SALIR" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\nDIGITE UN NUMERO\t";
                cin >> dato;
                insertarNodo(arbol, dato, NULL); // INSERTAMOS UN NUEVO NODO
                cout << "\n";
                system("pause");
                break;
            case 2:
                cout << "MOSTRANDO EL ARBOL\n\n";
                mostrarArbol(arbol, contador);
                cout << "\n";
                system("pause");
                break;
            case 3:
                cout << "\nDIGITE ELEMENTO A BUSCAR EN ARBOL\n\n";
                cin >> dato;
                if (busqueda(arbol, dato) == true) {
                    cout << "\nELEMENTO\t" << dato << "\tENCONTRADO EN ARBOL\n";
                } else {
                    cout << "\nELEMENTO NO ENCONTRADO EN ARBOL\n";
                }
                cout << "\n";
                system("pause");
                break;
            case 4:
                cout << "\nRECORRIDO EN PREORDEN:";
                preOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;
            case 5:
                cout << "\nRECORRIDO EN INORDEN:\t";
                inOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;
            case 6:
                cout << "\nRECORRIDO EN POSTORDEN:\t";
                postOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;
            case 7:
                cout << "DIGITE EL NUMERO A ELIMINAR: ";
                cin >> dato;
                eliminar(arbol, dato);
                cout << "\n\n";
                system("pause");
                break;
        }
        system("cls");
    } while(opcion != 8);
}

// FUNCION CREAR NUEVO NODO
Nodo *CrearNodo(int n, Nodo *padre) {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

// FUNCION INSERTAR ELEMENTOS EN EL ARBOL
void insertarNodo(Nodo *&arbol, int n, Nodo *padre) {
    if (arbol == NULL) { // SI ARBOL ESTA VACIO
        Nodo *nuevo_nodo = CrearNodo(n, padre);
        arbol = nuevo_nodo;
    } else { // SI ARBOL TIENE UN NODO O MAS
        int valorRaiz = arbol->dato; // OBTENEMOS VALOR DE LA RAIZ
        if (n < valorRaiz) { // SI EL ELEMENTO ES MENOR A LA RAIZ, INSERTAMOS A LA IZQ
            insertarNodo(arbol->izq, n, arbol);
        } else { // SI EL ELEMENTO ES MAYOR A LA RAIZ, INSERTAMOS A LA DER
            insertarNodo(arbol->der, n, arbol);
        }
    }
}

// FUNCION MOSTRAR ARBOL
void mostrarArbol(Nodo *arbol, int cont) {
    if (arbol == NULL) {
        return;
    } else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}

// FUNCION BUSCAR ELEMENTO EN ARBOL
bool busqueda(Nodo *arbol, int n) {
    if (arbol == NULL) { // ARBOL VACIO
        return false;
    } else if (arbol->dato == n) { // SI EL NODO ES IGUAL AL ELEMENTO
        return true;
    } else if (n < arbol->dato) {
        return busqueda(arbol->izq, n);
    } else {
        return busqueda(arbol->der, n);
    }
}

// FUNCION RECORRIDO PROFUNDIDAD PREORDEN
void preOrden(Nodo *arbol) {
    if (arbol == NULL) {
        return;
    } else {
        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

// FUNCION RECORRIDO PROFUNDIDAD INORDEN
void inOrden(Nodo *arbol) {
    if (arbol == NULL) {
        return;
    } else {
        inOrden(arbol->izq);
        cout << arbol->dato << " - ";
        inOrden(arbol->der);
    }
}

// FUNCION RECORRIDO PROFUNDIDAD POSTORDEN
void postOrden(Nodo *arbol) {
    if (arbol == NULL) { // ARBOL VACIO
        return;
    } else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}

// FUNCION ELIMINAR NODO
void eliminar(Nodo *arbol, int n) {
    if (arbol == NULL) { // SI EL ARBOL ESTA VACIO
        return; // NO HACE NADA
    } else if (n < arbol->dato) { // SI EL ELEMENTO ES MENOR
        eliminar(arbol->izq, n); // BUSCA POR LA IZQUIERDA
    } else if (n > arbol->dato) { // SI EL ELEMENTO ES MAYOR
        eliminar(arbol->der, n); // BUSCA POR LA DERECHA
    } else { // SI ENCONTRO EL VALOR
        eliminarNodo(arbol);
    }
}

// FUNCION PARA ELIMINAR NODO ENCONTRADO
void eliminarNodo(Nodo *nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der) { // SI EL NODO TIENE HIJOS IZQ Y DER
        Nodo *menor = minimo(nodoEliminar->der); // BUSCA LA MAS IZQ POSIBLE
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    } else if (nodoEliminar->izq) { // SI TIENE HIJO IZQ
        reemplazar(nodoEliminar, nodoEliminar->izq);
        if (nodoEliminar == arbol) { // SI se elimina la raiz
            arbol = nodoEliminar->izq;
        }
        destruirNodo(nodoEliminar);
    } else if (nodoEliminar->der) { // SI TIENE HIJO DER
        reemplazar(nodoEliminar, nodoEliminar->der);
        if (nodoEliminar == arbol) { // si se elimina la raiz
            arbol = nodoEliminar->der;
        }
        destruirNodo(nodoEliminar);
    } else { // SI UN NODO NO TIENE HIJOS NODO HOJA
        if (nodoEliminar == arbol) { // SI ELIMINAS LA RAÍZ
            arbol = NULL;
        } else {
            reemplazar(nodoEliminar, NULL);
        }
        destruirNodo(nodoEliminar);
    }
}

// FUNCION DETERMINAR EL NODO MAS IZQ POSIBLE
Nodo *minimo(Nodo *arbol) {
    if (arbol == NULL) { // SI EL ARBOL ES VACIO
        return NULL; // RETORNA NULO
    } else if (arbol->izq) { // SI TIENE HIJO IZQ
        return minimo(arbol->izq); // BUSCA LA MAS IZQ POSIBLE
    } else { // SI NO TIENE HIJO IZQUIERDO RETORNA EL MISMO NODO
        return arbol; // RETORNA NODO COMPLETO
    }
}

// FUNCION REEMPLAZAR DOS NODOS
void reemplazar(Nodo *arbol, Nodo *nuevoNodo) {
    if (arbol->padre) { // SI NODO TIENE PADRE
        if (arbol == arbol->padre->izq) {
            arbol->padre->izq = nuevoNodo;
        } else if (arbol == arbol->padre->der) {
            arbol->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

// FUNCION DESTRUIR NODO
void destruirNodo(Nodo *nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}


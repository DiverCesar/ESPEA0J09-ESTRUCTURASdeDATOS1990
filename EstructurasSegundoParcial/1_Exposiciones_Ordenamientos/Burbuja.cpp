

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void burbuja(int arr[], int n);
void impArreglo(int arr[], int tamano, int indice);

int main() {
    srand(time(NULL)); 

    int numElementos;
    cout << "Ingrese el numero de elementos del arreglo: ";
    cin >> numElementos;

    int* arreglo = new int[numElementos]; 

    for (int i = 0; i < numElementos; i++) {
        arreglo[i] = 1 + rand() % 100;
    }

    cout << "\nArreglo sin ordenar ==> ";
    impArreglo(arreglo, numElementos, 0);

    burbuja(arreglo, numElementos);

    cout << "Arreglo ordenado ==> ";
    impArreglo(arreglo, numElementos, 0);

    delete[] arreglo;
    return 0;
}

void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void impArreglo(int arr[], int tamano, int indice) {
    if (indice >= tamano) {
        cout << "\n";
        return;
    } else {
        cout << arr[indice] << " ";
        impArreglo(arr, tamano, indice + 1);
    }
}


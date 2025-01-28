#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Funcion para intercambiar dos elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// Funcion de particion
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    // Colocar el pivote en su lugar
    swap(arr[i + 1], arr[high]);
    return i + 1; // Retornar el índice del pivote
}
// Implementacion de Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtener el índice de partición
        int pi = partition(arr, low, high);
        // Ordenar recursivamente las dos mitades
        quickSort(arr, low, pi - 1);  // Lado izquierdo
        quickSort(arr, pi + 1, high); // Lado derecho
    }
}
// Funcion para imprimir el array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Programa principal
int main() {
	srand(time(NULL));
    int n;
    // Solicitar el tamaño del arreglo
    cout << "Ingrese el tamanio del arreglo: ";
    cin >> n;
    int* arr = new int[n];  // Crear un arreglo dinámico
    // Solicitar los elementos del arreglo
    /*
    cout << "Ingrese " << n << " elementos para el arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arr[i];
    }*/
    //Ingreso numeros aleatorios
    for(int i=0;i<n;i++){
    	arr[i]=rand()%100+1;
	}
    // Mostrar el arreglo original
    cout << "Array original: ";
    printArray(arr, n);
    // Llamar a la función quickSort
    quickSort(arr, 0, n - 1);
    // Mostrar el arreglo ordenado
    cout << "Array ordenado: ";
    printArray(arr, n);
    delete[] arr;  
    return 0;
}


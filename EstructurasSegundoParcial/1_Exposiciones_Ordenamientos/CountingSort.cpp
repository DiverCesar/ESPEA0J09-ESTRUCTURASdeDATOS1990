#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void countSort(int arr[], int n) {
    int output[n];       // Arreglo de salida
    int count[101] = {0}; // Arreglo de conteo, extendido para manejar valores de 1 a 100

    // Contar la frecuencia de cada elemento
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Calcular posiciones acumulativas
    for (int i = 1; i <= 100; i++) {
        count[i] += count[i - 1];
    }

    // Colocar los elementos en la posición correcta en 'output'
    for (int i = n - 1; i >= 0; i--) { // Recorremos de atrás hacia adelante
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copiar el arreglo ordenado de 'output' a 'arr'
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    // Validación de tamaño
    if (n <= 0) {
        cout << "El tamaño debe ser mayor que cero." << endl;
        return 1;
    }

    int* arr = new int[n]; // Usamos memoria dinámica para evitar problemas con VLA

    // Inicializar la semilla para números aleatorios
    srand(time(0));

    // Generar valores aleatorios para el arreglo
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; // Genera valores entre 1 y 100
    }

    cout << "Arreglo generado aleatoriamente:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countSort(arr, n);

    cout << "Arreglo ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Liberar memoria dinámica

    return 0;
}


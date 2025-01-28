#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funci�n para imprimir un arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Funci�n de ordenamiento Exchange Sort
void exchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Funci�n para generar un arreglo binario aleatorio
void generateRandomBinaryArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 2; // Genera 0 o 1 aleatoriamente
    }
}

// Funci�n principal
int main() {
    int n;

    // Inicializar la semilla para n�meros aleatorios
    srand(time(NULL));

    printf("Introduce el tama�o del arreglo binario: ");
    scanf("%d", &n);

    // Crear el arreglo din�micamente
    int arr[n];

    // Generar arreglo binario aleatorio
    generateRandomBinaryArray(arr, n);

    printf("Arreglo original generado aleatoriamente:\n");
    printArray(arr, n);

    // Ordena el arreglo binario
    exchangeSort(arr, n);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);

    return 0;
}


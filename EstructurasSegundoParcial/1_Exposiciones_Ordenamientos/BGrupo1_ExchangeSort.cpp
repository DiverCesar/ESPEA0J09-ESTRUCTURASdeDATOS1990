#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para imprimir un arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función de ordenamiento Exchange Sort
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

// Función para generar un arreglo binario aleatorio
void generateRandomBinaryArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 2; // Genera 0 o 1 aleatoriamente
    }
}

// Función principal
int main() {
    int n;

    // Inicializar la semilla para números aleatorios
    srand(time(NULL));

    printf("Introduce el tamaño del arreglo binario: ");
    scanf("%d", &n);

    // Crear el arreglo dinámicamente
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


#include <stdio.h>
#include <stdlib.h> // Para rand() y srand()
#include <time.h>   // Para usar time() como semilla de números aleatorios

void imprimir(int A[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

void shellSort(int A[], int tam) {
    int paso, i, j, temp;

    paso = tam / 2;
    while (paso > 0) {
        for (i = paso; i < tam; i++) {
            temp = A[i];
            for (j = i; j >= paso; j -= paso) {
                if (A[j - paso] > temp) {
                    A[j] = A[j - paso];
                } else {
                    break;
                }
            }
            A[j] = temp;
        }
        paso = paso / 2;
    }
}

int main() {
    int tam, i;

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tam);

    int A[tam]; // Declarar el arreglo con tamaño ingresado

    // Inicializar semilla para números aleatorios
    srand(time(NULL));

    // Generar números aleatorios para llenar el arreglo
    for (i = 0; i < tam; i++) {
        A[i] = rand() % 100 + 1; // Números aleatorios entre 0 y 99
    }

    printf("Arreglo en desorden: ");
    imprimir(A, tam);

    shellSort(A, tam);

    printf("Arreglo en orden: ");
    imprimir(A, tam);

    return 0;
}


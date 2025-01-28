#include <stdio.h>
#include <stdlib.h>
#define FILAS 3
#define COLUMNAS 3

void imprimirMatriz(float matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, totalElementos = FILAS * COLUMNAS;
    float menor, AUX, valor;
    float matriz[FILAS][COLUMNAS];
    float lineal[totalElementos]; 
    int pos_menor, alto, central, bajo;
    int bandera = 0;

    printf("Ingrese los elementos de la matriz (%d filas x %d columnas):\n", FILAS, COLUMNAS);
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    // Ordenamiento del arreglo lineal
    int idx = 0;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            lineal[idx++] = matriz[i][j];
        }
    }

    for (i = 0; i < totalElementos - 1; i++) {
        menor = lineal[i];
        pos_menor = i;
        for (j = i + 1; j < totalElementos; j++) {
            if (lineal[j] < menor) {
                menor = lineal[j];
                pos_menor = j;
            }
        }
        AUX = lineal[i];
        lineal[i] = lineal[pos_menor];
        lineal[pos_menor] = AUX;
    }

    printf("\nArreglo ordenado:\n");
    for (i = 0; i < totalElementos; i++) {
        printf("%f ", lineal[i]);
    }
    printf("\n");

    // Búsqueda binaria con banderas para valores repetidos
    printf("\nQue valor desea buscar? ");
    scanf("%f", &valor);
    bajo = 0;
    alto = totalElementos - 1;
    central = (alto + bajo) / 2;

    while (bajo <= alto && lineal[central] != valor) {
        if (valor < lineal[central]) {
            alto = central - 1;
        } else {
            bajo = central + 1;
        }
        central = (alto + bajo) / 2;
    }

    if (lineal[central] == valor) {
        printf("El valor se encuentra en las posiciones: ");
        bandera = 1;

    // Verificar hacia la izquierda del índice central
        int izquierda = central;
        while (izquierda >= 0 && lineal[izquierda] == valor) {
            printf("%d ", izquierda);
            izquierda--;
        }
        
        // Verificar hacia la derecha del índice central
        int derecha = central + 1;
        while (derecha < totalElementos && lineal[derecha] == valor) {
            printf("%d ", derecha);
            derecha++;
        }
        printf("\n");
    }

    if (!bandera) {
        printf("El valor no se encuentra en la matriz.\n");
    }

    return 0;
}

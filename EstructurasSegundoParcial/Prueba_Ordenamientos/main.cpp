#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting_algorithms.h"

using namespace std;

int main() {
    int opcion, n;
    srand(time(0)); // Semilla para números aleatorios

    do {
        cout << "\n--- MENU DE ORDENAMIENTO ---\n";
        cout << "1. Exchange Sort\n";
        cout << "2. Burbuja\n";
        cout << "3. ShellSort\n";
        cout << "4. QuickSort\n";
        cout << "5. Radix Sort\n";
        cout << "6. Counting Sort\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 6) {
            cout << "Ingrese el tamaño del arreglo: ";
            cin >> n;

            int* arreglo = new int[n];
            for (int i = 0; i < n; i++) {
                arreglo[i] = rand() % 100 + 1;
            }

            cout << "\nArreglo generado aleatoriamente: ";
            imprimir(arreglo, n);

            switch (opcion) {
                case 1:
                    exchangeSort(arreglo, n);
                    cout << "Arreglo ordenado con Exchange Sort: ";
                    break;
                case 2:
                    burbuja(arreglo, n);
                    cout << "Arreglo ordenado con Burbuja: ";
                    break;
                case 3:
                    shellSort(arreglo, n);
                    cout << "Arreglo ordenado con ShellSort: ";
                    break;
                case 4:
                    quickSort(arreglo, 0, n - 1);
                    cout << "Arreglo ordenado con QuickSort: ";
                    break;
                case 5:
                    radixSort(arreglo, n);
                    cout << "Arreglo ordenado con Radix Sort: ";
                    break;
                case 6:
                    countingSort(arreglo, n);
                    cout << "Arreglo ordenado con Counting Sort: ";
                    break;
            }

            imprimir(arreglo, n);
            delete[] arreglo;
        } else if (opcion != 7) {
            cout << "Opción inválida. Intente de nuevo.\n";
        }

    } while (opcion != 7);

    cout << "Programa finalizado.\n";
    return 0;
}


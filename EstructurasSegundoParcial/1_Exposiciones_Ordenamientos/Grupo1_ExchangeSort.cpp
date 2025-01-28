#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función de ordenamiento por intercambio exchangeSort
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

int main() {
    int n;

    cout << "Cuantos numeros ordenara?: ";
    cin >> n;
    int* arreglo = new int[n];
    srand(time(0));
    // Llenar el arreglo con números aleatorios
    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % 100+1;
    }

    cout << "Arreglo generado aleatoriamente: \n";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    exchangeSort(arreglo, n);

    cout << "Arreglo ordenado: \n";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    delete[] arreglo;

    return 0;
}


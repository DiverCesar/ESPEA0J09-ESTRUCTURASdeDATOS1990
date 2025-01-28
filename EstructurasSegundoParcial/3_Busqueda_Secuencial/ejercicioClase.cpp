#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

const int N = 3; // Declaración de una constante de tipo entero para el número de filas
const int M = 3; // Declaración de una constante de tipo entero para el número de columnas
float matriz[N][M]; // Declaración de un arreglo de dos dimensiones
int fila, col; // Variables para localizar las filas y las columnas

void leerarray(); // Declaración de la función para leer el arreglo
void imprimirarray(); // Declaración de la función para realizar la impresión del arreglo
void buscarDato();
int main()
{
    srand(time(NULL));
    
    leerarray(); // Llamada a la función para leer el arreglo
    cout << endl;
    cout << "*****************MATRIZ*****************" << endl;
    imprimirarray(); // Llamada a la función para imprimir el arreglo
    buscarDato();
    return 0;
}

void leerarray()
{
    fila = 0, col = 0;
    int y;
    for (fila = 0; fila < N; ++fila)
    {
        for (col = 0; col < M; ++col)
        {
            y = (rand() % 9) + 1; // Genera números aleatorios del 1 al 9
            matriz[fila][col] = y;
        }
        cout << endl;
    }
}
void buscarDato() {
    int dato;
    bool encontrado = false;  
    
    cout << "Ingresar el dato a buscar: " << endl;
    cin >> dato;
    
    for (fila = 0; fila < N; ++fila) {
        for (col = 0; col < M; ++col) {
            if (matriz[fila][col] == dato) {  
                cout << "Valor encontrado" << endl;
                cout << "Posicion: [" << fila << "][" << col << "]" << endl;
                encontrado = true;
            }
        }
    }
    
    if (!encontrado) {
        cout << "Valor no encontrado" << endl;
    }
}	

void imprimirarray()
{
    fila = 0, col = 0;
    for (fila = 0; fila < N; ++fila)
    {
        for (col = 0; col < M; ++col)
        {
            if (col == 0) // Para el valor de la primera columna de cada fila
            {
                cout << "| " << matriz[fila][col] << " | ";
            }
            else // Para las demás columnas
            {
                cout << matriz[fila][col] << " | ";
            }
        }
        cout << endl;
    }
}


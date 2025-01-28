#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

const int N = 3; // Declaraci�n de una constante de tipo entero para el n�mero de filas
const int M = 3; // Declaraci�n de una constante de tipo entero para el n�mero de columnas
float matriz[N][M]; // Declaraci�n de un arreglo de dos dimensiones
int fila, col; // Variables para localizar las filas y las columnas

void leerarray(); // Declaraci�n de la funci�n para leer el arreglo
void imprimirarray(); // Declaraci�n de la funci�n para realizar la impresi�n del arreglo
void buscarDato();
int main()
{
    srand(time(NULL));
    
    leerarray(); // Llamada a la funci�n para leer el arreglo
    cout << endl;
    cout << "*****************MATRIZ*****************" << endl;
    imprimirarray(); // Llamada a la funci�n para imprimir el arreglo
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
            y = (rand() % 9) + 1; // Genera n�meros aleatorios del 1 al 9
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
            else // Para las dem�s columnas
            {
                cout << matriz[fila][col] << " | ";
            }
        }
        cout << endl;
    }
}


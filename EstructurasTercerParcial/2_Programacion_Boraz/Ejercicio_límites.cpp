#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand((time(0))); // Inicializa la semilla para la generaci�n aleatoria

    // Generar los l�mites aleatorios
    int limiteInferior = 1 + rand() % 100;
    int limiteSuperior = limiteInferior + rand() % (100 - limiteInferior + 1);

    cout << "Limite inferior: " << limiteInferior << endl;
    cout << "Limite superior: " << limiteSuperior << endl;

    // Crear la lista de n�meros en los l�mites
    const int TAMANIO = limiteSuperior - limiteInferior + 1;
    int lista[TAMANIO];
    for (int i = 0; i < TAMANIO; ++i) {
        lista[i] = limiteInferior + i;
    }

    // Mostrar la lista inicial
    cout << "Lista inicial: ";
    for (int i = 0; i < TAMANIO; ++i) {
        cout << lista[i] << " ";
    }
    cout << endl;

    // Solicitar al usuario un n�mero dentro de los l�mites
    int n;
    cout << "Ingresa un numero dentro de los limites (" << limiteInferior << "-" << limiteSuperior << "): ";
    cin >> n;

    // Verificar que el n�mero est� en los l�mites
    if (n < limiteInferior || n > limiteSuperior) {
        cout << "El numero ingresado esta fuera de los limites." << endl;
        return 1;
    }

    // Generar un aleatorio entre 0 y 9
    int aleatorio = rand() % 10;

    // Sumar el aleatorio al n�mero ingresado
    int resultado = n + aleatorio;

    // Imprimir el resultado de la suma
    cout << "Numero ingresado: " << n << endl;
    cout << "Numero aleatorio generado: " << aleatorio << endl;
    cout << "Resultado de la suma: " << resultado << endl;

    // Verificar que el resultado est� dentro de los l�mites
    if (resultado > limiteSuperior) {
        cout << "El resultado (" << resultado << ") supera el limite superior." << endl;
        return 1;
    }

    // Eliminar el resultado de la lista
    for (int i = 0; i < TAMANIO; ++i) {
        if (lista[i] == resultado) {
            // Desplazar los elementos para eliminar el n�mero
            for (int j = i; j < TAMANIO - 1; ++j) {
                lista[j] = lista[j + 1];
            }
            lista[TAMANIO - 1] = 0; // Opcional: Rellenar con 0 el �ltimo elemento
            break;
        }
    }

    // Mostrar la lista actualizada
    cout << "Lista actualizada: ";
    for (int i = 0; i < TAMANIO - 1; ++i) {
        cout << lista[i] << " ";
    }
    cout << endl;

    // Mostrar el n�mero eliminado
    cout << "El numero eliminado es: " << resultado << endl;

    return 0;
}


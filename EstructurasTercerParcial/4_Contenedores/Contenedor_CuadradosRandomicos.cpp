#include <iostream>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(NULL));
    
    // Declaraci�n de un unordered_map con clave y valor de tipo int
    unordered_map<string, int> dato;
    
    // Generar cinco n�meros aleatorios entre 1 y 50
    int A1 = 1 + rand() % 50;
    int A2 = 1 + rand() % 50;
    int A3 = 1 + rand() % 50;
    int A4 = 1 + rand() % 50;
    int A5 = 1 + rand() % 50;
    
    // Insertar elementos (clave: nombre, valor: el cuadrado del n�mero correspondiente)
    dato["Primero"] = A1 * A1;
    dato["Segundo"] = A2 * A2;
    dato["Tercero"] = A3 * A3;
    dato["Cuarto"] = A4 * A4;
    dato["Quinto"] = A5 * A5;
    
    // Recorrer e imprimir los elementos del unordered_map
    cout << "Valores almacenados:" << endl;
    for(const auto& par : dato){
        cout << "Numero: " << par.first << " - Cuadrado: " << par.second << endl;
    }
    return 0;
}

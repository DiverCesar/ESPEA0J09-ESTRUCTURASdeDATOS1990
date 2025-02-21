#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    int A1, A2= rand()%50+1;
    double A3 = static_cast<double>(A1) / A2;
    double A4 = A3 * 2;
    double A5 = A3 + 5;
    double A6 = A3 - 3;
    double A7 = A3 * A3;
    unordered_map<string, double> datos;
    datos["Valor1"] = A3;
    datos["Valor2"] = A4;
    datos["Valor3"] = A5;
    datos["Valor4"] = A6;
    datos["Valor5"] = A7;

    // Imprimir los valores almacenados
    cout << "Valores generados:" << endl;
    cout << "A1: " << A1 << "\nA2: " << A2 << "\nA3: " << A3 << endl;
    
    cout << "Valores almacenados en el unordered_map:" << endl;
    for (const auto& par : datos) {
        cout << par.first << " = " << par.second << endl;
    }
    
    return 0;

}

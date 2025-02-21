#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Inicializa la semilla de números aleatorios
    
    int num1 = 100 + rand() % 900; // Número aleatorio entre 100 y 999
    int num2 = 100 + rand() % 900; // Número aleatorio entre 100 y 999
    
    cout << "Numero 1: " << num1 << endl;
    cout << "Numero 2: " << num2 << endl;
    
    // Extraer dígitos
    int dig1_1 = num1 / 100;
    int dig1_2 = (num1 / 10) % 10;
    int dig1_3 = num1 % 10;
    
    int dig2_1 = num2 / 100;
    int dig2_2 = (num2 / 10) % 10;
    int dig2_3 = num2 % 10;
    
    cout << "Comparacion digito por digito:" << endl;
    
    cout << "Centena: " << dig1_1 << " vs " << dig2_1;
    if (dig1_1 == dig2_1) {
        cout << " (Iguales)";
    } else {
        cout << " (Diferentes)";
    }
    cout << endl;
    
    cout << "Decena: " << dig1_2 << " vs " << dig2_2;
    if (dig1_2 == dig2_2) {
        cout << " (Iguales)";
    } else {
        cout << " (Diferentes)";
    }
    cout << endl;
    
    cout << "Unidad: " << dig1_3 << " vs " << dig2_3;
    if (dig1_3 == dig2_3) {
        cout << " (Iguales)";
    } else {
        cout << " (Diferentes)";
    }
    cout << endl;
    
    return 0;
}

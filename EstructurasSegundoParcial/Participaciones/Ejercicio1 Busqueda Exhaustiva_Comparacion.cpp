#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 

    int num1 = rand() % 900 + 100; 
    int num2 = rand() % 900 + 100; 

    cout << "Numero 1: " << num1 << endl;
    cout << "Numero 2: " << num2 << endl;

    int numero1[3], numero2[3];
    
    
    for (int i = 2; i >= 0; i--) {
        numero1[i] = num1 % 10;
        numero2[i] = num2 % 10;
        num1 /= 10;
        num2 /= 10;
    }

    bool encontrar = false;
    for (int i = 0; i < 3; i++) {
        if (numero1[i] == numero2[i]) {
            cout << "Coincidencia en la posicion " << i + 1 << ": " << numero1[i] << endl;
            encontrar = true;
        }
    }

    if (!encontrar) {
        cout << "No hay coincidencias en ninguna posicion." << endl;
    }

    return 0;
}


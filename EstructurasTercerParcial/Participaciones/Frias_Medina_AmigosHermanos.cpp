//Frias Pedro 
//Medina Simone 
#include <iostream>
#include <vector>
using namespace std;

int sumaDivisoresPropios(int n) {
    int suma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            suma += i;
        }
    }
    return suma;
}

bool sonAmigos(int a, int b) {
    return (sumaDivisoresPropios(a) == b) || (sumaDivisoresPropios(b) == a);
}
bool sonHermanos(int a, int b) {
    return a == b;
}
void ingresarNumeros(vector<int>& numeros) {
    for (int i = 0; i < 3; i++) {
    	cout << "Ingrese un numero: ";
        cin >> numeros[i];
    }
}
void verificarNumeros(const vector<int>& numeros) {
    bool amigos1y2 = sonAmigos(numeros[0], numeros[1]);
    bool amigos1y3 = sonAmigos(numeros[0], numeros[2]);
    bool amigos2y3 = sonAmigos(numeros[1], numeros[2]);
    bool hermanos1y2 = sonHermanos(numeros[0], numeros[1]);
    bool hermanos1y3 = sonHermanos(numeros[0], numeros[2]);
    bool hermanos2y3 = sonHermanos(numeros[1], numeros[2]);
    if (amigos1y2 || amigos1y3 || amigos2y3) {
        cout << "Los numeros son amigos." << endl;
    } else {
        cout << "Los numeros no son amigos." << endl;
    }
    if (hermanos1y2 || hermanos1y3 || hermanos2y3) {
        cout << "Los numeros son hermanos." << endl;
    } else {
        cout << "Los numeros no son hermanos." << endl;
    }
}
int main() {
    vector<int> numeros(3);
    ingresarNumeros(numeros);
    verificarNumeros(numeros);
    return 0;
}

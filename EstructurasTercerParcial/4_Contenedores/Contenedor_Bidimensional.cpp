#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

void Programa() {
    srand(time(0));
    unordered_map<string, double> datos;
    string claves[] = {"primero", "segundo", "tercero", "cuarto", "quinto"};

    for (int i = 0; i < 5; i++) {
        int num1 = 1 + rand() % 50;
        int num2 = 1 + rand() % 50;
        double division = static_cast<double>(num1) / num2;
        datos[claves[i]] = division;
        cout << claves[i] << ": (" << num1 << ", " << num2 << ") -> " << division << endl;
    }
}

int main() {
    Programa();
    return 0;
}


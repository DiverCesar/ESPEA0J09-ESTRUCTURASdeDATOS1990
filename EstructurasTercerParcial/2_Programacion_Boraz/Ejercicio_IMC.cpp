#include <iostream>

using namespace std;

// Estructura para almacenar peso y altura
struct DatosPersonales {
    double pesoLibras;
    double alturaCm;
};

// Función para convertir peso en libras a kilogramos
double convertirLibrasAKilogramos(double pesoLibras) {
    return pesoLibras * 0.453592;
}

// Función para convertir altura en centímetros a metros
double convertirCentimetrosAMetros(double alturaCm) {
    return alturaCm / 100.0;
}

// Función para calcular el IMC
double calcularIMC(double pesoKg, double alturaM) {
    return pesoKg / (alturaM * alturaM);
}

// Función para interpretar el IMC
void interpretarIMC(double imc) {
    cout << "Su IMC es: " << imc << endl;

    if (imc < 18.5) {
        cout << "Categoria: Peso insuficiente" << endl;
    } else if (imc >= 18.5 && imc < 24.9) {
        cout << "Categoria: Peso normal" << endl;
    } else if (imc >= 25 && imc < 29.9) {
        cout << "Categoria: Sobrepeso" << endl;
    } else {
        cout << "Categoria: Obesidad" << endl;
        // Determinar tipo de obesidad
        if (imc >= 30 && imc < 34.9) {
            cout << "Obesidad grado 1" << endl;
        } else if (imc >= 35 && imc < 39.9) {
            cout << "Obesidad grado 2" << endl;
        } else {
            cout << "Obesidad grado 3 (mórbida)" << endl;
        }
    }
}

// Función principal
int main() {
    DatosPersonales datos;

    // Solicitar datos al usuario
    cout << "Ingrese su peso en libras: ";
    cin >> datos.pesoLibras;
    cout << "Ingrese su altura en centimetros: ";
    cin >> datos.alturaCm;

    // Convertir unidades
    double pesoKg = convertirLibrasAKilogramos(datos.pesoLibras);
    double alturaM = convertirCentimetrosAMetros(datos.alturaCm);

    // Calcular IMC
    double imc = calcularIMC(pesoKg, alturaM);

    // Interpretar IMC
    interpretarIMC(imc);

    return 0;
}




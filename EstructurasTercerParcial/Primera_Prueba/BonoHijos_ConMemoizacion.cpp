#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, double> bonoMemo;  // Contenedor para memorización del bono

// Función para calcular el bono con memorización
double calcularBono(int hijos, double sueldo) {
	
    string clave = to_string(hijos) + "," + to_string(sueldo);

    // Si ya se calculó el bono, devolver el valor almacenado
    if (bonoMemo.find(clave) != bonoMemo.end()) {
        cout << "Usando bono memorizado para: " << hijos << " hijos y sueldo " << sueldo << "...\n";
        return bonoMemo[clave];
    }

    double bono = (sueldo * 0.0625) * hijos;
    bonoMemo[clave] = bono;  // Almacenar el resultado en el mapa
    cout << "Calculando bono para: " << hijos << " hijos y sueldo " << sueldo << "...\n";
    return bono;
}

int main() {

    unordered_map<string, pair<int, double>> empleados = {
        {"L034", {3, 451}},
        {"L045", {0, 725}},
        {"L062", {2, 611}},
        {"L023", {1, 1028}},
        {"L011", {4, 1540}}
    };

    // Mostrar el cuadro con los datos y el bono calculado
    for (const auto& empleado : empleados) {
        
		string id = empleado.first;
        
        int hijos = empleado.second.first;
        double sueldo = empleado.second.second;
        double bono = calcularBono(hijos, sueldo);
        
        cout << "ID: " << id << "\nSueldo: " << sueldo << "\nHijos: " << hijos << "\nBono: " << bono << "\n\n";

        
        if (id == "L045" || id == "L062") {  // Filtrar solo L045 y L062
            int hijos = empleado.second.first;
            double sueldo = empleado.second.second;
            double bono = calcularBono(hijos, sueldo);

            cout << "-----------------------------------\n";
            cout << "ID: " << id << "\nSueldo: " << sueldo << "\nHijos: " << hijos << "\nBono: " << bono << "\n\n";
        }
    }

    return 0;
}


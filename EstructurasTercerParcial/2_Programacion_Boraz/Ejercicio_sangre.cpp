#include <iostream>

using namespace std;

struct TipoSangre {
    string tipo;
    string puedeDonarA[8];
    string puedeRecibirDe[8];
};

void mostrarCompatibilidad(TipoSangre tabla[], int tamano, string tipo) {
    for (int i = 0; i < tamano; i++) {
        if (tabla[i].tipo == tipo) {
            cout << "Tipo de sangre: " << tipo << endl;
            cout << "Puede donar a: ";
            for (int j = 0; !tabla[i].puedeDonarA[j].empty(); j++) {
                cout << tabla[i].puedeDonarA[j] << " ";
            }
            cout << endl;

            cout << "Puede recibir de: ";
            for (int j = 0; !tabla[i].puedeRecibirDe[j].empty(); j++) {
                cout << tabla[i].puedeRecibirDe[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Tipo de sangre no valido." << endl;
}

int main() {
    TipoSangre tablaCompatibilidad[8] = {
        {"O-", {"O-", "O+", "A-", "A+", "B-", "B+", "AB-", "AB+"}, {"O-"}},
        {"O+", {"O+", "A+", "B+", "AB+"}, {"O-", "O+"}},
        {"A-", {"A-", "A+", "AB-", "AB+"}, {"A-", "O-"}},
        {"A+", {"A+", "AB+"}, {"A-", "A+", "O-", "O+"}},
        {"B-", {"B-", "B+", "AB-", "AB+"}, {"B-", "O-"}},
        {"B+", {"B+", "AB+"}, {"B-", "B+", "O-", "O+"}},
        {"AB-", {"AB-", "AB+"}, {"AB-", "A-", "B-", "O-"}},
        {"AB+", {"AB+"}, {"O-", "O+", "A-", "A+", "B-", "B+", "AB-", "AB+"}}
    };

    string tipoUsuario;
    cout << "Ingrese su tipo de sangre (Ejemplo: A+, O-, AB+): ";
    cin >> tipoUsuario;

    mostrarCompatibilidad(tablaCompatibilidad, 8, tipoUsuario);

    return 0;
}




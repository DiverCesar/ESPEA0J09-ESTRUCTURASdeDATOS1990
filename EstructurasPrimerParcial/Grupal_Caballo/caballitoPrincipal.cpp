//GRUPO 5:
//Baez Gabriel
//Frias Pedro
//Galarza Cesar
//Medina Simone
//Simbana Michael

#include <iostream>
#include "caballitoRecursivo.h"

using namespace std;

int main() {
    int N;

    cout << "Introduce la dimension del tablero (N x N) menor a 9: "; cin >> N;
    
    while(N>8){
    	cout << "\nDimension desbordada\nTiempo de espera indefinido, por favor ingrese un valor menor a 9: "; cin >> N;
	};

    cout << "\nRecorrido del caballo para un tablero de " << N << "x" << N << "...\n";
    knightTour(N);

    return 0;
}


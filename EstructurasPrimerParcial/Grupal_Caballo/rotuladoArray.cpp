#include <iostream>
#include <algorithm>
using namespace std;
//REGLA DE WARNSDORFF
bool siguienteMovimiento(int &x, int &y, int tablero[N][N]) {
    int minGrado = 9, mejorMovimiento = -1;
    for (int i = 0; i < 8; i++) {
        int nextX = x + movX[i];
        int nextY = y + movY[i];
        if (esMovimientoValido(nextX, nextY, tablero)) {
            int grado = contarMovimientosDisponibles(nextX, nextY, tablero);
            if (grado < minGrado) {
                minGrado = grado;
                mejorMovimiento = i;
            }
        }
    }
    if (mejorMovimiento == -1)
        return false; // No hay movimientos válidos
    // Actualizar la posición del caballo
    x += movX[mejorMovimiento];
    y += movY[mejorMovimiento];
    return true;
}







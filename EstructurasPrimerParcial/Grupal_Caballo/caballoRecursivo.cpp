#include <iostream>

using namespace std;

#define N 5

// Prototipos
bool isSafe(int x, int y, int board[N][N]);
bool solveKnightTour(int x, int y, int moveCount, int board[N][N]);
void knightTour();

// Movimientos posibles del caballo
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    cout << "Recorrido del caballo recursivo:\n";
    knightTour();
    return 0;
}

// Verifica si la posición es válida
bool isSafe(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Backtracking para resolver el problema
bool solveKnightTour(int x, int y, int moveCount, int board[N][N]) {
    
    // Si todos los cuadrados han sido visitados, termina
    if (moveCount == N * N) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isSafe(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;

            // Llamada recursiva
            if (solveKnightTour(nextX, nextY, moveCount + 1, board)) {
                return true;
            }

            board[nextX][nextY] = -1;
        }
    }
    return false;
}

// Inicializar el recorrido
void knightTour() {
    // Inicializar el tablero con -1
    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    // Posición inicial del caballo
    int startX = 0, startY = 0;
    board[startX][startY] = 0;

    if (solveKnightTour(startX, startY, 1, board)) {
        // Imprimir el tablero
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No se encontró solución para el tablero de " << N << "x" << N << ".\n";
    }
}

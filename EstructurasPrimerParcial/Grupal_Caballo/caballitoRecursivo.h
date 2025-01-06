#include <iostream>

using namespace std;

// Movimientos posibles del caballo
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Verifica si la posición es válida
bool isSafe(int x, int y, int board[][100], int N) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Backtracking para resolver el problema
bool solveKnightTour(int x, int y, int moveCount, int board[][100], int N) {
    
    if (moveCount == N * N) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isSafe(nextX, nextY, board, N)) {
            board[nextX][nextY] = moveCount;

            // Llamada recursiva
            if (solveKnightTour(nextX, nextY, moveCount + 1, board, N)) {
                return true;
            }

            board[nextX][nextY] = -1;
        }
    }
    return false;
}

void knightTour(int N) {
    int board[100][100];
    
    // Inicializar el tablero con -1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    // Posición inicial del caballo
    int startX = 0, startY = 0;
    board[startX][startY] = 0;

    if (solveKnightTour(startX, startY, 1, board, N)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "  ";
            }
            cout << endl;
        }
    } else {
        cout << "No se encontro solucion para el tablero de " << N << "x" << N << ".\n";
    }
}


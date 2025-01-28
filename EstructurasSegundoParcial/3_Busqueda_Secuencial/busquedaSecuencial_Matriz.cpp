#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
using namespace std;
const int N = 3;
const int M = 3;
float matriz[N] [M];
int fila, col, ran;
void leerarray();
void imprimirarray();

int main(){
	int i, j, num;
	srand(time(NULL));
	printf("\nLlenando arreglo con nummeros aleatorios\n");
	
	leerarray();
		
	printf("El arreglo es:\n");
	
	printf("\n*****************MATRIZ*****************\n");
	imprimirarray();
	
	printf("\n\nNumero a buscar: ");
	scanf("%d",&num);
	
	fila = 0, col = 0;
	for(fila = 0; fila < N; ++fila){
		for(col = 0; col < M; ++col){
			if(col == 0){
				if(matriz[fila][col] == num){
					printf("\nValor %d encontrado",num);
					printf("\tPosicion: [%d][%d]",fila+1,col+1);}
				else
					printf("\nValor %d NO encontrado en la posicion [%d][%d]",num,fila+1,col+1);
			}else{
				if(matriz[fila][col] == num){
					printf("\nValor %d encontrado",num);
					printf("\tPosicion: [%d][%d]",fila+1,col+1);}
				else
					printf("\nValor %d NO encontrado en la posicion [%d][%d]",num,fila+1,col+1);
			}
		}printf("\n");
	}
	
	getch();
	system("cls");
}

void leerarray(){
	fila = 0, col = 0;
	for(fila = 0; fila < N; ++fila){
		for(col = 0; col < M; ++col){
			ran = rand()%100;
			printf("Valor para Fila: %d - Columna: %d = %d",fila+1,col+1,ran);
			matriz[fila][col] = ran;
			printf("\n");
		}printf("\n");
	}
}

void imprimirarray(){
	fila = 0, col = 0;
	for(fila = 0; fila < N; ++fila){
		for(col = 0; col < M; ++col){
			if(col == 0){
				printf("| %f | ",matriz[fila][col]);
			}else{
				printf(" %f | ",matriz[fila][col]);
			}
		}printf("\n");
	}
}

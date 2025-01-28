#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
using namespace std;

int main(){
	int a[TAM], temp, i, j, num;
	srand(time(NULL));
	printf("\nLlenando arreglo con nummeros aleatorios\n");
	
	for(i=0; i<TAM; i++)
		a[i]=rand()%100;
		
	printf("El arreglo es:\n");
	
	for(i=0; i<TAM; i++)
		printf("%d ", a[i]);
	
	printf("\n\nNumero a buscar: ");
	scanf("%d",&num);
	
	for(i=0; i<TAM; i++)
		if(a[i] == num){
			printf("\n\nValor %d encontrado",num);
			printf("\tPosicion: %d\n",i+1);}
		else
			printf("\nValor %d NO encontrado en la posicion %d",num,i+1);
	
	getch();
	system("cls");
}

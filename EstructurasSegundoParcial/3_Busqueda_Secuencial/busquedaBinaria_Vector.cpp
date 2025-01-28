#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define largo 10

main(){
	int i,j;
	float menor, AUX, valor;
	float X[largo];
	int pos_menor,alto,central,bajo;
	system("CLS"); /* Lee el vector */
	for(i=0;i<largo;i++){
		printf("X[%i] = ",i);
		scanf("%f",&X[i]); /* Ordena por Seleccion */
	}
	for(i=0;i<largo;i++){
		menor=X[i];
		pos_menor=i;
		for(j=i+1;j<largo;j++){
			if(menor>X[j]){
				menor=X[j];
				pos_menor=j;	
			}
		}
		AUX=X[i];
		X[i]=X[pos_menor];
		X[pos_menor]=AUX;
	} /*Imprime el vector */
	printf("\n");
	for(i=0;i<largo;i++){
		printf("X[%i] = %f\n",i,X[i]);
	}
	printf("\nValor a buscar: ");
	scanf("%f",&valor);
	bajo=0;alto=largo-1;central=(bajo+alto)/2;
	/* Busqueda binaria */
	while(bajo<=alto && X[central]!=valor){
		if(valor<X[central]) alto=central-1;
		else bajo=central+1;
		central=(bajo+alto)/2;
	}
	if(valor==X[central]) printf("El valor %f se encuentra en la posicion %i",valor,central);
	else printf("El valor %f no se encuentra",valor);
	getch();
}

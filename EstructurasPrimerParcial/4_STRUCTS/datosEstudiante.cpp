#include <iostream>
#include <stdio.h>
#include <ctype.h>

//STRUCTS
struct estudiante{
	char nombre[30];
	char sexo;
	int nota;
};

int main(){
	struct estudiante est[100];
	int n, nest, ap=0, re=0, nef=0, nem=0;
	float pap, prep, pf,pm;
	printf("Introduzca el numero de estudiantes: ");
	scanf("%d",&nest);
	printf("\n");
	
	for (int n = 1; n <= nest; n++){ //Registramos nest estudiantes
		printf("Nombre Estudiante: ");
		fflush(stdin);
		gets(est[n].nombre);
		do{
			printf("Sexo (f/m): ");
			fflush(stdin);
			est[n].sexo = (toupper(getchar()));
		}while(est[n].sexo != 'F' && est[n].sexo != 'M');
		
		if(est[n].sexo == 'F')
		nef++;
		
		if(est[n].sexo == 'M')
		nem++;
		
		printf("Nota: ");
		scanf("%d",&est[n].nota);
		
		if(est[n].nota >= 0 && est[n].nota <= 6)
		re++;
		else
		ap++;
		
		printf("\n");
	}
	
	pap = (ap*100)/nest; prep = (re*100)/nest; pf = (nef*100)/nest; pm = (nem*100)/nest;
	printf("\n");
	
	printf("Hay %d estudiantes APROVADOS y representan %.2f%%\n", ap, pap);
	printf("Hay %d estudiantes REPROBADOS y representan %.2f%%\n", re, prep);
	printf("Hay %d estudiantes de sexo FEMENINO y representan %.2f%%\n", nef, pf);
	printf("Hay %d estudiantes de sexo MASCULINO y representan %.2f%%\n", nem, pm);
	
	return(0);
}

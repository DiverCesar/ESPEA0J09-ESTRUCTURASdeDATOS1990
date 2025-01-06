#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
	srand(time(NULL));
	int n[20];
	int i,x;
	printf("%38s%53s\n", "POSICION", "VALOR");
	for (i=0; i<20; i++){
		//x=1+rand()%20;
		x=1+rand()%100;
		while (x%2!=1){
			x=1+rand()%100;
		}
		n[i]=x;
	}
	for (i=0; i<20; i++){
		printf("%38d%53d\n", i+1, n[i]);
	}
}

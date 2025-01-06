#include <iostream>
#include <string>

using namespace std;

int main(){
	int *punta, *puntb;
	int x = 7;
	int y = 5;
	punta = &x;
	*punta = 3; //El puntero a cambia el valor x de 7 a 3
	puntb = &y; //El puntero b apuntar a y
	*puntb = x; //El puntero b cambia el valor y de 5 al valor de x = 3
	x = 9; //La variable x cambia el valor del puntero a de 3 a 9
	puntb = punta; //Puntero a cambia el valor del puntero b de 3 a 9
	printf("%d,%d",*puntb,*punta); //¿qué imprime este printf?
	
	//Imprime el valor del puntero b asignado por el puntero a & del puntero a luego de reasginar 9
}



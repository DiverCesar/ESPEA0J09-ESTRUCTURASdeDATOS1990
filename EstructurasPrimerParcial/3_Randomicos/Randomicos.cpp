#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
	srand(time(NULL));
	int r1,r2,r3;
	cout<<"Numeros generados aleatoriamente: \n";
	r1 = (rand()%3);
	cout<<"\nEl randomico 1 es: "<<r1<<endl;
}

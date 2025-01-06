#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int j,k;
int *ptr;

int main(){
	j=1;
	k=2;
	ptr = &k;
	cout<<"j tienen el valor "<<j<<" y esta almacenado en "<<&j<<endl;
	cout<<"k tienen el valor "<<k<<" y esta almacenado en "<<&k<<endl;
	cout<<"ptr tienen el valor "<<ptr<<" y esta almacenado en "<<&ptr<<endl;
	cout<<"El valor del entero al que apunta ptr es "<<*ptr<<endl;
}

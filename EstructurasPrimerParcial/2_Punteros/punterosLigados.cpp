#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
	int in, *pt1, *pt2;
	in = 39; /*Cualquier valor numerico*/
	pt1 = &in; /*La direccion de in*/
	pt2 = pt1;
	cout<<"El valor es "<<in<<' '<<*pt1<<' '<<*pt2<<endl;
	*pt1 = 13; /*Esto cambia el valor de in*/
	cout<<"El valor es "<<in<<' '<<*pt1<<' '<<*pt2<<endl;
}

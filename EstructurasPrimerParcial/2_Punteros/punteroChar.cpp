#include <iostream>

using namespace std;

void funcion1();
void funcion2();

int main(){
	funcion1();
	funcion2();
}

void funcion1(){
	int *t;
	t = new int;
	*t = 234;
	cout<<"El contenido de t es "<<*t<<endl;
	delete t;
}

void funcion2(){
	char *a, *b;
	a = new char;
	*a = 'R';
	b = a;
	
	cout<<"-------------Parte 1----------------"<<*b<<endl;
	cout<<"El valor de a es "<<*a<<endl;
	cout<<"El valor de b es "<<*b<<endl;
	
	//Parte 2
	delete a;
	char *c;
	a = new char;
	*a = 'U';
	b = new char;
	*b = 'N';
	c = new char;
	*c = 'P';
	
	cout<<"--------------Parte 2---------------"<<*b<<endl;
	cout<<"El valor de a es "<<*a<<endl;
	cout<<"El valor de b es "<<*b<<endl;
	cout<<"El valor de c es "<<*c<<endl;
	
	//Parte 3
	char *d;
	d = a;
	a = b;
	
	d = NULL;
	cout<<"--------------Parte 3---------------"<<*b<<endl;
	cout<<"El valor de a es "<<*a<<endl;
	cout<<"El valor de b es "<<*b<<endl;
	cout<<"El valor de c es "<<*c<<endl;
	cout<<"El valor de d es "<<*d<<endl;
}

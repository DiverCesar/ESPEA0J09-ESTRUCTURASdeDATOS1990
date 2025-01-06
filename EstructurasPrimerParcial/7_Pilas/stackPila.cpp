#include <iostream>
#include <conio.h>
#include<stack>

//COLA 10345467 BANCO
//PILA 12345678 PLATOS

using namespace std;

stack <int> pila;

int main(){
	pila.push(35);
	pila.push(45);
	pila.push(3);
	pila.push(77);
	
	
	
	cout<<pila.top()<<endl;
	pila.pop();
	cout<<pila.top()<<endl;
	pila.pop(); cout<<pila.top()<<endl;
	pila.pop(); cout<<pila.top()<<endl;
	pila.pop();
	getch();
}

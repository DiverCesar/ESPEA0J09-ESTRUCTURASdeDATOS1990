#include <iostream>
#include <conio.h>
#include<stack>

using namespace std;

stack <int> pila;

int main(){
	pila.push(35);
	pila.push(45);
	pila.push(3);
	pila.push(77);
	
	while(pila.size()>0){
		cout<<pila.top()<<endl;
		pila.pop();
	}
	getch();
}

#include <iostream>
#include <conio.h>
#include<stack>

using namespace std;

stack <int> pila;
int mayor;

int main(){
	pila.push(35);
	pila.push(45);
	pila.push(3);
	pila.push(77);
	
	while(pila.size()>0){
		if(pila.size()>mayor){
			mayor=pila.top();	
		}
		pila.pop();
	}
	cout<<mayor<<endl;
}

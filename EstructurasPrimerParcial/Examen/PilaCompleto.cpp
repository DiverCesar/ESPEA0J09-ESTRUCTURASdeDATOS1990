#include <iostream>
#include <conio.h>
#include <time.h> //randomico
#include <stdlib.h> //randomico
#include<stack>

using namespace std;

stack <int> pila;
int mayor;

int main(){
	srand(time(NULL));
	pila.push(35);
	pila.push(45);
	pila.push(3);
	pila.push(77);
	pila.push((rand()%100));
	
	cout<<pila.top()<<endl;
	pila.pop(); cout<<pila.top()<<endl;
	
	while(pila.size()>0){
		cout<<pila.top()<<endl;
		pila.pop();
	}
	
	while(pila.size()>0){
		if(pila.size()>mayor){
			mayor=pila.top();	
		}
		pila.pop();
	}
	cout<<mayor<<endl;
}

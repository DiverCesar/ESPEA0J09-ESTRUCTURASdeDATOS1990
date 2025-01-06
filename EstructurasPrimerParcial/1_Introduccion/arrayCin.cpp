#include <iostream>

using namespace std;

int main(){
	int i,x,tabla[4];
	for (x=0;x<=4;x++){
		cout<<"Ingrese el valor numero "<<x+1<<" de la tabla: ";
		cin>>i;
		tabla[x]=i;
	}
	for (x=0;x<=4;x++){
		cout<<"Valor numero "<<x+1<<" :"<<tabla[x]<<endl;
	}
}

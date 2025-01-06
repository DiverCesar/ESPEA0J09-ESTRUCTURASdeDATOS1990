#include <iostream>

using namespace std;

int main(){
	char *pNotas = NULL;
	int tam;
	
	cout <<"Cuantas notas desea almacenar: "<<endl;
	cin>>tam;
	pNotas = new char[tam];
	
	for (int i=0; i<tam; i++){
		cout<<"Ingrese la Nota "<<i+1<<": ";
		cin>>pNotas[i];
	}
	for (int i=0; i<tam; i++){
		cout<<pNotas[i]<<" ";
	}
	delete[]pNotas;
}

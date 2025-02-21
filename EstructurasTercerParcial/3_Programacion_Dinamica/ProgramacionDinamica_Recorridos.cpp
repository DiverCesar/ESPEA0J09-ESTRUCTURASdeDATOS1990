#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> numeros = {5, 10, 15, 20, 25};
	
	cout<<"Recorriendo con for basado en rango: ";
	
	//forma vector 
	for(int num:numeros){
		cout<<num<<" ";
	}
	
	cout<<endl;
	
	
	//forma tradicional
	cout<<"Recorriendo con for tradicional: ";
	for(size_t i=0; i<numeros.size(); i++){
		cout<<numeros[i]<<" ";
	}
	cout<< endl;
	return 0;
}

#include <iostream>
using namespace std;

//Funcion de ordenamiento por intercambio exchangeSort
void exchangeSort(int arr[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(){
	int n;
	
	cout<<"Cantidad de numeros ordenados: ";cin>>n;
	int arreglo[n];
	cout<<"\nIngrese los elementos del arreglo: \n";
	for (int i = 0; i < n; i++){
		cout<<i<<": ";cin>>arreglo[i];
	}
	
	int tamanio = sizeof(arreglo) / sizeof(arreglo[0]);
	
	//Llamar a la funcion exchangeSort
	exchangeSort(arreglo, tamanio);
	
	cout<<"\nArreglo ordenado: "<<endl;
	for (int i = 0; i < tamanio; i++){
		cout<<arreglo[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

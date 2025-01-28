#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//Funcion de ordenamiento por intercambio bubbleSort
void bubbleSort(int arr[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(){
	int n;
	srand(time(NULL));
	
	cout<<"Cantidad de numeros ordenados: ";cin>>n;
	int arreglo[n];
	cout<<endl;
	for (int i = 0; i < n; i++){
		arreglo[i] = rand()%100+1;
		cout<<i<<": "<<arreglo[i]<<endl;
	}
	
	int tamanio = sizeof(arreglo) / sizeof(arreglo[0]);
	
	//Llamar a la funcion bubbleSort
	bubbleSort(arreglo, tamanio);
	
	cout<<"\nArreglo ordenado: "<<endl;
	for (int i = 0; i < tamanio; i++){
		cout<<arreglo[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

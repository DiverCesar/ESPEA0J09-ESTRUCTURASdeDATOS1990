#include<iostream>

using namespace std;

long long potencia(int a, int b){
	cout << "Calculando " << a << "^" << b << "..." << endl;
	if(b == 0) return 1;
	return a * potencia(a, b - 1);
}

int main(){
	cout << "Sin memoización: " << endl;
	cout << "Resultado: " << potencia(2, 10) << endl;
	cout << "Resultado: " << potencia(2, 10) << endl; //Se recalcula innecesariamente
	
	return 0;
}

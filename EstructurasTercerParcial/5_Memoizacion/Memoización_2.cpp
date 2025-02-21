#include<iostream>
#include<unordered_map>

using namespace std;

//Mapa para almacenar resultado previamente calculados

unordered_map<string, long long> memo;

long long potenciaMemoizada(int a, int b){
	//Crear una clave única para cada combinación (a, b)
	string key = to_string(a) + "," + to_string(b);
	
	//Si ya se calculó antes, devolverlo directamente
	if(memo.find(key) != memo.end()){
		cout << "Usando memoizacion para " << a << "^" << b << "..." << endl;
		return memo[key];
	}
	
	//Calcular y almacenar el resultado
	cout << "Calculando " << a << "^" << b << "..." << endl;
	if(b == 0) return 1;
	memo[key] = a * potenciaMemoizada(a, b - 1);
	return memo[key];
}

int main(){
	cout << "\nCon memoizacion: " << endl;
	cout << "Resultado: " << potenciaMemoizada(2, 10) << endl;
	cout << "Resultado: " << potenciaMemoizada(2, 10) << endl;
	return 0;
}

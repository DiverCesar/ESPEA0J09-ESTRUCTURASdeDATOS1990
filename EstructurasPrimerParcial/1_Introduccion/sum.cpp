#include<iostream>
using namespace std;
int sum(){
	int A,B,r;
	cout << "Numero A (suma): " ; cin >> A;
	cout << "Numero B (suma): " ; cin >> B;
	r = A+B;
	return r;
}

int mult(){
	int A,B,r;
	cout << "Numero A (multiplicacion): " ; cin >> A;
	cout << "Numero B (multiplicacion): " ; cin >> B;
	r = A*B;
	return r;
}

int main(){
	int r;
	r = sum()+mult();
	cout << "Resultado suma + multiplicacion: " << r;
}


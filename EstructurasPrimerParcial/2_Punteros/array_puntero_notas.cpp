#include<iostream>
#include<conio.h>

using namespace std;

void pedirNotas();
int *calif;
void mostrarNotas();
int numCalif;

int main()
{
	pedirNotas();
	mostrarNotas();
	delete[]calif;
	
	getch();
	return 0;
}

void pedirNotas(){
	cout << "Ingrese una nota: " << endl;
	cin >> numCalif;
	calif = new int(numCalif);
	
for(int i = 0; i < numCalif; i++){
	cout << "Ingrese una nota: " << endl;
	cin >> calif[i];
}
}

void mostrarNotas(){
	cout << "Notas" << endl;
	for(int i = 0; i < numCalif; i++){
		cout << calif[i] << endl;
	}
}

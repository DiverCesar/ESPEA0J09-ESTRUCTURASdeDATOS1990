#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

#define MAX 100

//STRUCTS
struct paciente{
	string nombrepac;
	string apellido;
	int cedula;
	int telefono;
};
paciente *datosPaciente = new paciente[MAX];

int main(){
	for (int i = 0; i < 3; i++){ //Registramos 3 pacientes
		cout << "\nLista del paciente ["<< i + 1 << "]:\n" <<endl;
		cout << "Ingrese su nombre: " <<endl;
		cin >> datosPaciente[i].nombrepac;
		cout << "Ingrese su apelldo: " <<endl;
		cin >> datosPaciente[i].apellido;
		cout << "Ingrese su CEDULA: " <<endl;
		cin >> datosPaciente[i].cedula;
		cout << "Ingrese su numero de telefono: " <<endl;
		cin >> datosPaciente[i].telefono;
	}
	for (int i = 0; i < 3; i++){ //Listamos 3 pacientes
		cout << "\nLos datos del paciente ["<< i + 1 << "] es:\n" <<endl;
		cout << "Nombres: " << datosPaciente[i].nombrepac <<endl;
		cout << "Apellidos: " << datosPaciente[i].apellido <<endl;
		cout << "CEDULA: " << datosPaciente[i].cedula <<endl;
		cout << "Celular: " << datosPaciente[i].telefono <<endl;
	}
	getch();
	system("cls");
}

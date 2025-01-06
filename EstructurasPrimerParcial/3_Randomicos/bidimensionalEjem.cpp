#include <iostream>
using namespace std;
const int N = 2; //Se declara una constante de tipo entero (Hay que recordar que estos se necesitaran para la declaracion del arreglo)
const int M = 2;
float matriz[N] [M]; //Se declara un arreglo de dos dimensiones
int fila, col; //Se declaran dos variables las cuales ser�n usadas para localizar las filas y las columnas
void leerarray(); //Declaraci�n de la funci�n para leer el arreglo
void imprimirarray(); //Declaraci�n de la funci�n para realizar la impresi�n del arreglo
int main()
{
 leerarray(); //Se llama la funci�n de leer arreglo
 cout << endl; //EL endl se utiliza para hacer un salto de l�nea, lo que tambi�n podemos hacer con \n, para ejemplificar se utilizar�n ambas
 cout << "*****************MATRIZ*****************" << endl; //Se imprime un texto en consola
 imprimirarray(); //Se llama la funci�n para hacer la impresi�n del array
}
void leerarray()
{
 fila = 0, col = 0;
 for(fila = 0; fila < N; ++fila)
 {
 for(col = 0; col < M; ++col)
 {
 cout << "Introduca los valores para Fila: " << fila+1 << " - Columna: " << col+1 << " = "; //Se pide al usuario que ingrese el valor para la fila y columna indicada
 cin >> matriz[fila][col]; //Se realiza la lectura desde teclado (n�tese que en los corchetes, al igual que en los ciclos for, primero se pone la fila y despu�s la columna)
 }
 cout << endl; //Se imprime un salto de l�nea
 }
}
/* NOTA: para leer un arreglo de dos dimensiones necesitamos dos ciclos for, el primero de
utilizar� para avanzar en las FILAS y el segundo se utilizar� para las COLUMNAS */
void imprimirarray()
{
 fila = 0, col = 0;
 for(fila = 0; fila < N; ++fila)
 {
 for(col = 0; col < M; ++col)
 {
 if(col == 0) //Condicional if utilizada para comprobar si el valor es de la primera columna de cada fila, esto para poder agregar un detalle visual al inicio
 {
 cout << "| " << matriz[fila][col] << " | "; //Se imprime el valor de la fila y columna indicado
 }
 else //Si no se cumple la condici�n del if (que sea el valor de la primera columna de cada fila), se realizan estas operaciones
 {
 cout << matriz[fila][col] << " | ";
 }
 }
 cout << endl;
 }
}

//Galarza Cesar

//##############################################//
//################# LIBRERIAS ##################//
//##############################################//

//#################### Menú y Búsqueda Hash #####################//
#include <iostream>
#include <conio.h>

//##### Búsqueda Secuencial UNIdimensional y BIdimensional #####//
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

//###### Búsqueda Binaria UNIdimensional y BIdimensional #######//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define largo 10
#define FILAS 3
#define COLUMNAS 3

using namespace std;

//##############################################//
//################# PROTOTIPOS #################//
//##############################################//

//#################### Menú ####################//
void menu();

//##### Búsqueda Secuencial UNIdimensional #####//
void busquedaSecuencial_Vector();

//##### Búsqueda Secuencial BIdimensional ######//
const int N = 3;
const int M = 3;
float matriz[N] [M];
int fila, col, ran;
void leerarray();
void imprimirarray();
void busquedaSecuencial_Matriz();

//###### Búsqueda Binaria UNIdimensional #######//
void busquedaBinaria_Vector();

//####### Búsqueda Binaria BIdimensional #######//
void imprimirMatriz(float matriz[FILAS][COLUMNAS]);
void busquedaBinaria_Matriz();

//############### Búsqueda Hash ################//
struct Alumno { 
	char nombre[60];
	int nota;
	int estado=0; //VERIFICAR
	int clave; 
};
int insertar(Alumno* A, Alumno* B, int, int); //NODO ALUMNO 
int buscaHash(Alumno* A, int, int);
void busquedaHash();

//##############################################//
//########## PROGRAMA PRINCIPAL ################//
//##############################################//
int main(){
	menu();
	getch();
	return 0;
}

//##############################################//
//#################### MENÚ ####################//
//##############################################//
void menu(){
	int opcion, dato, num, datoBuscar, option1, option2;
	do{
		cout<<"*._______________________________.*"<<"    _   "<<endl;
		cout<<"|         CESAR GALARZA           |"<<"   (o<  "<<endl;
		cout<<"|           NRC 1990              |"<<"   //)  "<<endl;
		cout<<"*._______________________________.*"<<"   V_/_ "<<endl<<endl;
		cout<<"*.____________________________________________.*"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|############### MENU BUSQUEDAS ###############|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|----------------------------------------------|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|########### 1. BUSQUEDA SECUENCIAL ###########|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|############ 2. BUSQUEDA BINARIA #############|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|############## 3. BUSQUEDA HASH ##############|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|################## 4. SALIR ##################|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"*.____________________________________________.*"<<endl;
		cout<<"\nIngrese su opcion: "; cin>>opcion;
		switch(opcion){
			case 1:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############ BUSQUEDA SECUENCIAL #############|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|----------------------------------------------|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|### 1. BUSQUEDA SECUENCIAL UNIDIMENSIONAL ####|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|#### 2. BUSQUEDA SECUENCIAL BIDIMENSIONAL ####|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|################ 3. REGRESAR #################|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"\nIngrese su opcion: "; cin>>option1;
				switch(option1){
					case 1:
						busquedaSecuencial_Vector();
						cout<<endl;
						system("pause");
						break;
					case 2:
						busquedaSecuencial_Matriz();
						cout<<endl;
						system("pause");
						break;
					case 3:
						cout<<endl;
						system("pause");
						break;
					default:
						cout << endl << endl << "Opcion no valida" << endl << endl;
						cout<<endl;
						system("pause");
						break;
				}
				system("cls");
				break;
			case 2:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############## BUSQUEDA BINARIA ##############|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|----------------------------------------------|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|#### 1. BUSQUEDA BINARIA UNIDIMENSIONAL ######|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|###### 2. BUSQUEDA BINARIA BIDIMENSIONAL #####|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|################ 3. REGRESAR #################|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"\nIngrese su opcion: "; cin>>option2;
				switch(option2){
					case 1:
						busquedaBinaria_Vector();
						cout<<endl;
						system("pause");
						break;
					case 2:
						busquedaBinaria_Matriz();
						cout<<endl;
						system("pause");
						break;
					case 3:
						cout<<endl;
						system("pause");
						break;
					default:
						cout << endl << endl << "Opcion no valida" << endl << endl;
						cout<<endl;
						system("pause");
						break;
				}
				system("cls");
				break;
			case 3:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############### BUSQUEDA HASH ################|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				busquedaHash();
				break;
			case 4:
				cout << endl << endl;
				system("cls");
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############ PROGRAMA FINALIZADO #############|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<<endl;
				system("pause");
				break;
			default:
				cout << endl << endl << "Opcion no valida" << endl << endl;
				cout<<endl;
				system("pause");
				break;
		}
	}while(opcion !=4);
}

//##### Búsqueda Secuencial UNIdimensional #####//
void busquedaSecuencial_Vector(){
	int a[TAM], temp, i, j, num;
	srand(time(NULL));
	printf("\nLlenando arreglo con nummeros aleatorios\n");
	
	for(i=0; i<TAM; i++)
		a[i]=rand()%100;
		
	printf("El arreglo es:\n");
	
	for(i=0; i<TAM; i++)
		printf("%d ", a[i]);
	
	printf("\n\nNumero a buscar: ");
	scanf("%d",&num);
	
	for(i=0; i<TAM; i++)
		if(a[i] == num){
			printf("\n\nValor %d encontrado",num);
			printf("\tPosicion: %d\n",i+1);}
		else
			printf("\nValor %d NO encontrado en la posicion %d",num,i+1);
	printf("\n");
}

//##### Búsqueda Secuencial BIdimensional ######//
void leerarray(){
	fila = 0, col = 0;
	for(fila = 0; fila < N; ++fila){
		for(col = 0; col < M; ++col){
			ran = rand()%100;
			printf("Valor para Fila: %d - Columna: %d = %d",fila+1,col+1,ran);
			matriz[fila][col] = ran;
			printf("\n");
		}printf("\n");
	}
}
void imprimirarray(){
	fila = 0, col = 0;
	for(fila = 0; fila < N; ++fila){
		for(col = 0; col < M; ++col){
			if(col == 0){
				printf("| %f | ",matriz[fila][col]);
			}else{
				printf(" %f | ",matriz[fila][col]);
			}
		}printf("\n");
	}
}
void busquedaSecuencial_Matriz(){
	int i, j, num;
	srand(time(NULL));
	printf("\nLlenando arreglo con nummeros aleatorios\n");
	
	leerarray();
		
	printf("El arreglo es:\n");
	
	printf("\n*****************MATRIZ*****************\n");
	imprimirarray();
	
	printf("\n\nNumero a buscar: ");
	scanf("%d",&num);
	
	fila = 0, col = 0;
	for(fila = 0; fila < N; ++fila){
		for(col = 0; col < M; ++col){
			if(col == 0){
				if(matriz[fila][col] == num){
					printf("\n");
					printf("\nValor %d encontrado",num);
					printf("\tPosicion: [%d][%d]",fila+1,col+1);
					printf("\n");}
				else
					printf("\nValor %d NO encontrado en la posicion [%d][%d]",num,fila+1,col+1);
			}else{
				if(matriz[fila][col] == num){
					printf("\n");
					printf("\nValor %d encontrado",num);
					printf("\tPosicion: [%d][%d]",fila+1,col+1);
					printf("\n");}
				else
					printf("\nValor %d NO encontrado en la posicion [%d][%d]",num,fila+1,col+1);
			}
		}printf("\n");
	}
}

//###### Búsqueda Binaria UNIdimensional #######//
void busquedaBinaria_Vector(){
	int i,j;
	float menor, AUX, valor;
	float X[largo];
	int pos_menor,alto,central,bajo;
	system("CLS"); /* Lee el vector */
	for(i=0;i<largo;i++){
		printf("X[%i] = ",i);
		scanf("%f",&X[i]); /* Ordena por Seleccion */
	}
	for(i=0;i<largo;i++){
		menor=X[i];
		pos_menor=i;
		for(j=i+1;j<largo;j++){
			if(menor>X[j]){
				menor=X[j];
				pos_menor=j;	
			}
		}
		AUX=X[i];
		X[i]=X[pos_menor];
		X[pos_menor]=AUX;
	} /*Imprime el vector */
	printf("\n");
	for(i=0;i<largo;i++){
		printf("X[%i] = %f\n",i,X[i]);
	}
	printf("\nValor a buscar: ");
	scanf("%f",&valor);
	bajo=0;alto=largo-1;central=(bajo+alto)/2;
	/* Busqueda binaria */
	while(bajo<=alto && X[central]!=valor){
		if(valor<X[central]) alto=central-1;
		else bajo=central+1;
		central=(bajo+alto)/2;
	}
	if(valor==X[central]) printf("El valor %f se encuentra en la posicion %i",valor,central);
	else printf("El valor %f no se encuentra",valor);
}

//####### Búsqueda Binaria BIdimensional #######//
void imprimirMatriz(float matriz[FILAS][COLUMNAS]){
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}
void busquedaBinaria_Matriz(){
    int i, j, totalElementos = FILAS * COLUMNAS;
    float menor, AUX, valor;
    float matriz[FILAS][COLUMNAS];
    float lineal[totalElementos]; 
    int pos_menor, alto, central, bajo;
    int bandera = 0;
	system("CLS"); /* Lee el vector */
    printf("Ingrese los elementos de la matriz (%d filas x %d columnas):\n\n", FILAS, COLUMNAS);
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    // Ordenamiento del arreglo lineal
    int idx = 0;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            lineal[idx++] = matriz[i][j];
        }
    }

    for (i = 0; i < totalElementos - 1; i++) {
        menor = lineal[i];
        pos_menor = i;
        for (j = i + 1; j < totalElementos; j++) {
            if (lineal[j] < menor) {
                menor = lineal[j];
                pos_menor = j;
            }
        }
        AUX = lineal[i];
        lineal[i] = lineal[pos_menor];
        lineal[pos_menor] = AUX;
    }

    printf("\nArreglo ordenado:\n");
    for (i = 0; i < totalElementos; i++) {
        printf("%f ", lineal[i]);
    }
    printf("\n");

    // BÃºsqueda binaria con banderas para valores repetidos
    printf("\nValor a buscar: ");
    scanf("%f", &valor);
    bajo = 0;
    alto = totalElementos - 1;
    central = (alto + bajo) / 2;

    while (bajo <= alto && lineal[central] != valor) {
        if (valor < lineal[central]) {
            alto = central - 1;
        } else {
            bajo = central + 1;
        }
        central = (alto + bajo) / 2;
    }

    if (lineal[central] == valor) {
        printf("El valor %f se encuentra en la posicion ",valor);
        bandera = 1;

    // Verificar hacia la izquierda del Ã­ndice central
        int izquierda = central;
        while (izquierda >= 0 && lineal[izquierda] == valor) {
            printf("%d ", izquierda+1);
            izquierda--;
        }
        
        // Verificar hacia la derecha del Ã­ndice central
        int derecha = central + 1;
        while (derecha < totalElementos && lineal[derecha] == valor) {
            printf("%d ", derecha+1);
            derecha++;
        }
        printf("\n");
    }

    if (!bandera) {
        printf("El valor %f no se encuentra en la matriz\n",valor);
    }
}

//############### Búsqueda Hash ################//
int insertar(Alumno* A, Alumno* B, int i, int n){ 
    int j = (A[i].nota + 1) % n;
    while (B[j].estado == 1) {
        j = (j + 1) % n;
    }
    B[j] = A[i];
    B[j].estado = 1;
    B[j].clave = j;
    return j;
}
int buscaHash(Alumno* B, int n, int clave){
    int j = clave % n;
    for (int i = 0; i < n; i++) {
        if (B[j].estado == 1 && B[j].clave == clave) {
            return j;
        }
        j = (j + 1) % n;
    }
    return -1;
}
void busquedaHash(){
    int op = 0, n, clave, x;
    do {
        cout << "\nINGRESAR CANTIDAD DE ALUMNOS: ";
        cin >> n;
    } while (n <= 0); // Solo números positivos
    Alumno* A = new Alumno[n]; // Array para almacenar datos
    Alumno* B = new Alumno[n]; // Tabla hash
    for (int i = 0; i < n; i++) {
        B[i].estado = 0; // Inicializar tabla hash como vacía
    }
    system("CLS");
    do {
        cout << "\t\n";
        cout << "\t-----------------------\n";
        cout << "\t 1.INSERTAR | 2.BUSCAR \n";
        cout << "\t        3.SALIR        \n";
        cout << "\t-----------------------\n\n";
        cout << "\t    INGRESE OPCION:    \n";
        cout << "\t";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            for (int i = 0; i < n; i++) {
                cout << "INGRESE DATOS ALUMNO " << i + 1 << endl;
                fflush(stdin); // Limpiar buffer
                cout << "NOMBRE: ";
                cin.getline(A[i].nombre, 50); // Leer nombre
                do {
                    cout << "NOTA: ";
                    cin >> A[i].nota;
                } while (A[i].nota < 0 || A[i].nota > 20); // Validar nota en rango

                A[i].clave = insertar(A, B, i, n); // Insertar en tabla hash
                cout << "CLAVE: " << A[i].clave << endl << endl;
            }
            break;
        case 2:
            cout << "INTRODUZCA EL CODIGO QUE DESEA BUSCAR: ";
            cin >> clave;
            x = buscaHash(B, n, clave); // Buscar en la tabla hash
            if (x == -1) {
                cout << "Numero " << clave << " NO encontrado" << endl;
            } else {
                cout << "NUMERO " << clave << " ENCONTRADO" << endl;
                cout << "NOMBRE: " << B[x].nombre << endl;
                cout << "NOTA: " << B[x].nota << endl;
            }
            break;
        case 3:
			break;
        default:
            cout << "\n\nOPCION NO CORRECTA\n\n";
            system("PAUSE");
        }
    } while (op != 3);
    delete[] A;
    delete[] B;
}

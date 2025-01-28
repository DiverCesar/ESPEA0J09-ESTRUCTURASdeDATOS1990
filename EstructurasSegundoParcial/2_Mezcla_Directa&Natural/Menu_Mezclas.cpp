//Galarza Cesar
//Simbaña Michael

//##############################################//
//################ LIBRERIAS ###################//
//##############################################//

//########## Menú y Mezcla Directa #############//
#include <iostream>
#include <conio.h>

//############## Mezcla Natural ################//
//mezcla.c: Ordenamiento de archivos secuenciales
// Ordena ficehros de texto por orden alfabetico de lineas
// Usando el algortimo de mezcla natural
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

//##############################################//
//############### PROTOTIPOS ###################//
//##############################################//

//################## Menú ######################//
void menu();

//############## Mezcla Directa ################//
int a[50];
void merge(int,int,int);
void mezcla_directa();

//########### Mezcla Natural Uno ##############//
void Mostrar(FILE *fich);
void Mezcla(FILE *fich);
void Separar(FILE *fich, FILE **aux);
int Mezclar(FILE *fich, FILE **aux);
void mezcla_natural_uno();

//########### Mezcla Natural Dos ##############//
struct stRegistro {
	char valido; 
	char nombre[34];
	int dato[4];
};
int Menu();
void Leer(struct stRegistro *reg); void Mostrar(struct stRegistro *reg);
void Listar(long n, struct stRegistro *reg);
long LeeNumero();
void Empaquetar(FILE **fa);
void Ordenar(FILE *fa);
void Intercambia (FILE *fa, long iz, long de);
char *LeeCampo (FILE *fa, long n, char *buf);
void QuickSort(FILE *fa, long inicio, long final);
void mezcla_natural_dos();

//##############################################//
//########## PROGRAMA PRINCIPAL ################//
//##############################################//
int main(){
	menu();
	getch();
	return 0;
}

//##############################################//
//################# MENÚ #######################//
//##############################################//
void menu(){
	int opcion, dato, num, datoBuscar;
	do{
		cout<<"*._______________________________.*"<<"    _   "<<endl;
		cout<<"|         CESAR GALARZA           |"<<"   (o<  "<<endl;
		cout<<"|        MICHAEL SIMBANA          |"<<"   //)  "<<endl;
		cout<<"|           NRC 1990              |"<<"   V_/_ "<<endl;
		cout<<"*._______________________________.*"<<endl;
		cout<<"*.____________________________________________.*"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|################ MENU MEZCLAS ################|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|----------------------------------------------|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|############# 1. MEZCLA DIRECTA ##############|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|########### 2. MEZCLA NATURAL UNO ############|"<<endl;
		cout<<"|##############################################|"<<endl;
		cout<<"|########### 3. MEZCLA NATURAL DOS ############|"<<endl;
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
				cout<<"|################ MEZCLA DIRECTA ##############|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				mezcla_directa();
				cout<<endl;
				system("pause");
				break;
			case 2:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############## MEZCLA NATURAL UNO ############|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				mezcla_natural_uno();
				cout<<endl;
				system("pause");
				break;
			case 3:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############## MEZCLA NATURAL DOS ############|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
				mezcla_natural_dos();
				cout<<endl;
				system("pause");
				break;
			case 4:
				cout << endl << endl;
				cout<<"*.____________________________________________.*"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"|############# PROGRAMA FINALIZADO ############|"<<endl;
				cout<<"|##############################################|"<<endl;
				cout<<"*.____________________________________________.*"<<endl<< endl;
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
	}while(opcion !=4);
}

//##############################################//
//############ MEZCLA DIRECTA ##################//
//##############################################//
void merge_sort(int izquierda, int derecha){
	int medio;
	if(izquierda<derecha){
		medio=(izquierda+derecha)/2;
		merge_sort(izquierda,medio);
		merge_sort(medio+1,derecha);
		merge(izquierda,medio,derecha);
	}
}

void merge(int izquierda, int medio, int derecha){
	int h,i,j,b[50],k;
	h=izquierda;i=izquierda;j=medio+1;
	while((h<=medio)&&(j<=derecha)){
		if(a[h]<=a[j]){
			b[i]=a[h];
			h++;
		}else{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>medio){
		for(k=j;k<=derecha;k++){
			b[i]=a[k];
			i++;
		}
	}else{
		for(k=h;k<=medio;k++){
			b[i]=a[k];
			i++;
		}
	}
	for(k=izquierda;k<=derecha;k++){
		a[k]=b[k];
	}
}

void mezcla_directa(){
	int num,i;
	cout<<endl;
	cout<<"INGRESE LA CANTIDAD DE ELEMENTOS: ";
	cin>>num;
	cout<<endl;
	cout<<"LOS ELEMENTOS SON:"<<endl;
	for(i=1;i<=num;i++){
		cin>>a[i];
	}
	merge_sort(1,num);
	cout<<endl<<endl<<endl;
	cout<<"EL NUEVO ORDEN DE ELEMENTOS ES:"<<endl;
	for(i=1;i<=num;i++){
		cout<<a[i]<<"  ";
	}
}

//##############################################//
//########### MEZCLA NATURAL UNO ###############//
//##############################################//
void mezcla_natural_uno(){
	FILE *fichero;
	
	fichero = fopen("mezcla.txt","r+");
	puts("Fichero desordenado\n");
	Mostrar(fichero);
	puts("Ordenando fichero\n");
	Mezcla(fichero);
	puts("Fichero ordenado\n");
	Mostrar(fichero);
	fclose(fichero);
}

//Muestra el contenido del fichero "fich"
void Mostrar(FILE *fich){
	char linea[128];
	rewind(fich);
	fgets(linea, 128, fich);
	while(!feof(fich)){
		puts(linea);
		fgets(linea, 128, fich);
	}
}

//Algoritmo de mezcla:
void Mezcla(FILE *fich){
	int ordenado;
	FILE *aux[2];
	
	//Bucle que se repite hasta que el fichero este ordenado
	do{
		//Crea los dos ficheros auxiliares para separar los tramos:
		aux[0]=fopen("aux1.txt","w+");
		aux[1]=fopen("aux2.txt","w+");
		rewind(fich);
		Separar(fich,aux);
		rewind(aux[0]);
		rewind(aux[1]);
		rewind(fich);
		ordenado=Mezclar(fich,aux);
		fclose(aux[0]);
		fclose(aux[1]);
	}while(!ordenado);
	
	//Elimina los ficheros auxiliares:
	remove("aux1.txt");
	remove("aux2.txt");
}

//Separar los tramos ordenados alterando entre los ficheros auxiliares:
void Separar(FILE *fich, FILE **aux){
	char linea[128],anterior[2][128];
	int salida=0;
	
	//Valores iniciales para los ultimos valores
	//almacenados en los ficheros auxiliares
	strcpy(anterior[0],"");
	strcpy(anterior[1],"");
	//Captura la primera linea:
	fgets(linea, 128, fich);
	while(!feof(fich)){
		//Decide a que fichero de salida corresponde la linea leida:
		if(salida==0 && strcmp(linea,anterior[0])<0) salida=1;
		else if(salida==1 && strcmp(linea,anterior[1])<0) salida=0;
		//Almacena la lina actual como la ultima anadida;
		strcpy(anterior[salida],linea);
		//Anade la linea al fichero auxiliar:
		fputs(linea,aux[salida]);
		//Lee la siguiente linea:
		fgets(linea, 128, fich);
	}
}

//Mezcla los ficheros auxiliares:
int Mezclar(FILE *fich, FILE **aux){
	char ultima[128], linea[2][128], anterior[2][128];
	int entrada;
	int tramos=0;
	
	//Lee la primera linea de cada fichero auxiliar:
	fgets(linea[0], 128, aux[0]);
	fgets(linea[1], 128, aux[1]);
	//Valores iniciales;
	strcpy(ultima,"");
	strcpy(anterior[0],"");
	strcpy(anterior[1],"");
	//Bucle, mientras no se acabe ninguno de los ficheros auxiliares
	//(quedan tramos por mezclar):
	while(!feof(aux[0]) && !feof(aux[1])){
		//Selecciona la linea que se anadira:
		if(strcmp(linea[0],linea[1])<=0) entrada=0; else entrada=1;
		//Almacena el valor como el ultimo anadido:
		strcpy(anterior[entrada],linea[entrada]);
		//Anade la linea al fichero:
		fputs(linea[entrada],fich);
		//Lee la siguiente linea del fichero auxiliar:
		fgets(linea[entrada], 128, aux[entrada]);
		//Verificar fin del tramo, si es asi copiar al resto del otro tramo:
		if(strcmp(anterior[entrada],linea[entrada])>0){
			if(!entrada) entrada=1; else entrada=0;
			tramos++;
			//Copia lo que queda del tramo actual al fichero de salida:
			do{
				strcpy(anterior[entrada],linea[entrada]);
				fputs(linea[entrada],fich);
				fgets(linea[entrada], 128, aux[entrada]);
			}while(!feof(aux[entrada]) && strcmp(anterior[entrada],linea[entrada])<=0);
		}
	}

	//Anadimos tramos que queden sin mezclar:
	if(!feof(aux[0])) tramos++;
	while(!feof(aux[0])){
		fputs(linea[0],fich);
		fgets(linea[0], 128, aux[0]);
	}
	if(!feof(aux[1])) tramos++;
	while(!feof(aux[1])){
		fputs(linea[1],fich);
		fgets(linea[1], 128, aux[1]);
	}
	return(tramos==1);
}

//##############################################//
//########### MEZCLA NATURAL DOS ###############//
//##############################################//
void mezcla_natural_dos()
{
struct stRegistro reg;
FILE *fa;
int opcion;
long numero;
fa = fopen("alea.dat", "r+b");
if(!fa) fa = fopen("alea.dat", "w+b"); 
do {
	opcion = Menu();
	switch(opcion) {
		
		case '1': // Añadir registro
			Leer(&reg);
			fseek(fa, 0, SEEK_END);
			fwrite(&reg, sizeof(struct stRegistro), 1, fa);
			break;
		case '2': // Mostrar registro
			system("cls");
			printf("Mostrar registro: ");
			numero = LeeNumero();
			fseek(fa, numero* sizeof(struct stRegistro), SEEK_SET);
			fread(&reg, sizeof(struct stRegistro), 1, fa);
			Mostrar(&reg);
			break;
		case '3': // Eliminar registro
			system("cls");
			printf("Eliminar registro: ");
			numero = LeeNumero();
			fseek(fa, numero* sizeof(struct stRegistro), SEEK_SET);
			fread(&reg, sizeof(struct stRegistro), 1, fa);
			reg.valido = 'N';
			fseek(fa, numero* sizeof(struct stRegistro), SEEK_SET);
			fwrite(&reg, sizeof(struct stRegistro), 1, fa);
			break;
		case '4': // Mostrar todo
			rewind(fa);
			numero = 0;
			system("cls");
			printf("Nombre   Datos\n");
			while(fread(&reg, sizeof(struct stRegistro), 1, fa))
			Listar (numero++, &reg);
			system("PAUSE");
			break;
		case '5': // Eliminar marcados
			Empaquetar(&fa);
			break;
		case '6': // Ordenar
			Empaquetar(&fa);
			Ordenar(fa);
			break;
		}
	} while(opcion != '0');
	fclose(fa);
}

int Menu(){
	
	char resp[20];
	do {
		system("cls");
		printf("MENU PRINCIPAL\n");
		printf("--------------\n\n");
		printf("1- Insertar registro\n");
		printf("2- Mostrar registro\n");
		printf("3- Eliminar registro\n");
		printf("4- Mostrar todo\n");
		printf("5- Eliminar registros marcados\n");
		printf("6- Ordenar fichero\n");
		printf("0- Salir\n");
		fgets(resp, 20, stdin);
	} while(resp[0] < '0' && resp[0]> '6');
	return resp[0];
}
// Permite que el usuario introduzca un registro por pantalla
void Leer(struct stRegistro *reg)
{
	int i;
	char numero[6];
	system("cls");
	printf("Leer registro:\n\n");
	reg->valido = 'S';
	printf("Nombre: ");
	fgets(reg->nombre, 34, stdin);
	// la función fgets captura el retorno de línea, hay que eliminarlo:
	for(i= strlen(reg->nombre)-1; i && reg->nombre [i] < ' '; i--)
	reg->nombre[i] = 0;
	for(i = 0; i < 4; i++) {
	printf("Dato[%1d]: ", i);
	fgets(numero, 6, stdin);
	reg->dato[i] = atoi(numero);
	}
}

// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(struct stRegistro *reg)
{
	int i;
	system("cls");
	if(reg->valido == 'S') {
		printf("Nombre: %s\n", reg->nombre);
		for(i = 0; i < 4; i++)
		printf("Dato[%1d]: %d\n", i, reg->dato[i]);
	}
	system("PAUSE");
}
// Muestra un registro por pantalla en forma de listado,
// si no está marcado como borrado
void Listar(long n, struct stRegistro *reg)
{
	int i;
	if(reg->valido == 'S') {
	printf("[%6ld] %-34s", n, reg->nombre);
	for(i = 0; i < 4; i++) printf(", %4d", reg->dato[i]);
	printf("\n");
	}
}

// Lee un número suministrado por el usuario
long LeeNumero(){
	char numero[6];
	fgets(numero, 6, stdin);
	return atoi(numero);
}

// Elimina los registros marcados como borrados
void Empaquetar (FILE **fa){
	FILE *ftemp;
	struct stRegistro reg;
	ftemp = fopen("alea.tmp", "wb");
	rewind(*fa);
	while(fread(&reg, sizeof(struct stRegistro), 1, *fa))
	if(reg.valido == 'S')
	fwrite(&reg, sizeof(struct stRegistro), 1, ftemp);
	fclose(ftemp);
	fclose(*fa);
	remove("alea.bak");
	rename("alea.dat", "alea.bak");
	rename("alea.tmp", "alea.dat");
	*fa = fopen("alea.dat", "r+b");
}
void Ordenar(FILE *fa){
	long nRegs;
	fseek(fa, 0, SEEK_END);
	nRegs = ftell(fa)/sizeof(struct stRegistro);
	QuickSort(fa, 0L, nRegs-1);
}

void QuickSort(FILE *fa, long inicio, long final){
	long iz, de;
	char mitad [34];
	static char cad[34];
	iz = inicio;
	de = final;
	strcpy(mitad, LeeCampo(fa, (iz+de)/2, cad));
	do {
		while(strcmp(LeeCampo(fa, iz, cad), mitad) < 0 && iz < final) iz++;
	while(strcmp(mitad, LeeCampo(fa, de, cad)) < 0 && de > inicio) de--;
	if(iz < de) Intercambia(fa, iz, de);
	if(iz <= de) {
	iz++;
	de--;
}
}while(iz<=de);

if(inicio < de) QuickSort(fa, inicio, de); 
if(iz < final) QuickSort(fa, iz, final);
}

char *LeeCampo (FILE *fa, long n, char *buf){
	struct stRegistro reg;
	fseek(fa, n* sizeof(struct stRegistro), SEEK_SET);
	fread(&reg, sizeof(struct stRegistro), 1, fa);
	strcpy(buf, reg.nombre);
	return buf;
}

void Intercambia(FILE *fa, long iz, long de){
	struct stRegistro reg1, reg2;
	fseek(fa, iz* sizeof(struct stRegistro), SEEK_SET);
	fread(&reg1, sizeof(struct stRegistro), 1, fa);
	fseek(fa, de* sizeof(struct stRegistro), SEEK_SET); fread(&reg2, sizeof(struct stRegistro), 1, fa);
	fseek(fa, iz* sizeof(struct stRegistro), SEEK_SET);
	fwrite(&reg2, sizeof(struct stRegistro), 1, fa);
	fseek(fa, de* sizeof(struct stRegistro), SEEK_SET);
	fwrite(&reg1, sizeof(struct stRegistro), 1, fa);
}

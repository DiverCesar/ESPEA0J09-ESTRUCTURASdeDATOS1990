#include<iostream> 

using namespace std; 

struct Alumno 
{ 
 char nombre[60]; 
 int nota; 
 int estado=0; //VERIFICAR 
 int clave; 
}; 

//PROTOTIPOS 
int insertar(Alumno* A, Alumno* B, int, int); //NODO ALUMNO 
int buscaHash(Alumno* A, int, int); 

int main() 
{ 
 int op=0, n, clave, x; 
 do 
 { 
  cout << "INGRESAR CANTIDAD DE ALUMNOS: "; 
  cin >> n; 
 } while(n <= 0); //SOLO POSITIVOS 

 Alumno* A = new Alumno[n]; // ARRAY DATOS  
 Alumno* B = new Alumno[n]; // ARRAY HASH RECUPERAR 

 system("CLS"); 
 do 
 { 
  cout << "\t\n"; 
  cout << "\t-----------------------\n"; 
  cout << "\t 1.INSERTAR | 2.BUSCAR \n"; 
  cout << "\t        3.SALIR        \n";
  cout << "\t-----------------------\n\n";  
  cout << "\t    INGRESE OPCION:    \n";
  cout << "\t";
  cin >> op; 
  system("cls"); 

  switch(op) 
  { 
  case 1: 
   for(int i = 0; i < n; i++) //MANEJAR ARREGLO 
   { 
    cout << "INGRESE DATOS ALUMNO " << i + 1 << endl; 
    fflush(stdin); //LIMPIAR BUFFER 
    cout << "NOMBRE: "; 
    cin.getline(A[i].nombre, 50); //LEER NOMBRE 
    do 
    { 
     cout << "NOTA: "; 
     cin >> A[i].nota; 
    } while(A[i].nota < 0 || A[i].nota > 20); //CONTROLAR NOTA RANGO 

    A[i].clave = insertar(A, B, i, n); //FUNCION CLAVE IGUALADO  
    cout << "CLAVE: "; 
    cout << A[i].clave << endl <<endl; 
   } 
   break; 

  case 2: 
   cout << "INTRODUZCA EL CODIGO QUE DESEA BUSCAR: "; 
   fflush(stdin); 
   cin >> clave; 
   x = buscaHash(A, n, clave); 
   if(x == -1) 
   { 
    cout << "Numero " << clave << " NO encontrado" << endl; 
   } 
   else 
   { 
    cout << "NUMERO " << clave<< " ENCONTRADO" << endl; 
    cout << "NOMBRE: " << B[x].nombre << endl; 
    cout << "NOTA: " << B[x].nota << endl; 
   } 
   break; 

  case 3: 
   cout << ""; 
   return 0;  

  default: 
   cout << "\n\nOPCION NO CORRECTA\n\n"; 
   system("PAUSE"); 
  } 
 } while(op != 3); 

 return 0;      
} 

int insertar(Alumno* A, Alumno* B, int i, int n) 
{ 
 int j = (A[i].nota + 1) % n; //ALMACENAR NOTA INDICE +1 Y EL TAMAÑO ARREGLO CON EL MODULO  

 do 
 { 
  if(A[j].estado == 0) //VACIO 
  { 
   B[j] = A[j]; //IGUALAR Y ALMACENAR 
   A[j].estado = 1; //LLENO POSICION 
  } 
  else 
  { 
   j++; 
  } 
 } while(j > n); 

 return j; 
} 

int buscaHash(Alumno *A, int n, int clave) 
{ 
 int j = 0; 
 while(j < n) 
 { 
  if(A[j].clave == clave) 
  { 
   return j; 
  } 
  else 
  { 
   j++; 
  } 
 } 
 return -1; 
}

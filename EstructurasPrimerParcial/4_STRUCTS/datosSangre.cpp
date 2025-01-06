#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <conio.h>
using namespace std;

//STRUCTS
struct paciente {
    char sexo;
    string sangre;
};

int main() {
    struct paciente pac[100];
    int n, npac, nm = 0, nf = 0;
    int tipoSangre[8] = {0}; // 0: O-, 1: O+, 2: A-, 3: A+, 4: B-, 5: B+, 6: AB-, 7: AB+
    string tiposSangre[8] = {"O-", "O+", "A-", "A+", "B-", "B+", "AB-", "AB+"};
    float porcentajeHombres[8] = {0}; // Para calcular el porcentaje de cada tipo de sangre en hombres
    float porcentajeMujeres[8] = {0}; // Para calcular el porcentaje de cada tipo de sangre en mujeres

    printf("Introduzca el numero de pacientes: ");
    scanf("%d", &npac);
    printf("\n");

    for (int n = 1; n <= npac; n++) { // Registramos npac pacientes
        do {
            printf("Sexo (f/m): ");
            fflush(stdin);
            pac[n].sexo = (toupper(getchar()));
        } while (pac[n].sexo != 'F' && pac[n].sexo != 'M');

        do {
            printf("Tipo de sangre (O-, O+, A-, A+, B-, B+, AB-, AB+): ");
            fflush(stdin);
            getline(cin, pac[n].sangre);
        } while (pac[n].sangre != "O-" && pac[n].sangre != "O+" && pac[n].sangre != "A-" && pac[n].sangre != "A+" &&
                 pac[n].sangre != "B-" && pac[n].sangre != "B+" && pac[n].sangre != "AB-" && pac[n].sangre != "AB+");

        if (pac[n].sexo == 'F') {
            nf++; // Incrementamos mujeres
            // Encontramos el índice del tipo de sangre y lo incrementamos para mujeres
            for (int i = 0; i < 8; i++) {
                if (pac[n].sangre == tiposSangre[i]) {
                    tipoSangre[i]++;
                    porcentajeMujeres[i]++;
                }
            }
        }

        if (pac[n].sexo == 'M') {
            nm++; // Incrementamos hombres
            // Encontramos el índice del tipo de sangre y lo incrementamos para hombres
            for (int i = 0; i < 8; i++) {
                if (pac[n].sangre == tiposSangre[i]) {
                    tipoSangre[i]++;
                    porcentajeHombres[i]++;
                }
            }
        }

        printf("\n");
    }

    // Cálculo de los porcentajes por tipo de sangre
    for (int i = 0; i < 8; i++) {
        if (nm > 0) {
            porcentajeHombres[i] = (porcentajeHombres[i] * 100) / nm; // Porcentaje hombres por tipo de sangre
        }
        if (nf > 0) {
            porcentajeMujeres[i] = (porcentajeMujeres[i] * 100) / nf; // Porcentaje mujeres por tipo de sangre
        }
    }

    // Buscar el índice con el mayor porcentaje de hombres
	int maxIndexHombres = 0;
	for (int i = 1; i < 8; i++) {
	    if (porcentajeHombres[i] > porcentajeHombres[maxIndexHombres]) {
	        maxIndexHombres = i;
	    }
	}
	
	// Buscar el índice con el mayor porcentaje de mujeres
	int maxIndexMujeres = 0;
	for (int i = 1; i < 8; i++) {
	    if (porcentajeMujeres[i] > porcentajeMujeres[maxIndexMujeres]) {
	        maxIndexMujeres = i;
	    }
	}
	
	// Imprimir el porcentaje de los tipos de sangre más frecuentes
	printf("Porcentaje de hombres con el tipo de sangre mas frecuente (%s): %.2f%%\n", tiposSangre[maxIndexHombres].c_str(), porcentajeHombres[maxIndexHombres]);
	printf("Porcentaje de mujeres con el tipo de sangre mas frecuente (%s): %.2f%%\n", tiposSangre[maxIndexMujeres].c_str(), porcentajeMujeres[maxIndexMujeres]);

    // Imprimir los porcentajes por tipo de sangre
    for (int i = 0; i < 8; i++) {
        printf("Porcentaje de pacientes con tipo de sangre %s: %.2f%%\n", tiposSangre[i].c_str(), (tipoSangre[i] * 100.0) / npac);
    }
	
	getch();
    return(0);
}

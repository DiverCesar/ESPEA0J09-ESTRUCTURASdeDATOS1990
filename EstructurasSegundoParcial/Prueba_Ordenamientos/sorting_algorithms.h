#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

// Implementar algoritmo Exchange Sort (grupo v2)
void exchangeSort(int arr[], int n);
void burbuja(int arr[], int n);
// Implementar algoritmo Shell Sort (grupo v1 & v2)
void shellSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void radixSort(int arr[], int n);
// Implementar algoritmo Counting Sort (grupo v1)
void countingSort(int arr[], int n);
void imprimir(int arr[], int tamano);
void swap(int& a, int& b);

#endif // SORTING_ALGORITHMS_H


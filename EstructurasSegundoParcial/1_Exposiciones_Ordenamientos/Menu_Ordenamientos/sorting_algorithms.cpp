#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "sorting_algorithms.h"

using namespace std;

void exchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void shellSort(int arr[], int n) {
    for (int paso = n / 2; paso > 0; paso /= 2) {
        for (int i = paso; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= paso && arr[j - paso] > temp; j -= paso) {
                arr[j] = arr[j - paso];
            }
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void radixSort(int arr[], int n) {
    int m = *max_element(arr, arr + n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n);
    }
}

void countingSort(int arr[], int n) {
    int max = *max_element(arr, arr + n);
    int* count = new int[max + 1]();
    int* output = new int[n];

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

void imprimir(int arr[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


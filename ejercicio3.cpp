#include <iostream>
#include <cmath>
using namespace std;

int padre(int pos) {
    return pos / 2;
}

int hIzq(int pos) {
    return pos * 2;
}

int hDer(int pos) {
    return (pos * 2) + 1;
}

void swap(int pos1, int pos2, int* arr) {
    int aux =  arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = aux;
}

void heapify(int* arr, int i, int N) {
    int posHIzq = hIzq(i);
    int posHDer = hDer(i);

    int posMayorHijo = i;

    if (posHIzq <= N && arr[posHIzq] > arr[posMayorHijo]) {
        posMayorHijo = posHIzq;
    }
    if (posHDer <= N && arr[posHDer] > arr[posMayorHijo]) {
        posMayorHijo = posHDer;
    }

    if (posMayorHijo != i) {
        swap(i, posMayorHijo, arr);
        heapify(arr, posMayorHijo, N);
    }
}

void BuildMaxHeap(int* arr, int N) {
    for (int i = floor(N/2); i > 0; i--) {
        heapify(arr, i, N);
    }
}

void heapsort(int* arr, int N) {
    BuildMaxHeap(arr, N);
    for (int i = N; i > 1; i--) {
        swap(1, i, arr);
        N = N - 1;
        heapify(arr, 1, N);
    }
}

int main() {
    int N;
    cin >> N;

    int* elementos = new int[N+1]();

    for (int i = 1; i <= N; i++) { // ARRANCA EN 1 !!
        int element;
        cin >> element;
        elementos[i] = element;
    }

    heapsort(elementos, N);

    for (int i = 1; i <= N; i++) {
        cout << elementos[i] << endl;
    }

    delete[] elementos; // liberar memoria
    return 0;
}

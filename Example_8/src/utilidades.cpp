#include <iostream>
#include "utilidades.h"

using namespace std;

/* Método que lee los datos por teclado y 
los introduce en un array usando el puntero que apunta
a la primera posición del array */
void leerDatos(double *array, int tam) {
    double valor;
    cout << "Introduzca los datos: ";
    for(int i = 0; i < tam; i++) {
        cin >> valor;
        *(array+ i) = valor;
    }
}

// Método para ordenar un array usando el puntero del array
void ordenarArray(double *array, int tam) {
    double minimo, cambio;
    int pos_min;
    for (int izda = 0; izda < tam; izda++) {
        minimo = *(array + izda);
        pos_min = izda;
        for (int i = izda + 1; i < tam; i++) {
            if (*(array+ i) < minimo) {
                minimo = *(array + i);
                pos_min = i;
            }
        }
    cambio = *(array + izda);
    *(array + izda) = *(array + pos_min);
    *(array + pos_min) = cambio;
    }
}

/* Método para elimitar los valores 
repetidos en un vector ordenado usando su puntero. 
Devuvelve el tamaño del vector final */
int eliminarRepetidos(double *array, int tam) {
    int i, j, k;
    for(i = 0; i < tam; i++) {
		for(j = i + 1; j < tam; j++){
			if(*(array + i) == *(array + j)) { 
				k = j;
				while(k < tam) { 
					*(array + k) = *(array + k + 1); 
					k++; 
				}
				tam--; 
				j--;
            }
        }
    }
    return tam;
}

/* Método para mezclar dos vectores sin repetir valores
usando los dos punteros de los arrays */
void mezclarVectores(double *array1, double *array2, int tam1, int tam2, int TAM) {
    int pos1 = 0, pos2 = 0, 
    pos3 = 0;
    double array3[TAM];
    while (pos1 < tam1 && pos2 < tam2) {
        if(*(array1 + pos1) < *(array2 + pos2)) {
            *(array3 + pos3) = *(array1 + pos1);
            pos1++;
            pos3++;
        }
        else if (*(array1 + pos1) == *(array2 + pos2)) {
            *(array3 + pos3) = *(array1 + pos1);
            pos1++;
            pos2++;
            pos3++;
        }
        else {
            *(array3 + pos3) = *(array2 + pos2);
            pos2++;
            pos3++;
        }
    }
    while(pos1 < tam1){
        *(array3 + pos3) = *(array1 + pos1);
        pos1++;
        pos3++;
    }
    while(pos2 < tam2){
        *(array3 + pos3) = *(array2 + pos2);
        pos2++;
        pos3++;
    }
    // Se imprime el vector resultante usando punteros
    cout << "Véctor final: ";
    for (int i = 0; i < pos3; i++) {
        cout << *(array3 + i) << " ";
    }
    cout << endl; 
}
#include <iostream>
#include "Pareja.h"
#include "Precuencias.h"
#include "utilidades.h"

using namespace std;

/* Función que lee los datos de
un número y guarda sus dígitos en un
array */
int *leerDatos(int num, int tam) {
    int *array = new int[tam];
    for(int i = 0; i < tam; i++) {
        *(array+ i) = num % 10;
        num = num / 10;
    }
    return array;
}

/* Método que ordena los números del
array introducido */
void ordenar(int *num, int tam){
    int cambio;
    for(int i = 1; i < tam; i++){
            for(int j = 0; j < tam - i; j++){
                if(*(num + j) > *(num + j + 1)){
                    cambio = *(num + j);
                    *(num + j) = *(num + j + 1);
                    *(num + j + 1) = cambio; 
                }
            }
        }
}

/* Función que muestra el contenido
de un array usando un puntero */
void mostrar(int * array, int tam){ 
    for(int i = 0; i < tam; i++){
        cout << *(array + i) << " "; 
    }
    cout << endl;
}

/* Función para contar los números diferentes
que existen en un array */
int contar_dif(int *array, int tam){
    int cant = 0;

    for(int i = 0; i < tam; i++){
        if(*(array + i) != *(array + i + 1)){
            cant++;
        }
    }

    return cant;
}

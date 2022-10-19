#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "MatrizDispersa.h"
#include "Valor.h"

/* Función para leer un array de enteros */
void leerArrayInt(int tam, int array[]);

/* Función para leer un array de double */
void leerArrayDouble(int tam, double array[]);

/* Función que suma los valores de dos vectores
de la clase Valor, cuyas posiciones de la matriz
coinciden. Después imprime el véctor resultante */
void sumarArray(Valor array1[], Valor array2[], Valor array3[], int tam1, int tam2);

#endif
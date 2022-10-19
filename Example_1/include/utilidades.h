#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "Precuencias.h"
#include "Pareja.h"

/* Función que lee los datos de
un número y guarda sus dígitos en un
array */
int *leerDatos(int num, int tam);

/* Método que ordena los números del
array introducido */
void ordenar(int *num, int tam);

/* Función que muestra el contenido
de un array usando un puntero */
void mostrar(int * array, int tam);

/* Función para contar los números diferentes
que existen en un array */
int contar_dif(int *array, int tam);

#endif
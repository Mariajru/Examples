/* Ejercicio 3. Implementar una funci´on llamada mezclarUnico que devuelva un valor de tipo
entero y reciba como argumento dos arrays de valores de tipo double (pasados como
punteros) y los combine almacenando el resultado en un tercer array, pasado tambi´en
como argumento. */

#include <iostream>
#include "utilidades.h"

using namespace std;

int main() {
    const int TAM = 100;
    int elementos;
    double array1[TAM], array2[TAM], array3[TAM]; 

    /* Se introduce por teclado el tamaño de los dos vectores 
    con los que se va a trabajar. Después llamamos a la función
    que introducirá los datos y se modificarán por 
    paso por referencia */
    int tam1, tam2;
    cout << "Introduzca el tamaño del primer vector: ";
    cin >> tam1;
    leerDatos(array1, tam1);
    cout << "Introduzca el tamaño del segundo vector: ";
    cin >> tam2;
    leerDatos(array2, tam2);

    /* Se llama al método ordenarArray dos veces, para tener
    ordenado cada uno de los dos arrays de forma creciente */
    ordenarArray(array1, tam1);
    ordenarArray(array2, tam2);

    /* Se llama al método eliminarRepetidos dos veces, para tener
    cada array sin valores coincidentes */
    tam1 = eliminarRepetidos(array1, tam1);
    tam2 = eliminarRepetidos(array2, tam2); 

    cout << "Véctor 1 ordenado sin valores repetidos: ";
    for (int i = 0; i < tam1; i++) {
        cout << *(array1 + i) << " ";
    }
    cout << endl;

    cout << "Véctor 2 ordenado sin valores repetidos: ";
    for (int i = 0; i < tam2; i++) {
        cout << *(array2 + i) << " ";
    }
    cout << endl;

    /* Se llama al método mezclar vectores, con el que finalmente
    se obtendrá un único véctor impreso por pantalla, que será
    el resultado de la combinación de ambos vectores
    sin repetir valores */
    mezclarVectores(array1, array2, tam1, tam2, TAM);

    return 0;
}
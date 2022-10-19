/* Ejercicio 1. Se desea resolver el problema de sumas de enteros no negativos de gran tama~no (que
exceden la capacidad de representacion del tipo int. Para ello se propone crear la clase
BigInt que puede almacenar valores enteros de longitud indeterminada.

La clase representara un entero mediante un array (de longitud variable) de enteros,
reservado en memoria dinamica (donde cada entero representa uno de los dgitos del
entero largo a construir y solo podra tomar valores entre 0 y 9). El almacenamiento se
produce de forma que el valor menos signicativo se guarda en la posicion 0 del array. Dos
ejemplos de representacion de enteros se muestran a continuacion (para 9530273759835
y 0) */

#include <iostream>
#include "BigInt.h"

using namespace std;

int main(){
    BigInt *array_sum;
    int tam1, tam3;

    /* Introduzco el tamaño por teclado
    y creo el array con los datos introducidos
    por teclado */
    cout << "Introduzca el tamaño del número: ";
    cin >> tam1;
    BigInt array1(tam1);
    array1.insertar();
    cout << "Array introducido: " << endl;
    array1.mostrar();

    /* Llamo al constructor copia
    e imprimo el array copiado */
    BigInt array2(array1);
    cout << "Array copiado: " << endl;
    array2.mostrar();

    /* Creo que array 3 para sumar dos
    objetos entre sí */
    cout << "Introduzca el tamaño del segundo número: ";
    cin >> tam3;
    BigInt array3(tam3);
    array3.insertar();

    /* Recibo el puntero al nuevo objeto
    que se ha creado con el método sumar */
    array_sum = array1.sumar(array3);
    cout << "Suma: " << endl;
    array_sum->mostrar();

    cout << "Uso de operador <<, array1: ";
    cout << array1;
    
    return 0;
}

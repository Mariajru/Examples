#include <iostream>
#include "Pareja.h"
#include "Precuencias.h"

using namespace std;

int main(){
    int num, tam, tam_dif, valor;
    int *numeros;
    Precuencias array1; 

    cout << "Introduzca el tamaño del número: ";
    cin >> tam;
    cout << "Introduzca el número: ";
    cin >> num;
    cout << "Valor a agregar: ";
    cin >> valor;

    numeros = leerDatos(num, tam);

    ordenar(numeros, tam);

    tam_dif = contar_dif(numeros, tam);

    array1.contarRepeticiones(numeros, tam, tam_dif);
    cout << "Precuencias: " << endl;
    array1.mostrarPrecuencias();

    Precuencias array2(array1);
    cout << "Copia Precuencias: " << endl;
    array2.mostrarPrecuencias();

    if(array1 == array2){
        cout << "Son la misma clase. " << endl;
    }
    else{
        cout << "Son clases diferentes. " << endl; 
    }
    cout << endl;
    
    array1.agregarValor(valor);
    cout << "Precuencia con el valor agregado: " << endl;
    array1.mostrarPrecuencias();

    if(array1 != array2){
        cout << "Son clases diferentes. " << endl;
    }
    else{
        cout << "Son la misma clase. " << endl;
    }
    cout << endl;

    return 0;
}
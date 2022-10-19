#include <iostream>
#include "Valor.h"
#include "MatrizDispersa.h"
#include "utilidades.h"

using namespace std;

/* Función para leer un array de enteros */
void leerArrayInt(int tam, int array[]){
    int valor;
    for(int i = 0; i < tam; i++){
        cin >> valor;
        array[i] = valor;
    }
}

/* Función para leer un array de double */
void leerArrayDouble(int tam, double array[]){
    int valor;
    for(int i = 0; i < tam; i++){
        cin >> valor;
        array[i] = valor;
    }
}

/* Función que suma los valores de dos vectores
de la clase Valor, cuyas posiciones de la matriz
coinciden. Después imprime el véctor resultante */
void sumarArray(Valor array1[], Valor array2[], Valor array3[], int tam1, int tam2){
    int pos = 0;
    for(int i = 0; i < tam1; i++){
        bool encontrado = false;
        for(int j = 0; j < tam2 && !encontrado; j++){
            if(array1[i].getFil() == array2[j].getFil()){
                if(array1[i].getCol() == array2[j].getCol()){
                    array3[pos].setFil(array1[i].getFil());
                    array3[pos].setCol(array1[i].getCol());
                    array3[pos].setVal(array1[i].getVal() + array2[j].getVal());
                    encontrado = true;
                    pos++;
                }
            }
        }
        if(!encontrado){
            array3[pos].setFil(array1[i].getFil());
            array3[pos].setCol(array1[i].getCol());
            array3[pos].setVal(array1[i].getVal());
            pos++;
        }
    }

    /* Completa el véctor resultante con los valores
    del segundo véctor en los que no se ha realizado
    la suma de valores */
    if(pos < tam1){
        for(int i = 0; i < tam2; i++){
            bool encontrado = false;
            for(int j = 0; j < tam1 && !encontrado; j++){
                if(array2[i].getFil() == array1[j].getFil()){
                    if(array1[i].getCol() == array2[j].getCol()){
                        encontrado = true;
                    }
                }
            }
            if(!encontrado){
                array3[pos].setFil(array2[i].getFil());
                array3[pos].setCol(array2[i].getCol());
                array3[pos].setVal(array2[i].getVal());
                pos++;
            }
        }
    }

    // Se imprime el véctor resultante 
    for(int i = 0; i < pos; i++){
        cout << "{" << array3[i].getFil() << ", " << array3[i].getCol()
        << ", " << array3[i].getVal() << "} ";
    }
}

#include <iostream>
#include "Valor.h"

using namespace std;


/**
 * Constructor por defecto
 */
Valor::Valor(){
    fila = 0;
    columna = 0;
    valor = 0;
}

/**
 * Constructor de la clase
 * @param fila
 * @param columna
 * @param valor
 */
Valor::Valor(int fil, int col, double val, int n){
    fila = fil;
    columna = col;
    valor = val;
}

/**
 * Métodos para devolver los datos del objeto
 */
int Valor::getFil(){
    return fila;
}
int Valor::getCol(){
    return columna;
}
double Valor::getVal(){
    return valor;
}

/**
 * Métodos para modificar los datos del objeto
*/
void Valor::setFil(int fil){
    fila = fil;
}
void Valor::setCol(int col){
    columna = col;
}
void Valor::setVal(double val){
    valor = val;
}


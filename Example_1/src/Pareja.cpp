#include <iostream>
#include "Pareja.h"

using namespace std;

Pareja::Pareja(){
    dato = 0;
    nveces = 0;
}

Pareja::Pareja(int valor, int veces){
    dato = valor;
    nveces = veces;
}

int Pareja::devolverDato(){
    return dato;
}

int Pareja::devolverVeces(){
    return nveces;
}

void Pareja::asignarDato(int valor){
    dato = valor;
}

void Pareja::asignarNveces(int num){
    nveces = num;
}


#include <iostream>
#include "Punto.h"

using namespace std;

Punto::Punto(){
    x = 0;
    y = 0;
}

Punto::Punto(int x1, int y2){
    x = x1;
    y = y2;
}

int Punto::devolverX(){
    return x;
}
int Punto::devolverY(){
    return y;
}
void Punto::asignarX(int x1){
    x = x1;
}
void Punto::asignarY(int y1){
    y = y1;
}

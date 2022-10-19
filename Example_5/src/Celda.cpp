#include<iostream>
#include "Celda.h"
#include "Lista.h"

using namespace std;

/**
 * Constructor de la clase Celda
 * @param info
 */
Celda::Celda(double info){
   this->info = info;
   this->sig = 0;
}

/**
 * Obtiene el valor de la celda
 * @return
 */
double Celda::obtenerInfo(){
   return info;
}

// Devuelve puntero a la celda siguiente
Celda * Celda::obtenerSiguiente(){
   return sig;
}

// Anula el puntero a siguiente a la celda
void Celda::anularSiguiente(){
   sig = 0;
}

// Se asigna el valor siguiente de una celda
void Celda::asignarSiguiente(Celda *pCelda){
   sig = pCelda;
}

// Imprime el contenido de una celda
void Celda::mostrar(){
   cout << info << " ";
}


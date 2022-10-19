#ifndef LISTA_H
#define LISTA_H

#include "Celda.h"

class Lista{
    private:
        Celda *contenido; // Puntero a un objeto de la clase celda (primer valor que almacena)

    public:
        /* Constructor por defecto. Inicia info = 0,
        y siguiente a 0 para el nuevo objeto */
        Lista(){
            this->contenido = 0;
        }
    void mostrar(Celda *p);
    void mostrarInverso(Celda *p);
    void colocarFinal(double info);
    Celda *obtener(int posicion);
    void eliminar();

};

#endif
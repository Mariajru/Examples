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
    
    void mostrar();
    void colocarFinal(double info);
    void obtenerLongitud();
    void eliminarFinal(int eliminar);
    void Inicio(double info);
    Celda *obtener(int posicion);
    void agregarPosicion(Celda *pos, double dato);
    void eliminar();
};

#endif



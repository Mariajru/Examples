#ifndef POLILINEA_H
#define POLILINEA_H

#include "Punto.h"

class Polilinea{
    private: 
        /* Creo un puntero para apuntar
        al array de puntos */
        Punto *p;
        int num; // Numero de puntos
    public:
        /* Constructor por defecto */
        Polilinea();

        /* Constructor para inicializar los
        valores del array de puntos */
        Polilinea(int tam);

        /* Constructor de copia */
        Polilinea(Polilinea &objeto1);

        // Destructor
        ~Polilinea();

        /* Método para mostrar el contenido 
        de un véctor de objetos */
        void mostrar();

        /* Método para añadir un nuevo
        punto en la Polilínea, en la primera
        posición */
        void agregarPunto(int x1, int y1); 

        /**
        * Sobrescritura del operador +
        * @param otro sumando2
        * @return resultado de la suma
        */
        Polilinea operator+(const Polilinea &otro) const;
};

#endif
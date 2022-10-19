#ifndef PRECUENCIAS_H
#define PRECUENCIAS_H

#include "utilidades.h"
#include "Pareja.h"

class Precuencias{
    private:
        Pareja *parejas; // Array de objetos de la clase Pareja
        int npares; // Número de objetos almacenados en el array
    public:
        // Constructor por defecto
        Precuencias();

        // Destructor
        ~Precuencias();

        // Constructor de copia
        Precuencias(Precuencias &objeto1);

        /* Método para guardas los valores
        con su respectivo número de repeticiones */
        void contarRepeticiones(int *num, int tam, int tam_dif);

        /* Método para mostrar las frecuencias
        de cada número de la clase Pareja */
        void mostrarPrecuencias();

        /* Método para agregar un valor
        a la lista de Parejas */
        void agregarValor(int valor);

        /**
        * Sobrescritura del operador de igualdad
        * @param otro
        * @return resultado de la comparacion
        */
        bool operator==(const Precuencias &otro) const;

        /**
        * Sobrescritura del operador de desigualdad
        * @param otro
        * @return resultado de la comparacion
        */
        bool operator!=(const Precuencias &otro) const;
};

#endif
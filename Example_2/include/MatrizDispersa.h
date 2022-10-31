#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "utilidades.h"
#include "Valor.h"

class MatrizDispersa{
    private:
        int nfilas;         //Num de filas de la Matriz
        int ncolumnas;      //Num de columnas de la Matriz
        Valor *valores;     //Puntero que señala al comienzo
        int numeroValores;  //Numero de valores totales en la Matriz
    public:
        // Constructor por defecto
        MatrizDispersa();
    
        /* Método parqa leer los datos que forman
        la características de la matriz */
        void leerDatos();
        
        /* Método que lee los valores introducidos por teclado,
        rellena el véctor de objetos */
        void leerValores();

        /* Método que muestra los valores de
        la matriz, fila, columna, y valor guardado */
        void mostrar();

        // Destructor
        ~MatrizDispersa();    

        // Constructor copia
        MatrizDispersa(MatrizDispersa &objeto1);

        // Constructor copia para una matriz deperminada
        MatrizDispersa(int array_fil[], int array_col[], double array_val[], int tam_val);
};

#endif

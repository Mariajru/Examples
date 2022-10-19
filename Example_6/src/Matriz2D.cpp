#include <iostream>
#include "Matriz2D.h"

using namespace std;

/* Método para rellenar la matriz
por teclado */
void Matriz2D::rellenarMatriz(){
    int valor;
    for(int f = 0; f < fil; f++){
        for(int c = 0; c < col; c++){
            cout << "Inserte el valor para la posición [ " << f << " ][ " << c << " ]: ";
            cin >> valor;
            *(*(ptrMatriz + f) + c) = valor;
        }
    }
}

/* Método para mostrar el contenido de
la matriz */
void Matriz2D::mostrar(){
    for(int f = 0; f < fil; f++){
        for(int c = 0; c < col; c++){
            cout << *(*(ptrMatriz + f) + c) << " ";
        }
        cout << endl;
    }
}

/* Método que permite copiar el objeto
sobre el que se hace la llamada */
Matriz2D *Matriz2D::copiarMatriz(){
    Matriz2D *ptrObjeto;

    // Creo un puntero a mi objeto
    ptrObjeto = new Matriz2D(fil, col);

    /* Accedo al valor de puntero a punteros
    de mi nuevo objeto */
    int **ptr;
    ptr = (*ptrObjeto).ptrMatriz;

    /* Relleno la nueva matriz usando 
    el puntero a la matriz que quiero copiar */
    for(int f = 0; f < fil; f++){
        for(int c = 0; c < col; c++){
            *(*(ptr + f) + c) = *(*(ptrMatriz + f) + c);
        }
    }

    // Devuelve el puntero al nuevo objeto
    return ptrObjeto;
}

// Método para extraer una submatriz
Matriz2D *Matriz2D::extraerSubmatriz(int fil_inicio, int col_inicio, int fil_fin, int col_fin){
    Matriz2D *ptrSub;

    /* Calculo el tamaño de la matriz para
    poder asignar el espacio de memoria necesario */
    int fil_sub = (fil_fin + 1) - fil_inicio;
    int col_sub = (col_fin + 1) - col_inicio;
    ptrSub = new Matriz2D(fil_sub, col_sub);

    int **ptr;
    ptr = (*ptrSub).ptrMatriz;

    /* Completo la matriz teniendo en cuenta que necesito
    dos contadores adicionales para comenzar a colocar
    los valores de la matriz dada en la nueva matriz */
    int cont_fil = 0;
    for(int f = fil_inicio; f <= fil_fin; f++){
        int cont_col = 0;
        for(int c = col_inicio; c <= col_fin; c++){
            *(*(ptr + cont_fil) + cont_col) = *(*(ptrMatriz + f) + c);
            cont_col++;
        }
        cont_fil++;
    }
    return ptrSub;
}

// Método para eliminar una fila
void Matriz2D::eliminarFila(int fila){
    for (int f = fila; f < fil - 1; f++){
        for(int c = 0; c < col; c++){
            *(*(ptrMatriz + f) + c) = *(*(ptrMatriz + f + 1) + c);
        }
    }
    --fil;
    delete [] *(ptrMatriz + fil);
}

// Método para eliminar una columna
void Matriz2D::eliminarColumna(int columna){
    for (int f = 0; f < fil; f++){
        for(int c = columna; c < col - 1; c++){
            *(*(ptrMatriz + f) + c) = *(*(ptrMatriz + f) + c + 1);
        }
    }
    --col;
} 

/* Método para liberar el espacio ocupado en el heap. Solo
eliminamos el puntero a punteros que forma parte de los
atributos privados de la clase */
void Matriz2D::eliminarEspacio(){
    for(int i = 0; i < fil; i++){
        delete [] ptrMatriz[i];
    }
    delete [] ptrMatriz;
}        
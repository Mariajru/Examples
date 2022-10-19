#ifndef MATRIZ2D_H
#define MATRIZ2D_H

/* Se define la clase para representar la matriz
bidimensional */
class Matriz2D{
    private:
        int col;
        int fil;
        int **ptrMatriz;
    public:
        // Constructor por defecto
        Matriz2D(){
            col = 0;
            fil = 0;
            ptrMatriz = 0;
        }

        /* Constructor para crear una matriz
        con un determinado número de filas y columnas */
        Matriz2D(int n_fil, int n_col){
            fil = n_fil;
            col = n_col;
            /* Reservo el espacio de memoria
            necesario para la matriz */
            ptrMatriz = new int *[n_fil];
            for(int i = 0; i < n_fil; i++){
                *(ptrMatriz + i) = new int[n_col];
            }

            /* Inicializo los elementos de las columnas
            a 0 */
            for(int f = 0; f < n_fil; f++){
                for(int c = 0; c < n_col; c++){
                    *(*(ptrMatriz + f) + c) = 0;
                }
            }
        }

    // Declaración de los métodos de la clase
    void rellenarMatriz();
    void mostrar();
    Matriz2D *copiarMatriz();
    Matriz2D *extraerSubmatriz(int fil_inicio, int col_inicio, int fil_fin, int col_fin);
    void eliminarFila(int fila);
    void eliminarColumna(int columna);
    void eliminarEspacio();
};

#endif
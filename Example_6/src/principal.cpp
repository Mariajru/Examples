/* Ejercicio 6. Tratar con matrices bidimensionales a partir de 
memoria dinámina */

#include <iostream>
#include "Matriz2D.h"

using namespace std;

int main(){
    int filas, columnas, fil_ini, fil_fin,
    col_ini, col_fin, fil_elimi, col_elimi;
    Matriz2D *ptrMatriz2, *ptrSubmatriz;

    // Pido los datos de fila y columna por teclado
    cout << "Introduzca el número de filas: ";
    cin >> filas;
    cout << "Introduzca el número de columnas: ";
    cin >> columnas;

    // Datos para la submatriz
    cout << "Introduzca la fila de inicio para la submatriz: ";
    cin >> fil_ini;
    cout << "Introduzca la columna de inicio para la submatriz: ";
    cin >> col_ini;
    cout << "Introduzca la fila final para la submatriz: ";
    cin >> fil_fin;
    cout << "Introduzca la columna final para la submatriz: ";
    cin >> col_fin;

    // Datos para eliminar fila y columna
    cout << "Introduzca la fila que quiere eliminar: ";
    cin >> fil_elimi;
    cout << "Introduzca la columna que quiere eliminar: ";
    cin >> col_elimi;

    Matriz2D matriz1(filas, columnas);

    matriz1.rellenarMatriz();

    cout << "Matriz original: " << endl;
    matriz1.mostrar();

    cout << "Matriz copiada a partir de la original: " << endl;
    ptrMatriz2 = matriz1.copiarMatriz();
    (*ptrMatriz2).mostrar();

    cout << "Submatriz desde el elemento (" << fil_ini << ", " << col_ini 
    << ") hasta (" << fil_fin << ", " << col_fin << "): " << endl;
    ptrSubmatriz = matriz1.extraerSubmatriz(fil_ini, col_ini, fil_fin, col_fin);
    int fil_sub = (fil_fin + 1) - fil_ini;
    int col_sub = (col_fin + 1) - col_ini;
    (*ptrSubmatriz).mostrar();

    cout << "Matriz con la fila eliminada: " << endl;
    matriz1.eliminarFila(fil_elimi);
    matriz1.mostrar();

    cout << "Matriz con la columna eliminada: " << endl;
    matriz1.eliminarColumna(col_elimi);
    matriz1.mostrar();

    // Liberamos el espacio del heap
    matriz1.eliminarEspacio();
    (*ptrMatriz2).eliminarEspacio();
    (*ptrSubmatriz).eliminarEspacio();

    return 0;
}
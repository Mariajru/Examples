#include <iostream>
#include "Valor.h"
#include "MatrizDispersa.h"

using namespace std;

int main(){
    const int TAM = 100;

    int cant, nfil, ncol, tam_val,
    array_fil[TAM], array_col[TAM];
    double valor, array_val[TAM];
    MatrizDispersa matriz;

    matriz.leerValores();
    matriz.mostrar();

    MatrizDispersa matriz_copia(matriz);
    cout << "Copia: " << endl;
    matriz_copia.mostrar();

    cout << "Introduzca la cantidad de valores significativos de la matriz copia determinada: ";
    cin >> tam_val;
    cout << "Introduzca los valores significativos: ";
    leerArrayDouble(tam_val, array_val);

    cout << "Introduzca las filas dónde se encuentran los valores significativos: ";
    leerArrayInt(tam_val, array_fil);

    cout << "Introduzca las columnas dónde se encuentran los valores significativos: ";
    leerArrayInt(tam_val, array_col);

    MatrizDispersa matriz_determinada(array_fil, array_col, array_val, tam_val);
    cout << "Matriz copia determinada generada: " << endl;
    matriz_determinada.mostrar();

    return 0; 
}
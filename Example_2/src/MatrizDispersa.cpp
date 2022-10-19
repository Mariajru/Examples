#include <iostream>
#include "Valor.h"
#include "MatrizDispersa.h"

using namespace std;

MatrizDispersa::MatrizDispersa(){
    nfilas = 0;
    ncolumnas = 0;
    valores = 0;
    numeroValores = 0;
}

/* Método parqa leer los datos que forman
la características de la matriz */
void MatrizDispersa::leerDatos(){
    int tam, numfil, numcol;

    cout << "Introduzca cantidad de valores significativos: ";
    cin >> tam;
    cout << "Introduzca el número de filas de la matriz: ";
    cin >> numfil;
    cout << "Introduzca el número de columnas de la matriz: ";
    cin >> numcol;
    
    numeroValores = tam;
    nfilas = numfil;
    ncolumnas = numcol;
}

/* Método que lee los valores introducidos por teclado,
rellena el véctor de objetos */
void MatrizDispersa::leerValores(){
    leerDatos();

    valores = new Valor[numeroValores];

    int fila, columna;
    int num = 0;
    double valor;

    for (int i = 0; i < numeroValores; i++) {
            cout << "Introduzca fila, columna y valor: ";
            cin >> fila >> columna >> valor;
        
        if(valor > 0){
            (valores + i)->setVal(valor);
        }
        else{
            cout << "Error, valor debe de ser mayor que 0. Reinicie el programa" << endl; 
        }
        if(fila <= nfilas){
            (valores + i)->setFil(fila);
        }
        else{
            cout << "Error, la fila indicada no está contenida en la matriz. Reinicie el programa. " << endl; 
        }
        if(columna <= ncolumnas){
            (valores + i)->setCol(columna);
        }
        else{
            cout << "Error, la columna indicada no está contenida en la matriz. Reinicie el programa. " << endl; 
        }
    }   
}

/* Método que muestra los valores de
la matriz, fila, columna, y valor guardado */
void MatrizDispersa::mostrar(){
    for(int i = 0; i < numeroValores; i++){
        cout << "{" << (valores + i)->getFil() << ", " << (valores + i)->getCol()
        << ", " << (valores + i)->getVal() << "} ";
    }
    cout << endl;
}

// Destructor
MatrizDispersa::~MatrizDispersa(){
    delete [] valores;
    valores = 0;
    nfilas = 0;
    ncolumnas = 0;
    numeroValores = 0;
}     

// Constructor copia
MatrizDispersa::MatrizDispersa(MatrizDispersa &objeto1){
    this->nfilas = objeto1.nfilas;
    this->ncolumnas = objeto1.ncolumnas;
    this->numeroValores = objeto1.numeroValores;

    // Reservo el espacio necesario para el nuevo array
    this->valores = new Valor[this->numeroValores];

    /* Copio los valores del array de Valores en el
    nuevo array que será la copia del objeto 1 */
    for(int i = 0; i < numeroValores; i++){
        *(this->valores + i) = objeto1.valores[i];
    }
} 

// Constructor copia para una matriz deperminada
MatrizDispersa::MatrizDispersa(int array_fil[], int array_col[], double array_val[], int tam_val){
    int num_f, num_c;

    cout << "Introduza el número de filas y número de columnas de la matriz copia determinada: ";
    cin >> num_f >> num_c;

    this->nfilas = num_f;
    this->ncolumnas = num_c;
    this->numeroValores = tam_val;

    this->valores = new Valor[this->numeroValores];

    for(int i = 0; i < numeroValores; i ++){
        (this->valores + i)->setFil(array_fil[i]);
        (this->valores + i)->setCol(array_col[i]);
        (this->valores + i)->setVal(array_val[i]);
    }
}

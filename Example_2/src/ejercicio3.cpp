/* Ejercicio3. Se pretende implementar una clase que permita representar de forma eciente matrices
dispersas, donde solo un numero relativamente bajo de valores son signicativos
(distintos de cero). Estos valores signicativos son los unicos que se almacenan. Cada
valor signicativo precisa almacenar: la, columna y valor numerico que representa (de
tipo double). La informacion sobre valores signicativos se almacena en una clase llamada
Valor. */

#include <iostream>

using namespace std;

class Valor{
  private:
    int fila;
    int columna;
    double valor;

  public:
    /**
     * Constructor por defecto
     */
    Valor(){
        fila = 0;
        columna = 0;
        valor = 0;
    }

    /**
     * Constructor de la clase
     * @param fila
     * @param columna
     * @param valor
     */
    Valor(int fil, int col, double val, int n){
        fila = fil;
        columna = col;
        valor = val;
    }
    
    /**
     * Métodos para devolver los datos del objeto
     */
    int getFil(){
        return fila;
    }
    int getCol(){
        return columna;
    }
    double getVal(){
        return valor;
    }

    /**
     * Métodos para modificar los datos del objeto
    */
    void setFil(int fil){
        fila = fil;
    }
    void setCol(int col){
        columna = col;
    }
    void setVal(double val){
        valor = val;
    }

};

class MatrizDispersa{
    private:
        int nfilas;
        int ncolumnas;
        Valor *valores;
        int numeroValores;
    public:
        // Constructor por defecto
        MatrizDispersa(){
            nfilas = 0;
            ncolumnas = 0;
            valores = 0;
            numeroValores = 0;
        }
    
        /* Método parqa leer los datos que forman
        la características de la matriz */
        void leerDatos(){
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
        void leerValores(){
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
        void mostrar(){
            for(int i = 0; i < numeroValores; i++){
                cout << "{" << (valores + i)->getFil() << ", " << (valores + i)->getCol()
                << ", " << (valores + i)->getVal() << "} ";
            }
            cout << endl;
        }

        // Destructor
        ~MatrizDispersa(){
            delete [] valores;
            valores = 0;
            nfilas = 0;
            ncolumnas = 0;
            numeroValores = 0;
        }     

        // Constructor copia
        MatrizDispersa(MatrizDispersa &objeto1){
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
        MatrizDispersa(int array_fil[], int array_col[], double array_val[], int tam_val){
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
};

/* Función para leer un array de enteros */
void leerArrayInt(int tam, int array[]){
    int valor;
    for(int i = 0; i < tam; i++){
        cin >> valor;
        array[i] = valor;
    }
}

/* Función para leer un array de double */
void leerArrayDouble(int tam, double array[]){
    int valor;
    for(int i = 0; i < tam; i++){
        cin >> valor;
        array[i] = valor;
    }
}

/* Función que suma los valores de dos vectores
de la clase Valor, cuyas posiciones de la matriz
coinciden. Después imprime el véctor resultante */
void sumarArray(Valor array1[], Valor array2[], Valor array3[], int tam1, int tam2){
    int pos = 0;
    for(int i = 0; i < tam1; i++){
        bool encontrado = false;
        for(int j = 0; j < tam2 && !encontrado; j++){
            if(array1[i].getFil() == array2[j].getFil()){
                if(array1[i].getCol() == array2[j].getCol()){
                    array3[pos].setFil(array1[i].getFil());
                    array3[pos].setCol(array1[i].getCol());
                    array3[pos].setVal(array1[i].getVal() + array2[j].getVal());
                    encontrado = true;
                    pos++;
                }
            }
        }
        if(!encontrado){
            array3[pos].setFil(array1[i].getFil());
            array3[pos].setCol(array1[i].getCol());
            array3[pos].setVal(array1[i].getVal());
            pos++;
        }
    }

    /* Completa el véctor resultante con los valores
    del segundo véctor en los que no se ha realizado
    la suma de valores */
    if(pos < tam1){
        for(int i = 0; i < tam2; i++){
            bool encontrado = false;
            for(int j = 0; j < tam1 && !encontrado; j++){
                if(array2[i].getFil() == array1[j].getFil()){
                    if(array1[i].getCol() == array2[j].getCol()){
                        encontrado = true;
                    }
                }
            }
            if(!encontrado){
                array3[pos].setFil(array2[i].getFil());
                array3[pos].setCol(array2[i].getCol());
                array3[pos].setVal(array2[i].getVal());
                pos++;
            }
        }
    }

    // Se imprime el véctor resultante 
    for(int i = 0; i < pos; i++){
        cout << "{" << array3[i].getFil() << ", " << array3[i].getCol()
        << ", " << array3[i].getVal() << "} ";
    }
}

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
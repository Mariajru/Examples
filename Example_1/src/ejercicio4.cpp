/* Ejercicio4. Se desea crear un programa para calcular el numero de repeticiones en una secuencia
de numeros enteros. Por ejemplo, en el caso de la secuencia 939324 existen 4 valores
distintos, repitiendose 9 2 veces, 3 se repite 2 veces, 2 aparece una sola vez y 4 unicamente
1 vez. */

#include <iostream>

using namespace std;

class Pareja{
    private:
        int dato; // Valor
        int nveces; // Número de repeticiones
    public:
        Pareja(){
            dato = 0;
            nveces = 0;
        }

        Pareja(int valor, int veces){
            dato = valor;
            nveces = veces;
        }

        int getdevolverDato(){
            return dato;
        }

        int devolverVeces(){
            return nveces;
        }

        void asignarDato(int valor){
            dato = valor;
        }

        void asignarNveces(int num){
            nveces = num;
        }

};

class Precuencias{
    private:
        Pareja *parejas; // Array de objetos de la clase Pareja
        int npares; // Número de objetos almacenados en el array
    public:
        // Constructor por defecto
        Precuencias(){
            parejas = 0;
            npares = 0;
        }

        // Destructor
        ~Precuencias(){
            delete [] parejas;
            parejas = 0;
            npares = 0;
        }

        // Constructor de copia
        Precuencias(Precuencias &objeto1){
            this->npares = objeto1.npares;

            this->parejas = new Pareja[npares];

            for(int i = 0; i < npares; i++){
                *(this->parejas + i) = objeto1.parejas[i];
            }
        }


        /* Método para guardas los valores
        con su respectivo número de repeticiones */
        void contarRepeticiones(int *num, int tam, int tam_dif){
            int veces = 1, cont = 0;
            this->npares = tam_dif;

            parejas = new Pareja[npares];

            for(int i = 0; i < tam; i++){ 
                if(*(num + i) == *(num + i + 1)){
                    veces++;
                    (this->parejas + cont)->asignarNveces(veces);
                }
                else{
                    (this->parejas + cont)->asignarDato(*(num + i)); 
                    cont++;
                    veces = 1;
                }
            }
        }

        /* Método para mostrar las frecuencias
        de cada número de la clase Pareja */
        void mostrarPrecuencias(){
            for(int i = 0; i < npares; i++){
                cout << "El dato " << (this->parejas + i)->devolverDato() << " aparece " << (this->parejas + i)->devolverVeces() << " veces." << endl;
            }
            cout << endl;
        }

        /* Método para agregar un valor
        a la lista de Parejas */
        void agregarValor(int valor){
            bool repetido = false; 

            for(int i = 0; i < npares; i++){
                if((parejas + i)->devolverDato() == valor){
                    repetido = true;
                    (parejas + i)->asignarNveces((parejas + i)->devolverVeces() + 1);
                }
            }
            if(!repetido){
                    Pareja *ptpre = new Pareja[npares + 1];
                    
                    for(int i = 0; i < npares; i++){
                        *(ptpre + 1 + i) = *(this->parejas + i);
                    }

                    Pareja nuevo(valor, 1);

                    this->npares++;
                    *(ptpre + 0) = nuevo;

                    delete [] this->parejas;
                    this->parejas = ptpre;
            }
        }

        /**
        * Sobrescritura del operador de igualdad
        * @param otro
        * @return resultado de la comparacion
        */
        bool operator==(const Precuencias &otro) const{
            bool resultado = false;

            /* Primero se comprueba si se trata del mismo
            objeto para no seguir comprobando */
            if(this == &otro){
                resultado = true;
            }

            else{
                // Compruebo el tamaño
                if(this->npares == otro.npares){
                    resultado = true;
                    for(int i = 0; i < npares && resultado; i++){
                        if((this->parejas + i)->devolverVeces() != (otro.parejas + i)->devolverVeces() || (this->parejas + i)->devolverDato() != (otro.parejas + i)->devolverDato()){
                            resultado = false; 
                        }
                    }
                }
            }

            return resultado;
        } 

        /**
        * Sobrescritura del operador de desigualdad
        * @param otro
        * @return resultado de la comparacion
        */
        bool operator!=(const Precuencias &otro) const{
            bool resultado = true;

            /* Primero se comprueba si se trata del mismo
            objeto para no seguir comprobando */
            if(this == &otro){
                resultado = false;
            }

            else{
                // Compruebo el tamaño
                if(this->npares == otro.npares){
                    resultado = false;
                    for(int i = 0; i < npares && !resultado; i++){
                        if((this->parejas + i)->devolverVeces() != (otro.parejas + i)->devolverVeces() || (this->parejas + i)->devolverDato() != (otro.parejas + i)->devolverDato()){
                            resultado = true; 
                        }
                    }
                }
            }

            return resultado;
        } 



};

    /* Función que lee los datos de
    un número y guarda sus dígitos en un
    array */
    int *leerDatos(int num, int tam) {
        int *array = new int[tam];
        for(int i = 0; i < tam; i++) {
            *(array+ i) = num % 10;
            num = num / 10;
        }
        return array;
    }

    /* Método que ordena los números del
    array introducido */
    void ordenar(int *num, int tam){
        int cambio;
        for(int i = 1; i < tam; i++){
                for(int j = 0; j < tam - i; j++){
                    if(*(num + j) > *(num + j + 1)){
                        cambio = *(num + j);
                        *(num + j) = *(num + j + 1);
                        *(num + j + 1) = cambio; 
                    }
                }
            }
    }

    /* Función que muestra el contenido
    de un array usando un puntero */
    void mostrar(int * array, int tam){ 
        for(int i = 0; i < tam; i++){
            cout << *(array + i) << " "; 
        }
        cout << endl;
    }

    /* Función para contar los números diferentes
    que existen en un array */
    int contar_dif(int *array, int tam){
        int cant = 0;

        for(int i = 0; i < tam; i++){
            if(*(array + i) != *(array + i + 1)){
                cant++;
            }
        }

        return cant;
    }

int main(){
    int num, tam, tam_dif, valor;
    int *numeros;
    Precuencias array1; 

    cout << "Introduzca el tamaño del número: ";
    cin >> tam;
    cout << "Introduzca el número: ";
    cin >> num;
    cout << "Valor a agregar: ";
    cin >> valor;

    numeros = leerDatos(num, tam);

    ordenar(numeros, tam);

    tam_dif = contar_dif(numeros, tam);

    array1.contarRepeticiones(numeros, tam, tam_dif);
    cout << "Precuencias: " << endl;
    array1.mostrarPrecuencias();

    Precuencias array2(array1);
    cout << "Copia Precuencias: " << endl;
    array2.mostrarPrecuencias();

    if(array1 == array2){
        cout << "Son la misma clase. " << endl;
    }
    else{
        cout << "Son clases diferentes. " << endl; 
    }
    cout << endl;
    
    array1.agregarValor(valor);
    cout << "Precuencia con el valor agregado: " << endl;
    array1.mostrarPrecuencias();

    if(array1 != array2){
        cout << "Son clases diferentes. " << endl;
    }
    else{
        cout << "Son la misma clase. " << endl;
    }
    cout << endl;

    return 0;
}

/* Ejercicio 1. Se desea resolver el problema de sumas de enteros no negativos de gran tama~no (que
exceden la capacidad de representacion del tipo int. Para ello se propone crear la clase
BigInt que puede almacenar valores enteros de longitud indeterminada.

La clase representara un entero mediante un array (de longitud variable) de enteros,
reservado en memoria dinamica (donde cada entero representa uno de los dgitos del
entero largo a construir y solo podra tomar valores entre 0 y 9). El almacenamiento se
produce de forma que el valor menos signicativo se guarda en la posicion 0 del array. Dos
ejemplos de representacion de enteros se muestran a continuacion (para 9530273759835
y 0) */

#include <iostream>

using namespace std;

class BigInt{
    private:
        int tam;
        int *arrayInt;
    public:
        /*Constructor por defecto que crea un array de una posición
        con el valor 0 */
        BigInt(){
            tam = 0;
            *arrayInt = 0;
        }

        /* Constructor por parámetros */
        BigInt(int tamanio){
            arrayInt = new int[tamanio];
            tam = tamanio;
        }

        // Métodos get y set
        int getTam(){
            return tam;
        }
        int *getPtr(){
            return arrayInt;
        }
        void setTam(int tamanio){
            tam = tamanio;
        }
        void setPtr(int *ptr){
            arrayInt = ptr;
        }

        /* Método para mostrar el array utilizando
        punteros */
        void mostrar(){
            for(int i = 0; i < tam; i++){
                cout << *(arrayInt + i) << " ";
            }
            cout << endl;
        }

        /* Método que crea un véctor de enteros a partir
        de los datos introducidos por teclado */
        void insertar(){
            int cont = 0, num;

            /* Introduzco los dígitos que van a componer el número
            entero en un véctor, de atrás hacia delante. Cada dígito 
            debe de estar entre 0 y 9 */
            int i = tam - 1;
            do{
            cout << "Introduza el dígito " << cont << " del número: ";
            cin >> num;
                if(num >= 0 && num <= 9){
                    *(arrayInt + i) = num;
                    i--;
                    cont++;
                }
                else{
                    cout << "Error! Cada dígito debe de estar entre 0-9. " << endl; 
                }
            }while(i >= 0);
        }

        /* Método destructir para eliminar el 
        véctor y el espacio oculpado */
        ~BigInt(){
            if(arrayInt != 0){
                delete [] arrayInt;
                arrayInt = 0;
                tam = 0;
            }
        }

        // Constructor copia 
        BigInt(const BigInt &otra){
            this->arrayInt = new int[otra.tam];

            this->tam = otra.tam;
            
            for(int i = 0; i < tam; i++){
                *(this->arrayInt + i) = *(otra.arrayInt + i); 
            }   
        }

        /* Método que comprueba cuál es el mayor
        tamaño entre dos arrays */
        int tamMayor(int tam1, int tam2){
            if(tam2 > tam1)
                return tam2;
            else
                return tam1;
        }

        /* Método para sumar dos objetos de la 
        clase BigInt */
        BigInt * sumar(BigInt objt2){
            int tam_final, result, dig, cont, acarreo;
            
            /* Obtengo el tamaño mayor de los dos
            arrayr que voy a sumar, este tamaño correspondera
            con el tamaño del array resultante */
            tam_final = tamMayor(this->tam, objt2.tam);
            
            /* Reservo el espacio de la nueva clase,
            y creo el puntero que la identificará */
            BigInt *ptclase = new BigInt(tam_final);
            
            acarreo = 0;
            for(int i = 0; i < tam_final; i++){
                result = *(this->arrayInt + i) + *(objt2.arrayInt + i) + acarreo;
                if(result > 9){
                    result = result % 10;
                    acarreo = 1;
                } 
                else{
                    acarreo = 0;
                }  
                *(ptclase->arrayInt + i) = result;                 
            }

            /* Devuelvo el puntero a la 
            clase */
            return ptclase;
        } 

        friend ostream & operator<<(ostream &, const BigInt &);
};

/**
* Sobrescritura del oprador <<
* @param output
* @param array
* @return
*/
ostream & operator<<(ostream &output, const BigInt &array){
    output << endl;
    
    for(int i = 0; i < array.tam; i++){
        output << array.arrayInt[i] << " ";
    }
    output << endl;
   
    // Se devuelve output
    return output;
}

int main(){
    BigInt *array_sum;
    int tam1, tam3;

    /* Introduzco el tamaño por teclado
    y creo el array con los datos introducidos
    por teclado */
    cout << "Introduzca el tamaño del número: ";
    cin >> tam1;
    BigInt array1(tam1);
    array1.insertar();
    cout << "Array introducido: " << endl;
    array1.mostrar();

    /* Llamo al constructor copia
    e imprimo el array copiado */
    BigInt array2(array1);
    cout << "Array copiado: " << endl;
    array2.mostrar();

    /* Creo que array 3 para sumar dos
    objetos entre sí */
    cout << "Introduzca el tamaño del segundo número: ";
    cin >> tam3;
    BigInt array3(tam3);
    array3.insertar();

    /* Recibo el puntero al nuevo objeto
    que se ha creado con el método sumar */
    array_sum = array1.sumar(array3);
    cout << "Suma: " << endl;
    array_sum->mostrar();

    cout << "Uso de operador <<, array1: ";
    cout << array1;
    
    return 0;
}
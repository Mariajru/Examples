#include <iostream>
#include "BigInt.h"

using namespace std;

/*Constructor por defecto que crea un array de una posición
con el valor 0 */
BigInt::BigInt(){
    tam = 0;
    *arrayInt = 0;
}

/* Constructor por parámetros */
BigInt::BigInt(int tamanio){
    arrayInt = new int[tamanio];
    tam = tamanio;
}

// Métodos get y set
int BigInt::getTam(){
    return tam;
}
int *BigInt ::getPtr(){
    return arrayInt;
}
void BigInt::setTam(int tamanio){
    tam = tamanio;
}
void BigInt::setPtr(int *ptr){
    arrayInt = ptr;
}

/* Método para mostrar el array utilizando
punteros */
void BigInt::mostrar(){
    for(int i = 0; i < tam; i++){
        cout << *(arrayInt + i) << " ";
    }
    cout << endl;
}

/* Método que crea un véctor de enteros a partir
de los datos introducidos por teclado */
void BigInt::insertar(){
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
BigInt::~BigInt(){
    if(arrayInt != 0){
        delete [] arrayInt;
        arrayInt = 0;
        tam = 0;
    }
}

// Constructor copia 
BigInt::BigInt(const BigInt &otra){
    this->arrayInt = new int[otra.tam];

    this->tam = otra.tam;
    
    for(int i = 0; i < tam; i++){
        *(this->arrayInt + i) = *(otra.arrayInt + i); 
    }   
}

/* Método que comprueba cuál es el mayor
tamaño entre dos arrays */
int BigInt::tamMayor(int tam1, int tam2){
    if(tam2 > tam1)
        return tam2;
    else
        return tam1;
}

/* Método para sumar dos objetos de la 
clase BigInt */
BigInt *BigInt::sumar(BigInt objt2){
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




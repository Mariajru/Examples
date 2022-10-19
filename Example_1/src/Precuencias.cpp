#include <iostream>
#include "Pareja.h"
#include "Precuencias.h"

using namespace std;

// Constructor por defecto
Precuencias::Precuencias(){
    parejas = 0;
    npares = 0;
}

// Destructor
Precuencias::~Precuencias(){
    delete [] parejas;
    parejas = 0;
    npares = 0;
}

// Constructor de copia
Precuencias::Precuencias(Precuencias &objeto1){
    this->npares = objeto1.npares;

    this->parejas = new Pareja[npares];

    for(int i = 0; i < npares; i++){
        *(this->parejas + i) = objeto1.parejas[i];
    }
}


/* Método para guardas los valores
con su respectivo número de repeticiones */
void Precuencias::contarRepeticiones(int *num, int tam, int tam_dif){
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
void Precuencias::mostrarPrecuencias(){
    for(int i = 0; i < npares; i++){
        cout << "El dato " << (this->parejas + i)->devolverDato() << " aparece " << (this->parejas + i)->devolverVeces() << " veces." << endl;
    }
    cout << endl;
}

/* Método para agregar un valor
a la lista de Parejas */
void Precuencias::agregarValor(int valor){
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
bool Precuencias::operator==(const Precuencias &otro) const{
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
bool Precuencias::operator!=(const Precuencias &otro) const{
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




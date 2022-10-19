#include<iostream>
#include "Lista.h"
#include "Celda.h"

using namespace std;

/* Método que muestra por pantalla el contenido 
de una lista */
void Lista::mostrar(){
    // Me creo un puntero que apunta a un objeto de tipo Celda
    Celda *ptr;
    
    if(this->contenido){
        // Hago que el puntero apunte al objeto de nuestra clase
        ptr = this->contenido; // (ptr = contenido)
        
        // Mientras que ptr apunte a algo
        while(ptr){
            ptr->mostrar();
            ptr = ptr->obtenerSiguiente();
        }
    cout << endl;
    }
    else{
        cout << "No exite contenido en la lista" << endl;
    }
cout << endl;
}

/* Método que añade una nueva celda al final de
la lista */
void Lista::colocarFinal(double info){
    Celda *ptr;
    
    // Se recorre la lista hasta que el punteero apunte a 0
    if(this->contenido){ // Si la lista tiene contenido
        ptr = this->contenido;
        while(ptr->obtenerSiguiente() != 0){
            ptr = ptr->obtenerSiguiente();
        }
        Celda *ptrFin = new Celda(info);
        ptr->asignarSiguiente(ptrFin);
    }
    // Si la lista está vacía
    else{ 
        this->contenido = new Celda(info);
        ptr = this->contenido;
    }
} 

/* Método que devuelve la longitud
de la lista */
void Lista::obtenerLongitud(){
    Celda *ptr;
    int cont = 0;

    if(this->contenido){
        ptr = contenido;
        while(ptr != 0){
            cont++;
            ptr = ptr->obtenerSiguiente();
        }
    }
    cout << "Lista con longitud: " << cont << endl;
    cout << endl;
}

/* Método para eliminar la última
celda */
void Lista::eliminarFinal(int eliminar){
    Celda *ptr;
    // Si contenido apunte a algo
    if(this->contenido){
        for(int i = 0; i < eliminar; i++){
            // Si el puntero que apunta a la celda siguiente es diferente de 0
            if(this->contenido->obtenerSiguiente() != 0){
                ptr = this->contenido;
                while(ptr->obtenerSiguiente()->obtenerSiguiente() != 0){
                    ptr = ptr->obtenerSiguiente();
                }
                // Elimino el espacio que ocupaba la última celda
                delete ptr->obtenerSiguiente();
                ptr->anularSiguiente();
            }
        } 
    }
    // Si la lista no tiene celdas
    else{
        delete this->contenido->obtenerSiguiente();
        this->contenido = 0; 
        cout << "No existen elementos para eliminar" << endl;
    }
}

/* Método para insertar una nueca celda al
principio de la lista */
void Lista::Inicio(double info){
    // Si el puntero apunta a algo, es decir, la lista no está vacía
    if(contenido){
        Celda *ptr = new Celda(info);
        ptr->asignarSiguiente(contenido);
        contenido = ptr;
    }
    else{
        contenido = new Celda(info);
    }
}

/* Método que obtiene un puntero a la
celda que ocupa una posición determinada */
Celda *Lista::obtener(int posicion){
    Celda *ptr = contenido;
    /* Mientras i sea menor a la posición que estamos buscando,
    y el puntero apunte a alguna celda */
    for(int i = 0; i < posicion && ptr != 0; i++){
        ptr = ptr->obtenerSiguiente();
    }
    return ptr;
}

/* Método para insertar una celda en 
una posición concreta de la lista */
void Lista::agregarPosicion(Celda *pos, double dato){
    Celda *ptr = new Celda(dato);
    // Asigno al puntero donde apunta la posición siguiente
    ptr->asignarSiguiente(pos->obtenerSiguiente());
    pos->asignarSiguiente(ptr);
}

/* Método para liberar el espacio de memoria
utilizado */
void Lista::eliminar(){
    Celda *ptr;

    ptr = this->contenido;

    while(this->contenido){
        // El puntero al objeto apunta a la siguiente posición
        this->contenido = this->contenido->obtenerSiguiente(); 
        delete ptr;
        // Apunta al siguiente objeto
        ptr = this->contenido;
    }
    this->contenido = 0;
}

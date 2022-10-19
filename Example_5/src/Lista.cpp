#include<iostream>
#include "Lista.h"
#include "Celda.h"

using namespace std;

/* Método que muestra por pantalla el contenido 
de una lista por recursividad */
void Lista::mostrar(Celda *p){
    if(this->contenido){
        // Si la siguiente celda existe
        if(p->obtenerSiguiente()){
            p->mostrar();
            // Asigno el puntero a la siguiente posición
            p = p->obtenerSiguiente();
            // Llamo a la punción con el puntero asignado en la siguiente celda
            mostrar(p);
        }
        else{
            p->mostrar();
        }
    }
    // Si no existen celdas
    else{
        cout << "No exite contenido en la lista" << endl;
    }
} 

void Lista::mostrarInverso(Celda *p){
    if(this->contenido){
        // Si la siguiente celda existe
        if(p->obtenerSiguiente()){
            // Llamo a la función para el puntero que apunta a la siguiente celda
            mostrarInverso(p->obtenerSiguiente());
            p->mostrar();
        }
        else{
            p->mostrar();
        }
    }
    // Si no existen celdas
    else{
        cout << "No exite contenido en la lista" << endl;
    }
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
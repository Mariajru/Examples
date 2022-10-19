#include <iostream>
#include "Punto.h"
#include "Polilinea.h"

using namespace std;

/* Constructor por defecto */
Polilinea::Polilinea(){
    p = 0;
    num = 0;
}

/* Constructor para inicializar los
valores del array de puntos */
Polilinea::Polilinea(int tam){
    this->num = tam;
    /* Reservo espacio para un array de Puntos con un 
    tamaño de entrada */
    for(int i = 0; i < num; i++){
        this->p = new Punto[i];
    }
    // Relleno el array por teclado
    int x1, y1;
    Punto *ptr;
    ptr = this->p;
    for(int i = 0; i < num; i++){
        // Asigno los valores a los objetos del array
        cout << "Punto x" << i << ": ";
        cin >> x1;
        (ptr + i)->asignarX(x1);

        cout << "Punto y" << i << ": ";
        cin >> y1;
        (ptr + i)->asignarY(y1);
    }
    cout << endl;
}

/* Constructor de copia */
Polilinea::Polilinea(Polilinea &objeto1){
    // Inicializo los valores de la clase
    this->p = objeto1.p;
    this->num = objeto1.num;
    /* Reservo espacio de memoria para 
    el nuevo objeto y copio los 
    valores del objeto 1, en el nuevo
    array copia */
    for(int i = 0; i < num; i++){ // CAMBIAR
        this->p = new Punto[i];
    }

    /* Se asigna a cada valor de x e y para el nuevo objeto
    los valores de x e y del objeto 1 */
    for(int i = 0; i < num; i++){
        (this->p + i)->asignarX((objeto1.p + i)->devolverX());
        (this->p + i)->asignarY((objeto1.p + i)->devolverY());

    }
}

// Destructor
Polilinea::~Polilinea(){
    // Se libera el array de Puntos
    delete [] this->p;
    /* Se reestablecen los valores
    a 0 */
    this->p = 0;
    this->num = 0;
}

/* Método para mostrar el contenido 
de un véctor de objetos */
void Polilinea::mostrar(){
    for(int i = 0; i < num; i++){
        cout << "[ " << (this->p + i)->devolverX() << " ][ " << (this->p + i)->devolverY() << " ] ";
    }
    cout << endl;
}

/* Método para añadir un nuevo
punto en la Polilínea, en la primera
posición */
void Polilinea::agregarPunto(int x1, int y1){    
    // Creo un nuevo array del mismo tamaño que el actual + 1
    Punto *aux = new Punto[this->num + 1];

    /* Relleno el array con los mismos puntos,
    pero en este caso la posición inicial estará
    vacía */
    for(int i = 0; i < this->num; i++){
        *(aux + 1 + i) = *(this->p + i);
    } 

    /* Me creo el nuevo punto que voy a introducir
    en el nuevo array */
    Punto nuevo(x1, y1);

    /* Asigno a la primera posición del nuevo array
    el punto */
    this->num++;
    *(aux + 0) = nuevo;

    /* Borro array de puntos para dirigir el 
    puntero al nuevo array */
    delete [] this->p;
    this->p = aux; 
}     

/**
* Sobrescritura del operador +
* @param otro sumando2
* @return resultado de la suma
*/
Polilinea Polilinea::operator+(const Polilinea &otro) const{
    Polilinea *resultado = new Polilinea();
    resultado->num = this->num + otro.num;
    
    // Se crea el array que contendrá el resultado
    resultado->p = new Punto[resultado->num];

    // Se copian en primer lugar los valores de this y los de otro
    for(int i = 0; i < num; i++){
        resultado->p[i] = this->p[i];
    }

    for(int i = 0; i < otro.num; i++){
        resultado->p[num + i] = otro.p[i];
    }

    // Se devuelve el objeto creado
    return *resultado;
}

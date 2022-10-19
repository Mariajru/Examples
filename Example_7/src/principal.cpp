/* Ejercicio 4 */

#include <iostream>
#include "Celda.h"
#include "Lista.h"

using namespace std;

int main(){
    double valor, elemento, i_valor;
    int tam, longitud, longitud2, eliminados, pos, i_pos;
    Lista lista;
    Celda *ptr, *insertar;
    
    // DATOS POR TECLADO
    cout << "Introduza las celdas que contendrá la lista: ";
    cin >> tam;

    cout << "Introduza los valores para cada celda: ";
    for(int i = 0; i < tam; i++){  
        cin >> valor;
        lista.colocarFinal(valor); 
    }

    cout << "Cantidad de elementos del final de la lista desea eliminar: ";
    cin >> eliminados;

    cout << "Introduzca el elemento que desea insertar al inicio de la lista: ";
    cin >> elemento;

    cout << "Introduzca la posición de la celda de la que desea obtener su valor: ";
    cin >> pos;

    cout << "Introduzca la posición y el valor de celda que desea añadir a la lista: ";
    cin >> i_pos >> i_valor;

    // RESULTADOS
    cout << "Lista inicial: " << endl;
    lista.mostrar();
    lista.obtenerLongitud();

    cout << "Lista con " << eliminados << " elementos eliminados: " << endl;
    lista.eliminarFinal(eliminados);
    lista.mostrar();
    lista.obtenerLongitud();

    cout << "Lista tras insertar el elemento " << elemento << " al inicio de la lista: " << endl;
    lista.Inicio(elemento);
    lista.mostrar();
    lista.obtenerLongitud();

    ptr = lista.obtener(pos);
    cout << "El elemento de la posición " << pos << " es: " << ptr->obtenerInfo() << endl;
    cout << endl;

    insertar = lista.obtener(i_pos);
    cout << "Lista con tras añadir el nuevo elemento: " << endl;
    lista.agregarPosicion(insertar, i_valor);
    lista.mostrar();

    //LIBERO EL ESPACIO DE MEMORIA UTILIZADO
    lista.eliminar();

    return 0;
}
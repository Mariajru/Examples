/* Ejercicio 8 */

#include <iostream>
#include "Celda.h"
#include "Lista.h"

using namespace std;

int main(){
    double valor;
    int tam;
    Lista lista;
    Celda *mostrar;
    
    // DATOS POR TECLADO
    cout << "Introduza las celdas que contendrá la lista: ";
    cin >> tam;

    cout << "Introduza los valores para cada celda: ";
    for(int i = 0; i < tam; i++){  
        cin >> valor;
        lista.colocarFinal(valor); 
    }

    // RESULTADOS
    cout << "Lista mostrada de forma Recursiva: " << endl;
    lista.mostrar(lista.obtener(0));
    cout << endl;

    cout << "Lista invertida mostrada de forma Recursiva: " << endl;
    lista.mostrarInverso(lista.obtener(0));
    cout << endl;

    //LIBERO EL ESPACIO DE MEMORIA UTILIZADO
    lista.eliminar();

    return 0;
}

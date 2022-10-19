#include <iostream>
#include "Punto.h"
#include "Polilinea.h"

using namespace std;

int main(){
    int tam, tam_sum, posi, p1, p2, x1, y1;

    cout << "Introduzca la cantidad de puntos que contendrá el array: ";
    cin >> tam;
    Polilinea array1(tam);

    cout << "Introduzca el nuevo punto: " << endl;
    cout << "Nuevo x0: ";
    cin >> x1;
    cout << "Nuevo y0: ";
    cin >> y1; 
    cout << endl;
    
    cout << "Introduzca la cantidad de puntos que contendrá el array a sumar: ";
    cin >> tam_sum;
    Polilinea arraySum(tam_sum); 

    cout << "Array de puntos introducidos: " << endl;
    array1.mostrar();
   
    Polilinea array2(array1);
    cout << "Copia: " << endl;
    array2.mostrar();
     
    cout << "Array con el nuevo punto: " << endl;
    array1.agregarPunto(x1, y1);
    array1.mostrar();
        
    cout << "Arrays concatenados, operador +: " << endl;
    (array1 + arraySum).mostrar();

    return 0;
}

using namespace std;
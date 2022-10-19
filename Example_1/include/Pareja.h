#ifndef PAREJA_H
#define PAREJA_H

class Pareja{
    private:
        int dato; // Valor
        int nveces; // Número de repeticiones
    public:
        Pareja();

        Pareja(int valor, int veces);

        int devolverDato();

        int devolverVeces();

        void asignarDato(int valor);

        void asignarNveces(int num);

};

#endif
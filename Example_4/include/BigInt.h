#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>

using namespace std;

class BigInt{
    private:
        int tam;
        int *arrayInt;
    public:
        BigInt();
        BigInt(int tamanio);
        int getTam();
        int *getPtr();
        void setTam(int tamanio);
        void setPtr(int *ptr);

        void mostrar();
        void insertar();
        ~BigInt();
        BigInt(const BigInt &otra);
        int tamMayor(int tam1, int tam2);
        BigInt * sumar(BigInt objt2);
        friend ostream & operator<<(ostream &, const BigInt &);
};

#endif

#ifndef PUNTO_H
#define PUNTO_H

class Punto{
    private:
        int x, y;
    public:
        Punto();
        Punto(int x1, int y2);
        int devolverX();
        int devolverY();
        void asignarX(int x1);
        void asignarY(int y1);
};

#endif
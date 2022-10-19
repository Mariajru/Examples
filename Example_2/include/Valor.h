#ifndef VALOR_H
#define VALOR_H

class Valor{
  private:
    int fila;
    int columna;
    double valor;
  public:
    /**
     * Constructor por defecto
     */
    Valor();

    /**
     * Constructor de la clase
     * @param fila
     * @param columna
     * @param valor
     */
    Valor(int fil, int col, double val, int n);
    
    /**
     * Métodos para devolver los datos del objeto
     */
    int getFil();
    int getCol();
    double getVal();

    /**
     * Métodos para modificar los datos del objeto
    */
    void setFil(int fil);
    void setCol(int col);
    void setVal(double val);

};

#endif
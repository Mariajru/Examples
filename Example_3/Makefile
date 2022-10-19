OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all:	bin/principal

clean:
	echo "Limpieza de los archivos objeto y biblioteca"
	rm obj/*.o lib/*.a

$(OBJ)/Punto.o: $(SRC)/Punto.cpp $(INC)/Punto.h
	g++ -c -o $(OBJ)/Punto.o -I$(INC) $(SRC)/Punto.cpp

$(OBJ)/Polilinea.o: $(SRC)/Polilinea.cpp $(INC)/Polilinea.h
	g++ -c -o $(OBJ)/Polilinea.o -I$(INC) $(SRC)/Polilinea.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/Punto.o $(OBJ)/Polilinea.o
	ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/Punto.o $(OBJ)/Polilinea.o

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/Punto.h $(INC)/Polilinea.h
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(BIN)/principal: $(OBJ)/principal.o $(LIB)/libformas.a
	g++ -L$(LIB)/ -o bin/principal $(OBJ)/principal.o -lformas
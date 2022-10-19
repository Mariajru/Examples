OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all:	bin/principal

clean:
	echo "Limpieza de los archivos objeto y biblioteca"
	rm obj/*.o lib/*.a

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	g++ -c -o $(OBJ)/utilidades.o -I$(INC) $(SRC)/utilidades.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/utilidades.o
	ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/utilidades.o

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/utilidades.h
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(BIN)/principal: $(OBJ)/principal.o $(LIB)/libformas.a
	g++ -L$(LIB)/ -o bin/principal $(OBJ)/principal.o -lformas
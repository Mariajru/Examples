OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all:	bin/principal

clean:
	echo "Limpieza de los archivos objeto y biblioteca"
	rm obj/*.o lib/*.a

$(OBJ)/Matriz2D.o: $(SRC)/Matriz2D.cpp $(INC)/Matriz2D.h
	g++ -c -o $(OBJ)/Matriz2D.o -I$(INC) $(SRC)/Matriz2D.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/Matriz2D.o
	ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/Matriz2D.o

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/Matriz2D.h
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(BIN)/principal: $(OBJ)/principal.o $(LIB)/libformas.a
	g++ -L$(LIB)/ -o bin/principal $(OBJ)/principal.o -lformas
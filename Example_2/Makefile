OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all:	bin/principal

clean:
	echo "Limpieza de los archivos objeto y biblioteca"
	rm obj/*.o lib/*.a

$(OBJ)/MatrizDispersa.o: $(SRC)/MatrizDispersa.cpp $(INC)/MatrizDispersa.h
	g++ -c -o $(OBJ)/MatrizDispersa.o -I$(INC) $(SRC)/MatrizDispersa.cpp

$(OBJ)/Valor.o: $(SRC)/Valor.cpp $(INC)/Valor.h
	g++ -c -o $(OBJ)/Valor.o -I$(INC) $(SRC)/Valor.cpp

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	g++ -c -o $(OBJ)/utilidades.o -I$(INC) $(SRC)/utilidades.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/MatrizDispersa.o $(OBJ)/Valor.o $(OBJ)/utilidades.o
	ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/MatrizDispersa.o $(OBJ)/Valor.o $(OBJ)/utilidades.o

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/MatrizDispersa.h $(INC)/Valor.h $(INC)/utilidades.h
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(BIN)/principal: $(OBJ)/principal.o $(LIB)/libformas.a
	g++ -L$(LIB)/ -o bin/principal $(OBJ)/principal.o -lformas
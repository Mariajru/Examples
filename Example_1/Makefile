OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all:	bin/principal

clean:
	echo "Limpieza de los archivos objeto y biblioteca"
	rm obj/*.o lib/*.a

$(OBJ)/Pareja.o: $(SRC)/Pareja.cpp $(INC)/Pareja.h
	g++ -c -o $(OBJ)/Pareja.o -I$(INC) $(SRC)/Pareja.cpp

$(OBJ)/Precuencias.o: $(SRC)/Precuencias.cpp $(INC)/Precuencias.h
	g++ -c -o $(OBJ)/Precuencias.o -I$(INC) $(SRC)/Precuencias.cpp

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	g++ -c -o $(OBJ)/utilidades.o -I$(INC) $(SRC)/utilidades.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/Precuencias.o $(OBJ)/Pareja.o $(OBJ)/utilidades.o
	ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/Precuencias.o $(OBJ)/Pareja.o $(OBJ)/utilidades.o

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/Precuencias.h $(INC)/Pareja.h $(INC)/utilidades.h
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(BIN)/principal: $(OBJ)/principal.o $(LIB)/libformas.a
	g++ -L$(LIB)/ -o bin/principal $(OBJ)/principal.o -lformas
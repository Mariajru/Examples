OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all:	bin/principal

clean:
	echo "Limpieza de los archivos objeto y biblioteca"
	rm obj/*.o lib/*.a

$(OBJ)/Lista.o: $(SRC)/Lista.cpp $(INC)/Lista.h
	g++ -c -o $(OBJ)/Lista.o -I$(INC) $(SRC)/Lista.cpp

$(OBJ)/Celda.o: $(SRC)/Celda.cpp $(INC)/Celda.h
	g++ -c -o $(OBJ)/Celda.o -I$(INC) $(SRC)/Celda.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/Lista.o $(OBJ)/Celda.o
	ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/Lista.o $(OBJ)/Celda.o

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/Lista.h $(INC)/Celda.h
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(BIN)/principal: $(OBJ)/principal.o $(LIB)/libformas.a
	g++ -L$(LIB)/ -o bin/principal $(OBJ)/principal.o -lformas
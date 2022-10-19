OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all:	bin/principal

clean:
	echo "Limpieza de los archivos objeto y biblioteca"
	rm obj/*.o lib/*.a

$(OBJ)/BigInt.o: $(SRC)/BigInt.cpp $(INC)/BigInt.h
	g++ -c -o $(OBJ)/BigInt.o -I$(INC) $(SRC)/BigInt.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/BigInt.o 
	ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/BigInt.o 

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/BigInt.h 
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(BIN)/principal: $(OBJ)/principal.o $(LIB)/libformas.a
	g++ -L$(LIB)/ -o bin/principal $(OBJ)/principal.o -lformas

SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all:  $(BIN)/testimagen $(BIN)/testASCII $(BIN)/testplano $(BIN)/arteASCII $(BIN)/suma

$(BIN)/suma: $(OBJ)/suma.o $(LIB)/libimagen.a
		g++ -g $< -o $@ -L$(LIB) -limagen -std=c++0x

$(OBJ)/suma.o: $(SRC)/suma.cpp $(INC)/imagen.h
		g++ -c $(SRC)/suma.cpp -o $(OBJ)/suma.o -I$(INC)/ -std=c++0x

$(BIN)/testimagen: $(OBJ)/testimagen.o $(LIB)/libimagen.a
	g++ -g $< -o $@ -L$(LIB) -limagen -std=c++0x

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -I$(INC)/ -std=c++0x



$(BIN)/testASCII: $(OBJ)/testASCII.o $(LIB)/libimagen.a
	g++ -g $< -o $@ -L$(LIB) -limagen -std=c++0x

$(OBJ)/testASCII.o: $(SRC)/testASCII.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testASCII.cpp -o $(OBJ)/testASCII.o -I$(INC)/ -std=c++0x



$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	g++ -g $< -o $@ -L$(LIB) -limagen -std=c++0x

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp $(INC)/imagen.h
	g++ -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o -I$(INC)/  -std=c++0x


$(BIN)/testplano: $(OBJ)/testplano.o $(LIB)/libimagen.a
	g++ -g $< -o $@ -L$(LIB) -limagen -std=c++0x

$(OBJ)/testplano.o: $(SRC)/testplano.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o -I$(INC)/ -std=c++0x




$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o



$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	g++ -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -I$(INC)/ -std=c++0x

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -I$(INC)/

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	g++ -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -I$(INC)/

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	g++ -c $(SRC)/lista.cpp -o $(OBJ)/lista.o -I$(INC)/

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

mrproper:
	rm obj/*.o bin/* lib/*

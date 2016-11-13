
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++0x -c -g -I$(INC)/
AR = ar
ARFLAGS = rvs
LDFLAGS = -L$(LIB)
LDLIBS = -limagen

all : $(BIN)/testimagen $(BIN)/testplano $(BIN)/testASCII $(BIN)/arteASCII $(BIN)/suma

$(BIN)/suma : $(OBJ)/suma.o $(LIB)/libimagen.a
	$(CXX) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(OBJ)/suma.o : $(SRC)/suma.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN)/arteASCII : $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	$(CXX) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(OBJ)/arteASCII.o : $(SRC)/arteASCII.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN)/testASCII : $(OBJ)/testASCII.o $(LIB)/libimagen.a
	$(CXX) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(OBJ)/testASCII.o : $(SRC)/testASCII.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN)/testplano : $(OBJ)/testplano.o $(LIB)/libimagen.a
	$(CXX) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(OBJ)/testplano.o : $(SRC)/testplano.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN)/testimagen : $(OBJ)/testimagen.o $(LIB)/libimagen.a
	$(CXX) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(OBJ)/testimagen.o : $(SRC)/testimagen.cpp $(INC)/imagen.h $(INC)/pgm.h
	$(CXX) $(CXXFLAGS) $< -o $@

$(LIB)/libimagen.a : $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	$(AR) $(ARFLAGS) $@ $^

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ)/pgm.o : $(SRC)/pgm.cpp $(INC)/pgm.h
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ)/byte.o : $(SRC)/byte.cpp $(INC)/byte.h
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	$(CXX) $(CXXFLAGS) $< -o $@

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean :
	@ echo "Limpiando..."
	rm -f $(OBJ)/*.o $(LIB)/lib*.a

cleanimages :
	rm -f *.pgm *.txt

mrproper : clean cleanimages
	rm -f $(BIN)/*

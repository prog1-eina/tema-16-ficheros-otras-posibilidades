################################################################################
## Fichero «Makefile» para los programas del repositorio
## «tema-16-ficheros-otras-posibilidades»:
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS
SOURCE_DIR = .
CALCULOS_DIR = ../practica3/src/calculadora/
BUILD_DIR = build
BIN_DIR = bin

VPATH = $(SOURCE_DIR) $(CALCULOS_DIR)

## COMPILADOR Y OPCIONES DE COMPILACIÓN:
CXX = g++
CXXFLAGS = -g -Wall -Wextra -I$(CALCULOS_DIR)


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):
OBJECTS_ACCESO_DIRECTO = $(addprefix $(BUILD_DIR)/, 2-acceso-directo.o fichero-primos.o calculos.o)
OBJECTS_LECTURA_ESCRITURA = $(addprefix $(BUILD_DIR)/, 3-lectura-escritura.o fichero-primos.o calculos.o)

################################################################################
## Reglas del fichero «Makefile»

linea-adicional: $(SOURCE_DIR)/1-linea-adicional.cpp
	$(CXX) -g -o $@ $^ -static

acceso-directo: $(OBJECTS_ACCESO_DIRECTO) 
	$(CXX) -g -o $@ $^ -static

lectura-escritura: $(OBJECTS_LECTURA_ESCRITURA) 
	$(CXX) -g -o $@ $^ -static

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(BUILD_DIR)/2-acceso-directo.o: fichero-primos.hpp
$(BUILD_DIR)/3-lectura-escritura.o: fichero-primos.hpp calculos.hpp
$(BUILD_DIR)/fichero-primos.o: fichero-primos.hpp calculos.hpp
$(BUILD_DIR)/calculos.o: calculos.hpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
	if exist linea-adicional.exe del /q linea-adicional.exe
	if exist acceso-directo.exe del /q acceso-directo.exe
	if exist lectura-escritura.exe del /q lectura-escritura.exe
else
	rm -f $(OBJECTS) $(BIN_DIR)/*
	rm linea-adicional
	rm acceso-directo
	rm lectura-escritura
endif

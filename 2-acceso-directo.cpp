﻿/******************************************************************************\
 * Curso de Programación 1. Tema 16 (acceso directo)
 * Autores: Miguel Ángel Latre
 * Última revisión: 13 de diciembre de 2019
 * Resumen: Función que utiliza acceso directo en un fichero en lugar de acceso
 *          secuencial (se presenta también una versión que usa acceso 
 *          secuencial)
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make acceso-directo
  *       o ejecutar la tarea "Compilar «acceso-directo»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           ./acceso-directo
 *       o, en Windows,
 *           .\acceso-directo.exe
 *       o ejecutar la tarea "Ejecutar «acceso-directo»" de VSC.
\******************************************************************************/
#include <iostream>
#include <fstream>
#include "fichero-primos.hpp"
using namespace std;


/*
 * Pre:  El fichero de nombre «nombreFichero» almacena al menos los primeros
 *       «i» números primos, almacenados en orden ascendente.
 * Post: Devuelve el «i»-ésimo (comenzando a contar por 1) número primo, 
 *       según el contenido del fichero. Si no se puede abrir el fichero, escribe 
 *       un mensaje de error en «cerr» y devuelve un valor negativo.
 * Nota: Versión secuencial de la función
 */
unsigned leerUnPrimo_secuencial(const string nombreFichero, 
                                    const unsigned i) {
    ifstream f(nombreFichero, ios::binary);
    if (f.is_open()) {
        unsigned primo;
        for(unsigned j = 1; j <= i; j++) {
            f.read(reinterpret_cast<char*>(&primo), sizeof(primo));
        }
        f.close();
        return primo;
    } else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido leer el fichero \""
             << nombreFichero << "\"" << endl;
        return -1;
    }
}


/*
 * Pre:  El fichero de nombre «nombreFichero» almacena al menos los primeros
 *       «i» números primos, almacenados en orden ascendente.
 * Post: Devuelve el «i»-ésimo (comenzando a contar por 1) número primo, 
 *       según el contenido del fichero. Si no se ha podido abrir el fichero, ha
 *       escrito un mensaje de error en «cerr» y devuelve un valor negativo.
 * Nota: Versión de la función que utiliza acceso directo.
 */
unsigned leerUnPrimo(const string nombreFichero, const unsigned i) {
    ifstream f(nombreFichero, ios::binary);
    if (f.is_open()) {
        f.seekg((i - 1) * sizeof(unsigned));
        unsigned primo;
        f.read(reinterpret_cast<char*>(&primo), sizeof(primo));
        f.close();
        return primo;
    } else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido leer el fichero \""
             << nombreFichero << "\"" << endl;
        return -1;
    }
}

/*
 * Programa de prueba de la función «leerUnPrimo».
 */
int main() {
    asegurarFicheroPrimos(NOMBRE_FICHERO_PRIMOS, NUM_PRIMOS);
    int n;
    do {
        cout << "Escriba un número entre 1 y " << NUM_PRIMOS << " (0 para acabar): ";
        cin >> n;
        if (1 <= n && n <= int(NUM_PRIMOS))
        cout << n << "º número primo: " << leerUnPrimo(NOMBRE_FICHERO_PRIMOS, n) << endl;
    } while (n != 0);
    return 0;
}

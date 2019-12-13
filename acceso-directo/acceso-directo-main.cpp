/********************************************************************************\
 * Curso de Programación 1. Tema 16 (acceso directo)
 * Autores: Miguel Ángel Latre
 * Última revisión: 13 de diciembre de 2019
 * Resumen: Función que utiliza acceso directo en un fichero en lugar de acceso
 *          secuancial (se presenta también una versión que usa acceso secuencial)
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdio>
#include "../../Biblioteca/nif.h"
using namespace std;


/*
 * Pre:  El fichero de nombre «nombreFichero» almacena al menos los primeros
 *       «i» números primos, almacenados en orden ascendente.
 * Post: Ha devuelto el «i»-ésimo (comenzando a contar por 1) número primo, 
 *       según el contenido del fichero.
 * Nota: Versión secuencial de la función
 */
void leerUnNifBin_versionSecuencial(const char nombreFichero[], int i, Nif& nif) {
    ifstream f(nombreFichero, ios::binary);
    if (f.is_open()) {
        int n;
        f.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int j = 0; j < i; j++) {
            f.read(reinterpret_cast<char*>(&nif), sizeof(nif));
        }
        f.close();
    }
    else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido leer el fichero \""
             << nombreFichero << "\"" << endl;
    }
}

/*
 * Pre:  El de fichero de nombre «nombreFichero» almacena la siguiente
 *       información codificada en binario que representa una secuencia
 *       de NIF: En primer lugar el número de NIF almacenados en el
 *       fichero; este número es mayor que cero y mayor que «i». Le sigue
 *       una secuencia de datos de tipo «Nif».
 * Post: Asigna a «nif» el NIF «i»-ésimo almacenado en el fichero.
 * Nota: Versión de la función que utiliza acceso directo.
 */
void leerUnNifBin(const char nombreFichero[], int i, Nif& nif) {
    ifstream f(nombreFichero, ios::binary);
    if (f.is_open()) {
        f.seekg(sizeof(int) + (i - 1) * sizeof(Nif));
        f.read(reinterpret_cast<char*>(&nif), sizeof(nif));
    }
    else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido leer el fichero \""
             << nombreFichero << "\"" << endl;
    }
}


/********************************************************************************\
 * Curso de Programación 1. Tema 16 (modo «append»)
 * Autores: Miguel Ángel Latre
 * Última revisión: 13 de diciembre de 2019
 * Resumen: Función que inserta al final de un fichero de texto una línea
 *          adicional (versión usando y sin usar el modo «append»).
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

/*
 * Pre:  «nombreFichero» hace referencia a un fichero de texto existente y
 *       modificable.
 * Post: Inserta al final del fichero de denominado «nombreFichero» una línea
 *       completa cuyo contenido sea la cadena de caracteres «linea».
 * Nota: Esta versión no utiliza el modo «append».
 */
void unaLineaAdicional_sinModoAppend(const char nombreFichero[],
                                     const char linea[]) {
    const char FICHERO_TEMPORAL[] = "temporal.tmp";
    ifstream fOriginal;
    fOriginal.open(nombreFichero);
    if (fOriginal.is_open()) {
        ofstream fTemporal;
        fTemporal.open(FICHERO_TEMPORAL);
        if (fTemporal.is_open()) {
            char c;
            fOriginal.get(c);
            while (!fOriginal.eof()) {
                fTemporal.put(c);
                fOriginal.get(c);
            }
            fTemporal << linea << endl;
            fTemporal.close();
            fOriginal.close();
            remove(nombreFichero);
            rename(FICHERO_TEMPORAL, nombreFichero);
        }
        else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido escribir el fichero \""
             << FICHERO_TEMPORAL << "\"" << endl;
        }
    }
    else {
    // Escritura de un mensaje de error si no se ha podido abrir el fichero
    cerr << "No se ha podido leer el fichero \""
         << nombreFichero << "\"" << endl;
    }
}

/*
 * Pre:  «nombreFichero» hace referencia a un fichero de texto existente y
 *       modificable.
 * Post: Inserta al final del fichero de denominado «nombreFichero» una línea
 *       completa cuyo contenido sea la secuencia de caracteres de «linea».
 * Nota: Esta versión utiliza el modo «append».
 */
void unaLineaAdicional(const char nombreFichero[], const char linea[]) {
    ofstream f;
    f.open(nombreFichero, ios::app);
    if (f.is_open()) {
        f << linea << endl;
        f.close();
    }
    else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido escribir en el fichero \""
            << nombreFichero << "\"" << endl;
    }
}

/*
 * Pre:  Existe un fichero denominado "1-una-linea-adicional.cpp" en el directorio
 *       en el que se ejecuta este programa.
 * Post: A modo de prueba, a añadido una línea que contiene un comentario C++ al
 *       final del fichero "1-una-linea-adicional.cpp".
 */
int main() {
   unaLineaAdicional("../linea-adicional-main.cpp",
                     "// Función «unaLineaAdicional» probada");
    return 0;
}

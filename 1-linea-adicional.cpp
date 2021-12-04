/******************************************************************************\
 * Curso de Programación 1. Tema 16 (modo «append»)
 * Autores: Miguel Ángel Latre
 * Última revisión: 19 de diciembre de 2020
 * Resumen: Función que inserta al final de un fichero de texto una línea
 *          adicional (versión usando y sin usar el modo «append»).
 * Nota: El programa completo está contenido en este fichero, por lo que puede 
 *       compilarse y ejecutarse con la extensión Code Runner de Visual Studio 
 *       Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 1-linea-adicional.cpp -o 1-linea-adicional
 *       y ejecutarse en Windows a través de la orden
 *           .\1-linea-adicional.exe
 *       o en Linux y macOS
 *           ./1-linea-adicional
 *       o ejecutar la tarea "Ejecutar «linea-adicional»" de VSC.
\******************************************************************************/

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
void unaLineaAdicional_sinModoAppend(const string nombreFichero,
                                     const string linea) {
    const string FICHERO_TEMPORAL = "temporal.tmp";
    ifstream fOriginal;
    fOriginal.open(nombreFichero);
    if (fOriginal.is_open()) {
        ofstream fTemporal;
        fTemporal.open(FICHERO_TEMPORAL);
        if (fTemporal.is_open()) {
            char c;
            while (fOriginal.get(c)) {
                fTemporal.put(c);
            }
            fTemporal << linea << endl;
            fTemporal.close();
            fOriginal.close();
            remove(nombreFichero.c_str());
            rename(FICHERO_TEMPORAL.c_str(), nombreFichero.c_str());
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
void unaLineaAdicional(const string nombreFichero, const string linea) {
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
 * Pre:  Existe un fichero denominado "1-linea-adicional.cpp" en el directorio
 *       en el que se ejecuta este programa.
 * Post: A modo de prueba, a añadido una línea que contiene un comentario C++ al
 *       final del fichero "1-linea-adicional.cpp".
 */
int main() {
    unaLineaAdicional("1-linea-adicional.cpp",
                     "// Función «unaLineaAdicional» probada");
    return 0;
}

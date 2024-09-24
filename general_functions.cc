/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Computabilidad y Algoritmia
** Curso: 2º
** Practica 2: Cadenas y lenguajes
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 20/09/2024

** Archivo help_functions.h: Archivo de cabecera con las funciones de ayuda
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**      21/09/2024 - Adición de las funciones de lectura y escritura
**      23/09/2024 - Mejora del control de errores
**      24/09/2024 - Manejo de casos en donde el alfabeto no se corresponde a la cadena
**      24/09/2024 - Eliminación de métodos de apertura y clausura. Ver "cya-P02-strings.cc"
**/

#include <iostream>

#include "general_functions.h"

/**
 * @brief Prints how to use the client program
 */
void Usage() {
  std::cout << "How to use: ./cya-P02-strings filein.txt fileout.txt opcode\n"
            << "Try 'cya-P02-strings --help' for further information\n";
}

/**
 * @brief Brings help if "./cya-P02-strings --help" is typed
 */
void Help () {
    std::cout << "./cya-P02-strings -- Symbols, strings, alphabets and formal languages\n"
              << "How to use:          ./cya-P02-strings filein.txt fileout.txt opcode\n"
              << "\n"
              << "filein.txt:      Input file: Format must be <chain> <alphabet> both without spaces within them.\n"
              <<                                  "- <alphabet> cannot have duplicated symbols\n"
              << "fileout.txt:     Output file\n"
              << "opcode:          Type the wanted opcode (int-type): \n"
              << "                 1. Alphabet: Asociated alphabet to the input chains\n"
              << "                 2. Size: Size of the input chains\n"
              << "                 3. Inverse:  Inverse of the input chains\n"
              << "                 4. Prefixes: Prefix languages by input chains\n"
              << "                 5. Sufixes:  Sufix languages by input chains\n"
              << "\n";
}
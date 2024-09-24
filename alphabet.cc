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

** Archivo alphabet.cc: Implementación de la clase alfabeto.
**      Contiene las implementaciones de la clase alfabeto.
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**      23/09/2024 - Adición del método empty
**      24/09/2024 - Manejo de casos en donde el alfabeto no se corresponde a la cadena
**/

#include <iostream>
#include "alphabet.h"


bool Alphabet::Empty() const {
  return symbols_.empty();
}

/**
 * @brief Function to add a symbol to an alphabet
 * @param symbol 
 */
void Alphabet::AddSymbol (const Symbol& symbol) {
  symbols_.insert(symbol);
}

/**
 * @brief Overload of << operator for Alphabet class
 * @param std::ostream  
 * @param symbol
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& symbols)  {
  int counter {0};
  int alphabet_size = symbols.getSymbols().size();
  os << "{";
  for (const Symbol& symbol : symbols.getSymbols()) {
    os << symbol;
    if (counter < alphabet_size - 1) {
      os << ", ";
    }
    ++counter;
  }
  os << "}";
  return os;
}

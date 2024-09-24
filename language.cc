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

** Archivo language.cc: Implementación de la clase lenguaje.
**      Contiene las implementaciones de la clase lenguaje.
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**      23/09/2024 - Mejora del operador << y adición del método insert
**      24/09/2024 - Eliminación de los métodos prefijos y sufijos (ver chain.h)
**/

#include <iostream>

#include "alphabet.h"
#include "chain.h"
#include "language.h"

/**
 * @brief Default constructor for Language class
 */
Language::Language() {
  language_.insert(Chain(std::vector<Symbol>{('&')}));
}

/**
 * @brief Designed constructor for Language class
 * @param Alphabet object
 */
Language::Language(const Alphabet& alphabet) {
  language_.insert(Chain(std::vector<Symbol>{('&')}));
  for (const Symbol& symbols : alphabet.getSymbols()) {
    language_.insert(Chain(std::vector<Symbol>{(symbols)}));
  }
}

/**
 * @brief Insert method to add a chain to the language
 * @param chain object
 */
void Language::insert(const Chain& new_chain) {
  language_.insert(new_chain);
}

/**
 * @brief Overload of << operator for Language class
 * @param std::ostream  
 * @param Language
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Language& lang) {
  const std::set<Chain>& languages = lang.getLanguage();
  os << "{";
  bool first = true;
  for (const auto& chains : languages) {
    if (!chains.Empty()) {
      if (first) {
        os << chains;
        first = false;
      } else {
        os << ", " << chains;
      }
    }
  }
  os << "}";
  return os;
}

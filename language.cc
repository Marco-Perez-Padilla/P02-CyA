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
**      23/09/2024 - Mejora del operador <<
**/

#include <iostream>

#include "alphabet.h"
#include "language.h"

/**
 * @brief Default constructor for Language class
 */
language::language() {
  language_.insert(chain(std::vector<symbol>{('&')}));
}

/**
 * @brief Designed constructor for Language class
 * @param Alphabet object
 */
language::language(const alphabet& alphabet) {
  language_.insert(chain(std::vector<symbol>{('&')}));
  for (const symbol& symbols : alphabet.getSymbols()) {
    language_.insert(chain(std::vector<symbol>{(symbols)}));
  }
}

/**
 * @brief Generation of prefixes language using subvectors
 * @param Chain 
 * @return Prefixes language
 */
const language language::Prefixes (const chain& original_chain) const {
  std::set<chain> all_prefixes;
  const std::vector<symbol>& symbols = original_chain.getChain();
  for (unsigned int i{0}; i <= symbols.size(); ++i) {
    std::vector<symbol> prefix(symbols.begin(), symbols.begin() + i);
    all_prefixes.insert(chain(prefix));
  }
  return all_prefixes;
}

/**
 * @brief Generation of sufixes language using subvectors
 * @param Chain
 * @return Sufixes language
 */
const language language::Sufixes (const chain& original_chain) const {
  std::set<chain> all_sufixes;  
  const std::vector<symbol>& symbols = original_chain.getChain();
  for (size_t i = 0; i <= symbols.size(); ++i) {
    std::vector<symbol> sufix(symbols.begin() + i, symbols.end()); 
    all_sufixes.insert(chain(sufix));  
  }
  return all_sufixes;  
}

/**
 * @brief Overload of << operator for Language class
 * @param std::ostream  
 * @param Language
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const language& lang) {
  int counter {0};
  int language_size = lang.getCardinal();
  const std::set<chain>& languages = lang.getLanguage();
  os << "{";
  for (const auto& chains : languages) {
    os << chains;
    if (counter < language_size - 1) {
      os << ", ";
    }
    ++counter;
  }
  os << "}";
  return os;
}

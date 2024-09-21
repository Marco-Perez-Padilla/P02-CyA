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

** Archivo chain.cc: Implemenatción de la clase cadena.
**      Contiene las implementaciones de la clase cadena.
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**/

#include <algorithm>
#include <iostream>
#include <fstream>

#include "chain.h"

/**
 * @brief Method to get the size of a chain (Longitud)
 * @return int size
 */
const int chain::ChainSize() const {
  return chain_.size();
}

/**
 * @brief Method Inverse of a chain object
 * @return chain object. Inverse of invoker chain
 */
const chain chain::Inverse () const {
  std::vector<symbol> reversed_chain = chain_;
  std::reverse(reversed_chain.begin(), reversed_chain.end());
  return reversed_chain;
}

/**
 * @brief Addition of new symbols to the chain
 * @param symbol
 * @return Previous chain with the wanted addition
 */
void chain::AddBack (const symbol& new_symbol) {
  chain_.push_back(new_symbol);
}

/**
 * @brief Overload of < operator
 * @param chain
 * @return bool-type
 */
bool chain::operator<(const chain& chain) const {
  return chain_ < chain.getChain(); 
}

/**
 * @brief Overload of == operator
 * @param chain
 * @return bool-type
 */
bool chain::operator==(const chain& chain) const {
  return chain_ == chain.getChain();
}

/**
 * @brief Overload of << operator for Chain class
 * @param std::ostream  
 * @param chain
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const chain& chains) {
  const std::vector<symbol>& symbols = chains.getChain();
  for (size_t i = 0; i < symbols.size(); ++i) {
    os << symbols[i];
  }
  return os;
}

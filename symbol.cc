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

** Archivo symbol.cc: Implementación de las clase símbolo.
**      Contiene las implementaciones de la clase símbolo.
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**/

#include <iostream>

#include "symbol.h"

/**
 * @brief Overload of < operator for Symbol class
 * @param symbol 
 * @return boolean-type
 */
bool symbol::operator<(const symbol& character) const {
  return character_ < character.getCharacter();
}

/**
 * @brief Overload of == operator for Symbol class
 * @param symbol 
 * @return boolean-type
 */
bool symbol::operator==(const symbol& character) const {
  return character_ == character.getCharacter();
}

/**
 * @brief Overload of << operator for Symbol class
 * @param std::ostream  
 * @param symbol
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const symbol& symbol) {
  return os << symbol.getCharacter();
}

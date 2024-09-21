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

** Archivo alphabet.h: Declaración de la clase alfabeto.
**      Contiene las declaraciones de la clase alfabeto.
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**/

#ifndef ALPHABET_H
#define ALPHABET_H

#include <set>

#include "symbol.h"

class alphabet {
 private:
  std::set<symbol>symbols_;

 public:
  alphabet() = default;
  alphabet (const std::set<symbol>& symbols) : symbols_(symbols) {}  //Constructor
  const std::set<symbol>& getSymbols () const {return symbols_;} //Getter

  void AddSymbol (const symbol&); //Function to add symbols to the alphabet
};
std::ostream& operator<<(std::ostream& os, const alphabet&); //Overload of out stream operator for alphabet class

#endif
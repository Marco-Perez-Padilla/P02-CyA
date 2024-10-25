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

** Archivo chain.h: Declaración de la clase cadena.
**      Contiene las declaraciones de la clase cadena.
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**      23/09/2024 - Adición del método empty
**      24/09/2024 - Adición de los métodos prefijos y sufijos 
**/

#ifndef CHAIN_H
#define CHAIN_H

#include <vector>

#include "symbol.h"
#include "language.h"

class Chain {
 private:
  std::vector<Symbol> chain_;

 public:
  //Constructors
  Chain() = default;
  Chain(const std::vector<Symbol>& chain) : chain_(chain) {}   
  //Getter
  const std::vector<Symbol>& getChain () const {return chain_;} 
  //Functions for chain class
  const int ChainSize() const;
  const Chain Inverse () const;
  void AddBack (const Symbol& new_symbol);
  bool Empty() const;
  const Language Prefixes () const;
  const Language Sufixes () const;
  //Overload of operators
  bool operator<(const Chain&) const;
  bool operator==(const Chain&) const;
};
std::ostream& operator<<(std::ostream& os, const Chain&);

#endif
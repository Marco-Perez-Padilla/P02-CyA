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
**/

#ifndef CHAIN_H
#define CHAIN_H

#include <vector>

#include "symbol.h"

class chain {
 private:
  std::vector<symbol> chain_;

 public:
  //Constructors
  chain() = default;
  chain(const std::vector<symbol>& chain) : chain_(chain) {}   
  //Getter
  const std::vector<symbol>& getChain () const {return chain_;} 
  //Functions for chain class
  const int ChainSize() const;
  const chain Inverse () const;
  void AddBack (const symbol& new_symbol);
  //Overload of operators
  bool operator<(const chain&) const;
  bool operator==(const chain&) const;
};
std::ostream& operator<<(std::ostream& os, const chain&);

#endif
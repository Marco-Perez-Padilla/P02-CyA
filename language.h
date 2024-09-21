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

** Archivo language.h: Declaración de la clase lenguaje.
**      Contiene las declaraciones de la clase lenguaje.
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**/

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <set>

#include "chain.h"

class language {
 private:
  std::set<chain> language_;

 public:
  //Default constructor
  language();
  //Constructor given an alphabet
  language(const alphabet& alphabet);
  //Constructor given a specific set of chains
  language(const std::set<chain>& subset) : language_(subset) {}
  //Getters
  std::set<chain> getLanguage() const {return language_;}
  const int getCardinal() const {return language_.size();}
  //Functions for Language class
  const language Prefixes (const chain&) const;
  const language Sufixes (const chain&) const;
};
std::ostream& operator<<(std::ostream& os, const language&);

#endif
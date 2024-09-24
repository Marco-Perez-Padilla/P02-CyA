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
**      23/09/2024 - Mejora del operador << y adición del método insert
**      24/09/2024 - Eliminación de los métodos prefijos y sufijos (ver chain.h)
**/

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <set>

//Forward declarations to solve circular inclusion
class Chain;
class Alphabet;

class Language {
 private:
  std::set<Chain> language_;

 public:
  //Default constructor
  Language();
  //Constructor given an alphabet
  Language(const Alphabet& alphabet);
  //Constructor given a specific set of chains
  Language(const std::set<Chain>& subset) : language_(subset) {}
  //Getters
  std::set<Chain> getLanguage() const {return language_;}
  const int getCardinal() const {return language_.size();}
  //Functions for Language class
  void insert(const Chain& new_chain);
};
std::ostream& operator<<(std::ostream& os, const Language&);

#endif
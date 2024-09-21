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

** Archivo symbol.h: Declaración de la clase símbolo
**      Contiene las declaraciones de la clase símbolo
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**/

#ifndef SYMBOL_H
#define SYMBOL_H

class symbol {
 private:
  char character_;

 public:
  symbol (char character) : character_(character) {}; //Constructor for class symbol
  char getCharacter () const {return character_;} //Getter

  //Operators
  bool operator< (const symbol&) const;
  bool operator== (const symbol&) const;
};
std::ostream& operator<<(std::ostream& os, const symbol&); //Overload of out stream operator for symbol class

#endif
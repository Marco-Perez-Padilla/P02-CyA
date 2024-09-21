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

** Archivo cya-P02-strings.cc: programa cliente.
**      Contiene la funcion main del proyecto que usa las clases X e Y
**      para ... (indicar brevemente el objetivo)
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**/
 
#include <iostream>

#include "general_functions.h"
#include "alphabet.h"
#include "chain.h"
#include "language.h"
#include "symbol.h"

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    Help();
    exit(EXIT_SUCCESS);
  }
  
  if (argc != 4) {
    Usage();
    exit(EXIT_SUCCESS);
  }
  
  std::vector<chain> input_chains;
  std::vector<alphabet> input_alphabets;
  
  Read(std::string(argv[1]), input_chains, input_alphabets);

  int option = std::stoi(argv[3]);
  const std::string out_file = std::string(argv[2]);

  switch(option) {
    case 1:
      Write(out_file, input_alphabets);
      break;
    case 2:
      WriteChainSize(out_file, input_chains);
      break;
    case 3:
      WriteInverse(out_file, input_chains);
      break;
    case 4:
      WritePrefixes(out_file, input_chains);
      break;
    case 5:
      WriteSufixes(out_file, input_chains);
      break;
    default:
      std::cerr <<"Parameter not valid. Option must be between 1-5";
      exit(EXIT_FAILURE);
  }
  return 0;
}
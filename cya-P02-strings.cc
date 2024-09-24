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
**      Contiene la funcion main del proyecto que usa las clases cadena, alfabeto y lenguaje
**      para escribir alfabetos, cadenas inversas, longitudes, sufijos y prefijos
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**      21/09/2024 - Segunda versión del código
**      24/09/2024 - Manejo de casos en donde el alfabeto no se corresponde a la cadena
**/
 
#include <iostream>
#include <fstream>
#include <cctype> //isdigit()

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
    exit(EXIT_FAILURE);
  }

  std::string opcode = argv[3];

  if (!isdigit(opcode[0])) {
    Usage();
    exit(EXIT_FAILURE);
  }
  
  int option = std::stoi(argv[3]);
  const std::string in_file = std::string(argv[1]);
  const std::string out_file = std::string(argv[2]);

  std::ifstream input(in_file);
  std::ofstream output(out_file);

  if (!input) {
    std::cerr << "Error opening input file" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (!output) {
    std::cerr << "Error opening output file" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string linea;

  while(std::getline(input, linea)) {
    long unsigned int iteration_counter {0};
    int space_counter {0};
    for (char chr : linea) {
      if (chr == ' ') {
        ++space_counter;
      }
    }
    
    //Checks if there is more than one or no space
    if (space_counter != 1) {
      std::cerr << "Incorrect input format in line " << iteration_counter + 1 << ": There is no or more than one space." << std::endl;
      ++iteration_counter;
      continue;
    }
    //Checks for inexistant space
    long unsigned int position = linea.find(' ');

    if (position >= linea.size()) {
      std::cerr << "Fatal error "<< space_counter + 1 <<": Alphabet cannot be empty. Try 'cya-P02-strings --help' for further information" << std::endl;
      ++iteration_counter;
      continue;;
    }

    //Substraction of the chain and the alphabet
    std::string cadena = linea.substr(0, position);
    std::string alfabeto = linea.substr(position + 1);

    //Checks if alphabet is valid for the given chain, and/or viceversa
    bool correct = true;
    for (long unsigned int i {0}; i < cadena.size(); ++i) {
      bool found = false;
      for (long unsigned int j {0}; j < alfabeto.size(); ++j) {
        if (cadena[i] == alfabeto[j] || cadena[i] == '&') {
          found = true;
          break;
        }
      }
      if (!found) {
        correct = false;
        std::cerr << "Incorrect input format in line "<< space_counter + 1 <<": Chain isn't part of given alphabet" << std::endl;
        break;
      }
    }

    if (!correct) {
      ++iteration_counter;
      continue;
    }

    Chain final_chain;
    for (const char& character : cadena) {
      final_chain.AddBack(Symbol(character));
    }

    Alphabet final_alphabet;
    for (const char& character : alfabeto) {
      final_alphabet.AddSymbol(Symbol(character));
    }

    switch(option) {
      case 1:
        if (!final_alphabet.Empty()) {
          output << final_alphabet << "\n";
        } else {
          std::cerr << "Fatal error "<< space_counter + 1 <<": Alphabet cannot be empty. Try 'cya-P02-strings --help' for further information" << std::endl;
        }
        break;
      case 2:
        output << final_chain.ChainSize() << "\n";
        break;
      case 3:
        output << final_chain.Inverse() << "\n";
        break;
      case 4:
        output << final_chain.Prefixes() << "\n";
        break;
      case 5:
        output << final_chain.Sufixes() << "\n";
        break;
      default:
        std::cerr <<"Parameters not valid. Try 'cya-P02-strings --help' for further information" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (input.fail() && !input.eof()) {
      std::cerr << "Error reading from input file in line " << iteration_counter + 1 << ". Aborting..." << std::endl;
      exit(EXIT_FAILURE);
    }

    if (output.fail()) {
      std::cerr << "Error writing to output file in line " << iteration_counter + 1 << ". Aborting..." << std::endl;
      exit(EXIT_FAILURE);
    }
  ++iteration_counter;
  }

  input.close();
  output.close();
  return 0;
}
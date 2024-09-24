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

** Archivo help_functions.h: Archivo de cabecera con las funciones de ayuda
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**      21/09/2024 - Adición de las funciones de lectura y escritura
**      23/09/2024 - Mejora del control de errores
**      24/09/2024 - Manejo de casos en donde el alfabeto no se corresponde a la cadena
**/

#include <iostream>
#include <fstream>

#include "general_functions.h"
#include "language.h"

/**
 * @brief Prints how to use the client program
 */
void Usage() {
  std::cout << "How to use: ./cya-P02-strings filein.txt fileout.txt opcode\n"
            << "Try 'cya-P02-strings --help' for further information\n";
}

/**
 * @brief Brings help if "./cya-P02-strings --help" is typed
 */
void Help () {
    std::cout << "./cya-P02-strings -- Symbols, strings, alphabets and formal languages\n"
              << "How to use:          ./cya-P02-strings filein.txt fileout.txt opcode\n"
              << "\n"
              << "filein.txt:      Input file: Format must be <chain> <alphabet> both without spaces within them.\n"
              <<                                  "- <alphabet> cannot have duplicated symbols\n"
              << "fileout.txt:     Output file\n"
              << "opcode:          Type the wanted opcode (int-type): \n"
              << "                 1. Alphabet: Asociated alphabet to the input chains\n"
              << "                 2. Size: Size of the input chains\n"
              << "                 3. Inverse:  Inverse of the input chains\n"
              << "                 4. Prefixes: Prefix languages by input chains\n"
              << "                 5. Sufixes:  Sufix languages by input chains\n"
              << "\n";
}

/**
 * @brief Reads an input file and saves the chains and vector in vectors of those objects
 * @param string 
 * @param vector<chain>
 * @param vector<alphabet>
 */
void Read (const std::string& in_file, std::vector<chain>& in_chains, std::vector<alphabet>& in_alphabets) {
  std::ifstream input(in_file);
  if (!input) {
    std::cerr << "Error opening input file" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string linea;

  while(std::getline(input, linea)) {
    int counter {0};
    for (char chr : linea) {
      if (chr == ' ') {
        ++counter;
      }
    }

    //Checks for inexistant space
    long unsigned int position = linea.find(' ');

    if (position >= linea.size()) {
      std::cerr << "Fatal error: Alphabet cannot be empty. Try 'cya-P02-strings --help' for further information" << std::endl;
      exit(EXIT_FAILURE);
    }
    
    //Checks for more than one space in same line
    if (counter != 1) {
      std::cerr << "Incorrect input format: More than one space in same line. Try 'cya-P02-strings --help' for further information" << std::endl;
      exit(EXIT_FAILURE);
    }
    //Substraction of the chain and the alphabet
    std::string cadena = linea.substr(0, position);
    std::string alfabeto = linea.substr(position + 1);

    //Checks for duplicate characters in alphabet
    for (long unsigned int i {0}; i < alfabeto.size(); ++i) {
      for (long unsigned int j {i + 1}; j < alfabeto.size(); ++j) {
        if (alfabeto[i] == alfabeto[j]) {
          std::cerr << "Incorrect input format: Duplicate symbols in alphabet" << std::endl;
          exit(EXIT_FAILURE);
        }
      }
    }

    bool correct = false;
    for (long unsigned int i {0}; i < cadena.size(); ++i) {
      for (long unsigned int j {0}; j < alfabeto.size(); ++j) {
        if (cadena[i] == alfabeto[j] || cadena[i] == '&') {
          correct = true;
        }
      }
    }

    if (!correct) {
      std::cerr << "Incorrect input format: Chain isn't part of given alphabet" << std::endl;
      exit(EXIT_FAILURE);
    }

    chain final_chain;
    for (const char& character : cadena) {
      final_chain.AddBack(symbol(character));
    }
    in_chains.push_back(final_chain);

    alphabet final_alphabet;
    for (const char& character : alfabeto) {
      final_alphabet.AddSymbol(symbol(character));
    }
    in_alphabets.push_back(final_alphabet);
  }
}

/**
 * @brief Writes an alphabet in an output file
 * @param string 
 * @param vector<alphabet>
 */
void Write(const std::string& out_file, const std::vector<alphabet>& to_write) {
  std::ofstream out(out_file);

  if (!out) {
    std::cerr << "Error opening the file: " << out_file << std::endl;
    exit(EXIT_FAILURE);
  }

  for (long unsigned int i {0}; i < to_write.size(); ++i) {
    if (to_write[i].Empty()) {
      std::cerr << "Fatal error in line " << i+1 << " : Alphabet cannot be empty" << std::endl;
    } else {
      out << to_write[i] << "\n"; 
    }
  }

  if (out.fail()) {
    std::cerr << "Error writing in the file." << std::endl;
    exit(EXIT_FAILURE);
  }

  out.close(); 
}

/**
 * @brief Writes the size of a chain in an output file
 * @param string 
 * @param vector<chain>
 */
void WriteChainSize(const std::string& out_file, const std::vector<chain>& to_write) {
  std::ofstream out(out_file);

  if (!out) {
    std::cerr << "Error opening the file: " << out_file << std::endl;
    exit(EXIT_FAILURE);
  }

  for (long unsigned int i {0}; i < to_write.size(); ++i) {
    out << to_write[i].ChainSize() << "\n"; 
  }

  if (out.fail()) {
    std::cerr << "Error writing in the file." << std::endl;
    exit(EXIT_FAILURE);
  }

  out.close(); 
}

/**
 * @brief Writes the inverse of a chain in an output file
 * @param string 
 * @param vector<chain>
 */
void WriteInverse(const std::string& out_file, const std::vector<chain>& to_write) {
  std::ofstream out(out_file);

  if (!out) {
    std::cerr << "Error opening the file: " << out_file << std::endl;
    exit(EXIT_FAILURE);
  }

  for (long unsigned int i {0}; i < to_write.size(); ++i) {
    out << to_write[i].Inverse() << "\n"; 
  }

  if (out.fail()) {
    std::cerr << "Error writing in the file." << std::endl;
    exit(EXIT_FAILURE);
  }

  out.close();
}

/**
 * @brief Writes the prefix language created by a chain in an output file
 * @param string 
 * @param vector<chain>
 */
void WritePrefixes(const std::string& out_file, const std::vector<chain>& to_write) {
  std::ofstream out(out_file);
  language prefix;

  if (!out) {
    std::cerr << "Error opening the file: " << out_file << std::endl;
    exit(EXIT_FAILURE);
  }

  for (long unsigned int i {0}; i < to_write.size(); ++i) {
    out << prefix.Prefixes(to_write[i]) << "\n"; 
  }

  if (out.fail()) {
    std::cerr << "Error writing in the file." << std::endl;
    exit(EXIT_FAILURE);
  }

  out.close();
}

/**
 * @brief Writes the sufix language created by a chain in an output file
 * @param string 
 * @param vector<chain>
 */
void WriteSufixes(const std::string& out_file, const std::vector<chain>& to_write) {
  std::ofstream out(out_file);
  language sufix;

  if (!out) {
    std::cerr << "Error opening the file: " << out_file << std::endl;
    exit(EXIT_FAILURE);
  }

  for (long unsigned int i {0}; i < to_write.size(); ++i) {
    out << sufix.Sufixes(to_write[i]) << "\n"; 
  }

  if (out.fail()) {
    std::cerr << "Error writing in the file." << std::endl;
    exit(EXIT_FAILURE);
  }

  out.close();
}
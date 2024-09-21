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
**/

#include <iostream>
#include <fstream>

#include "general_functions.h"
#include "language.h"

/**
 * @brief Prints how to use the client program
 */
void Usage() {
  std::cout << "Modo de empleo: ./cya-P02-strings filein.txt fileout.txt opcode\n"
            << "Pruebe 'cya-P02-strings --help' para más información\n";
}

/**
 * @brief Brings help if "./cya-P02-strings --help" is typed
 */
void Help () {
    std::cout << "./cya-P02-strings -- Cifrado de ficheros\n"
              << "Modo de uso:     ./cya-P02-strings filein.txt fileout.txt opcode\n"
              << "\n"
              << "filein.txt:      Fichero de entrada\n"
              << "fileout.txt:     Fichero de salida\n"
              << "metodo:          Indica la operacion deseada: \n"
              << "                 1. Alfabeto: Alfabeto asociado a las cadenas de entrada\n"
              << "                 2. Longitud: Longitud de la cadena entrada\n"
              << "                 3. Inversa:  Inversa de la cadena de entrada\n"
              << "                 4. Prefijos: Conjunto de cadenas que son prefijos de la cadena de entrada\n"
              << "                 5. Sufijos:  Conjunto de cadenas que son sufijos de la cadena de entrada\n"
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
    std::cerr << "Error al abrir el archivo de entrada" << std::endl;
    return;
  }

  std::string linea;
  while(std::getline(input, linea)) {
    long unsigned int position = linea.find(' ');

    if (position >= linea.size() || position == 0) {
      std::cerr << "Incorrect input format" << std::endl;
      exit(EXIT_FAILURE);
    }

    std::string cadena = linea.substr(0, position);
    std::string alfabeto = linea.substr(position + 1);

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



void Write(const std::string& out_file, const std::vector<language>& to_write) {
  std::ofstream out(out_file);

  if (!out) {
    std::cerr << "Error opening the file: " << out_file << std::endl;
    exit(EXIT_FAILURE);
  }

  for (long unsigned int i {0}; i < to_write.size(); ++i) {
    out << to_write[i] << "\n"; 
  }

  if (out.fail()) {
    std::cerr << "Error writing in the file." << std::endl;
    exit(EXIT_FAILURE);
  }

  out.close(); 
}

void Write(const std::string& out_file, const std::vector<alphabet>& to_write) {
  std::ofstream out(out_file);

  if (!out) {
    std::cerr << "Error opening the file: " << out_file << std::endl;
    exit(EXIT_FAILURE);
  }

  for (long unsigned int i {0}; i < to_write.size(); ++i) {
    out << to_write[i] << "\n"; 
  }

  if (out.fail()) {
    std::cerr << "Error writing in the file." << std::endl;
    exit(EXIT_FAILURE);
  }

  out.close(); 
}

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
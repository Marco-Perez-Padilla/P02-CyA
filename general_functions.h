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

#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#include <string>
#include <vector>

#include "alphabet.h"
#include "chain.h"
#include "language.h"

void Usage();
void Help ();
void Read (const std::string&, std::vector<chain>&, std::vector<alphabet>&);
void Write(const std::string& out_file, const std::vector<language>& to_write);
void Write(const std::string& out_file, const std::vector<alphabet>& to_write);
void WriteChainSize(const std::string& out_file, const std::vector<chain>& to_write);
void WriteInverse(const std::string& out_file, const std::vector<chain>& to_write);
void WritePrefixes(const std::string& out_file, const std::vector<chain>& to_write);
void WriteSufixes(const std::string& out_file, const std::vector<chain>& to_write);

#endif
#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Ficheros{
	//DEFINIENDO LAS VARIABLES NECESARIAS
public:
	string nombre, auxnombre, semestre, edad;
	int clave = 0, auxclave = 0;
	char grupo[10];
	char opca;
	bool encontrado = false;
	Ficheros();
	void altas();
	void bajas();
	void consultas();
	void buscar();
	void modificar();
};
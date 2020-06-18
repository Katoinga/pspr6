#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Ficha.h"
using namespace std;

void ficha::MostrarNombres(ficha* datos, int numFichas, char agenda[80], FILE* fichero)
{
	fichero = fopen(agenda, "rb"); //abrimos el fichero en modo lectura
	if (fichero == NULL) { //si el fichero no existe...
		cout << ("No hay datos.\n");
	}
	else { //si el fichero existe...
		datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas); //Reservamos el espacio para las fichas existentes
		if (datos == NULL) { //Si no hay espacio suficiente, salimos del programa
			cout << ("No hay suficiente espacio en memoria\n");
			exit(1);
		}
		while (!feof(fichero)) { //Leemos todos los datos hasta el final del fichero
			for (int i = 0; i < numFichas; i++)//y los cargamos en la memoria que hemos reservado
				fread(datos + i, sizeof(struct ficha), 1, fichero);
		}
		fclose(fichero); //Cerramos el fichero
	}

	//sacamos los datos por pantalla
	cout << ("Los nombres existentes son:\n");
	for (int i = 0; i < numFichas; i++) {
		cout << "Nombre:" << (datos + i)->nombre << endl;
	}
}
void ficha::MostrarTodo(ficha* datos, int numFichas, char agenda[80], FILE* fichero)
{
	fichero = fopen(agenda, "rb"); //abrimos el fichero en modo lectura
	if (fichero == NULL) { //si el fichero no existe...
		cout << ("No hay datos.\n");
	}
	else { //si el fichero existe...
		datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas); //Reservamos el espacio para las fichas existentes
		if (datos == NULL) { //Si no hay espacio suficiente, salimos del programa
			cout << ("No hay suficiente espacio en memoria\n");
			exit(1);
		}
		while (!feof(fichero)) { //Leemos todos los datos hasta el final del fichero
			for (int i = 0; i < numFichas; i++)// y los cargamos en la memoria que hemos reservado
				fread(datos + i, sizeof(struct ficha), 1, fichero);
		}
		fclose(fichero); //Cerramos el fichero
	}
	cout << ("Los datos existentes son:\n");
	for (int i = 0; i < numFichas; i++) {
		cout << "\n================================================";
		cout << "\nDatos:\nNombre:" << (datos + i)->nombre << "\nDireccion:" << (datos + i)->direccion << "\nTlf Movil:" << (datos + i)->movil <<
			"\nEmail:" << (datos + i)->email << "\nCumpleanyos:" << (datos + i)->cumpledia
			<< "/ " << (datos + i)->cumplemes << "/ " << (datos + i)->cumpleyear;
		cout << "\n================================================\n";
	}
}

void ficha::Buscar(ficha* datos, int numFichas, char agenda[80], FILE* fichero,char textotemporal[20])
{
	fichero = fopen(agenda, "rb"); //abrimos el fichero en modo lectura
	if (fichero == NULL) { //si el fichero no existe...
		cout << ("No hay datos.\n");
	}
	else { //si el fichero existe...
		datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas); //Reservamos el espacio para las fichas existentes
		if (datos == NULL) { //Si no hay espacio suficiente, salimos del programa
			cout << ("No hay suficiente espacio en memoria\n");
			exit(1);
		}
		while (!feof(fichero)) { //Leemos todos los datos hasta el final del fichero
			for (int i = 0; i < numFichas; i++) // y los cargamos en la memoria que hemos reservado
				fread(datos + i, sizeof(struct ficha), 1, fichero);
		}
		fclose(fichero); //Cerramos el fichero
	}

	//sacamos los datos por pantalla
	cout << ("Escribe el nombre a buscar: ");
	cin.getline(textotemporal, 10);
	cin.getline(textotemporal, 10);
	int coincide = 0; //inicializamos la variable que nos dirá si ha encontrado coincidencias o no
	for (int i = 0; i < numFichas; i++) {
		if (strcmp((datos + i)->nombre, textotemporal) == 0) {//hacemos la comparacion, si existe el nombre escribimos los datos
			cout << "\n================================================\n";
			cout << "Datos:\nNombre:" << (datos + i)->nombre << "\nDireccion:" << (datos + i)->direccion << "\nTlf Movil:" << (datos + i)->movil <<
				"\nEmail:" << (datos + i)->email << "\nCumpleanyos:" << (datos + i)->cumpledia << "/ " << (datos + i)->cumplemes << "/ " << (datos + i)->cumpleyear;
			coincide++; //y la variable sindatos cambia de valor
			cout << "\n================================================\n";
		}
	}
	//Si la variable sindatos sigue siendo igual a 0 es que no ha encontrado el nombre, cosa que indicamos
	if (coincide == 0) cout << "No se disponen de datos para\n"<< textotemporal;

}

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Ficheros.h"
using namespace std;

Ficheros::Ficheros() {
	encontrado = false;
}

void Ficheros:: altas()
{
	///Variables de la biblioteca fstream para el manejo de archivos
	ofstream escritura;
	ifstream consulta;

	do {
		escritura.open("alumnos.txt", ios::out | ios::app);//crea y escribe, si ya tiene texto une al final del archivo
		consulta.open("alumnos.txt", ios::in);//solamente consulta o lee usando la variable sobre el archivo físico alumnos.txt
		// si estan 'abierto' los dos
		if (escritura.is_open() && consulta.is_open()) {
			// flag que sirve para saber si esta repetido
			bool repetido = false;
			//pide la clave del alumno
			cout << "\n";
			cout << "\tIngresa la clave del alumno:    ";
			cin >> auxclave;

			///A continuación se aplica el tipo de lectura de archivos secuencial
			consulta >> clave;
			while (!consulta.eof()) {
				// anade todo eso a la consulta
				consulta >> nombre >> semestre >> grupo >> edad;
				if (auxclave == clave) {
					cout << "\t\tYa existe la clave del alumno...\n";
					repetido = true;
					break;
				}
				consulta >> clave;
			}
			//si no es repetido
			if (repetido == false) {
				cout << "\tIngresa el nombre del alumno:   ";
				cin >> nombre;
				cout << "\tIngresa el semestre del alumno: ";
				cin >> semestre;
				cout << "\tIngresa el grupo del alumno:    ";
				cin >> grupo;
				cout << "\tIngresa la edad del alumno:     ";
				cin >> edad;
				//ESCRIBIENDO LOS DATOS CAPTURADOS POR EL USUARIO EN EL ARCHIVO
				escritura << auxclave << " " << nombre << " " << semestre << " " << grupo << " " << edad << endl;
				cout << "\n\tRegistro agregado...\n";
			}
			//seleccionar opcion
			cout << "\n\tDeseas ingresar otro alumno? (S/N): ";
			cin >> opca;

		}
		else {
			cout << "El archivo no se pudo abrir \n";
		}
		//cierra toda la escritura
		escritura.close();
		consulta.close();
		//reconoce S o s como si/no
	} while (opca == 'S' or opca == 's');

}
//metodo para borrar alumnos
void Ficheros::bajas()
{
	ofstream aux;
	ifstream lectura;
	//definiendo 
	encontrado = false;

	aux.open("auxiliar.txt", ios::out);
	lectura.open("alumnos.txt", ios::in);

	if (aux.is_open() && lectura.is_open()) {
		// pide la clave del alumno para eliminar
		cout << "\n";
		cout << "\tIngresa la clave del alumno que deseas eliminar: ";
		cin >> auxclave;

		///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
		///hasta llegar al final del archivo gracias a la función .eof()
		lectura >> clave;
		while (!lectura.eof()) {
			//anade todo a la lectura
			lectura >> nombre >> semestre >> grupo >> edad;
			// encontraba al alumno con esa clave
			if (auxclave == clave) {
				encontrado = true;
				cout << "\n";
				cout << "\tClave:    " << clave << endl;
				cout << "\tNombre:   " << nombre << endl;
				cout << "\tSemestre: " << semestre << endl;
				cout << "\tGrupo:    " << grupo << endl;
				cout << "\tEdad:     " << edad << endl;
				cout << "\t________________________________\n\n";
				cout << "\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
				cin >> opca;
				//compruba si realmente quiere eliminar
				if (opca == 'S' or opca == 's') {
					cout << "\n\n\t\t\tRegistro eliminado...\n\n\t\t\a";
				}

				else {
					aux << clave << " " << nombre << " " << semestre << " " << grupo << " " << edad << endl;
				}

			}
			else {
				aux << clave << " " << nombre << " " << semestre << " " << grupo << " " << edad << endl;
			}
			lectura >> clave;
		}
	}
	else {
		cout << "\n\tEl archivo no se pudo abrir \n";
	}
	//no se encuetra una clave
	if (encontrado == false) {
		cout << "\n\tNo se encontro ningun registro con la clave: " << auxclave << "\n\n\t\t\t";
	}
	// cierra los archivos 
	aux.close();
	lectura.close();
	remove("alumnos.txt");
	rename("auxiliar.txt", "alumnos.txt");
}

//metodo para consultar los alumnos
void Ficheros::consultas()
{
	//Lectura de archivos
	ifstream lectura;
	lectura.open("alumnos.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
	if (lectura.is_open()) {
		//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
		lectura >> clave;
		while (!lectura.eof()) {
			lectura >> nombre >> semestre >> grupo >> edad;
			cout << "\n";
			cout << "\tClave:    " << clave << endl;
			cout << "\tNombre:   " << nombre << endl;
			cout << "\tSemestre: " << semestre << endl;
			cout << "\tGrupo:    " << grupo << endl;
			cout << "\tEdad:     " << edad << endl;
			lectura >> clave;
			cout << "\t________________________________\n";
		}

	}
	// error que no se pudo abrir ese archivo
	else {
		cout << "El archivo no se pudo abrir \n";
	}
	lectura.close();
}

//metodo que busca un alumno
void Ficheros::buscar()
{

	ifstream lectura;
	lectura.open("alumnos.txt", ios::out | ios::in);
	// boolean para encontrar algo
	encontrado = false;

	if (lectura.is_open()) {
		cout << "\n\tIngresa la clave del alumno que deseas buscar: ";
		cin >> auxclave;

		lectura >> clave;
		while (!lectura.eof()) {
			lectura >> nombre >> semestre >> grupo >> edad;
			//comparar cada registro para ver si es encontrado

			if (auxclave == clave) {
				cout << "\n";
				cout << "\tClave:    " << clave << endl;
				cout << "\tNombre:   " << nombre << endl;
				cout << "\tSemestre: " << semestre << endl;
				cout << "\tGrupo:    " << grupo << endl;
				cout << "\tEdad:     " << edad << endl;
				cout << "\t________________________________\n";
				encontrado = true;
				break;
			}//fin del if mostrar encontrado

			//lectura adelantada
			lectura >> clave;
		}//fin del while
		//no encontro 
		if (encontrado == false) {
			cout << "\n\n\tNo hay registros con la clave: " << auxclave << "\n\n\t\t\t";
		}
	}
	// no se pudo abrir el archivo
	else {
		cout << "\n\tAun no se pudo abrir el archivo...";
	}

	lectura.close();
}
//metodo para modificar un alumno
void Ficheros::modificar()
{
	ofstream aux;
	ifstream lectura;

	encontrado = false;
	//boolean para saber si encontro el indice
	aux.open("auxiliar.txt", ios::out);
	lectura.open("alumnos.txt", ios::in);
	// si abrio correcatemnte los archivos
	if (aux.is_open() && lectura.is_open()) {
		//pide la clave a buscar
		cout << "\n";
		cout << "\tIngresa la clave del alumno que deseas modificar: ";
		cin >> auxclave;
		///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
		///hasta llegar al final del archivo gracias a la función .eof()
		lectura >> clave;
		while (!lectura.eof()) {
			//busca si hay un registro que coincida
			lectura >> nombre >> semestre >> grupo >> edad;
			if (auxclave == clave) {
				encontrado = true;
				cout << "\n";
				cout << "\tClave:    " << clave << endl;
				cout << "\tNombre:   " << nombre << endl;
				cout << "\tSemestre: " << semestre << endl;
				cout << "\tGrupo:    " << grupo << endl;
				cout << "\tEdad:     " << edad << endl;
				cout << "\t________________________________\n\n";
				//pide los nuevos datos
				cout << "\tIngresa el nuevo nombre del alumno con la clave: " << auxclave << "\n\n\t---> ";
				cin >> auxnombre;
				//lo guarda como auxiliar
				aux << clave << " " << auxnombre << " " << semestre << " " << grupo << " " << edad << endl;
				cout << "\n\n\t\t\tRegistro modificado...\n\t\t\a";
			}
			else {
				aux << clave << " " << nombre << " " << semestre << " " << grupo << " " << edad << endl;
			}
			lectura >> clave;
		}
	}
	// no se pudo abrir el archivo
	else {
		cout << "\n\tEl archivo no se pudo abrir \n";
	}
	// no se encontro algun registro con la clave deseada
	if (encontrado == false) {
		cout << "\n\tNo se encontro ningun registro con la clave: " << auxclave << "\n\n\t\t\t";
	}

	aux.close();
	lectura.close();
	remove("alumnos.txt");
	rename("auxiliar.txt", "alumnos.txt");
}

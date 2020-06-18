#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Ficha.h"
using namespace std;

int main()
{
	ficha met;
	// cargar en la memoria los datos del fichero
	ficha* datos;
	// anadir nuevas fichas
	ficha* nueva;
	// se usa FILE ya que mediante switch no permite incializar
	// dentro de cada case o switch
	FILE* fichero;
	char agenda[80] = "agenda.dat";
	int numFichas = 0;
	int tamano = 0;
	datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas);
	char textotemporal[20];
	int menu;
	int i;
	// Calculamos cuántos datos hay actualmente en el fichero
	fichero = fopen(agenda, "rb"); //abrimos el fichero en modo lectura
	if (fichero == NULL) { //si el fichero no existe...
		cout << ("No existe el fichero.\n");
	}
	else { //si el fichero existe...
		fseek(fichero, 0, 2); //saltamos al final del fichero
		tamano = ftell(fichero); //tamaño total del fichero
		numFichas = (tamano / sizeof(struct ficha));;
		//El numero de fichas existentes es iguala la longitud total del fichero entre el tamaño del struct ficha 
		fclose(fichero); //cerramos el fichero
		cout << "El numero de fichas existentes es \n" << numFichas; //Indicamos el numero de fichas que existen actualmente

	}
	//cargamos los datos existentes en el fichero
	fichero = fopen(agenda, "rb"); //abrimos el fichero en modo lectura
	if (fichero == NULL) { //si el fichero no existe...
		cout << ("Comenzamos un fichero nuevo.\n");
	}
	else { //si el fichero existe...
		datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas); //Reservamos el espacio para las fichas existentes
		if (datos == NULL) { //Si no hay espacio suficiente, salimos del programa
			cout << ("No hay suficiente espacio en memoria\n");
			exit(1);
		}
		while (!feof(fichero)) { //Leemos todos los datos hasta el final del fichero
			for (i = 0; i < numFichas; i++)// y los cargamos en la memoria que hemos reservado
				fread(datos + i, sizeof(struct ficha), 1, fichero);
		}
		fclose(fichero); //Cerramos el fichero
	}

	//Iniciamos el programa propiamente dicho
	do {
		cout << ("\nElige una opcion:\n");
		cout << ("1. Anadir ficha nueva\n");
		cout << ("2. Listado de nombres del fichero\n");
		cout << ("3. Listado total del fichero\n");
		cout << ("4. Mostrar los datos de una persona\n");
		cout << ("0. Salir\n");
		cin >> menu;

		switch (menu) {
		case 1:
			if (numFichas < 1000) { //si hay menos de 1000 fichas...
				nueva = (struct ficha*) malloc(sizeof(struct ficha)); //reservamos memoria para una ficha
				cin.getline(nueva->nombre, 50);
				if (nueva == NULL) { //Si no hay espacio suficiente, salimos del programa
					cout << ("No hay suficiente espacio en memoria\n");
					exit(1);
				}
				cout << ("Introduce el nombre: ");//pedimos datos...
				cin.getline(nueva->nombre, 50);//...y los vamos almacenando en su posición
				cout << ("Introduce la direccion: ");
				cin.getline(nueva->direccion, 50);
				cout << ("Introduce el telefono: ");
				cin.getline(nueva->movil, 9);
				cout << ("Introduce el email: ");
				cin.getline(nueva->email, 50);
				cout << ("Introduce el dia de nacimiento: ");
				cin >> nueva->cumpledia;
				cout << ("Introduce el mes de nacimiento: ");
				cin >> nueva->cumplemes;
				cout << ("Introduce el anyo de nacimiento: ");
				cin >> nueva->cumpleyear;
				numFichas++;

				fichero = fopen(agenda, "ab"); //abrimos el fichero
				cout << ("fichero abierto\n");
				fwrite(nueva, sizeof(struct ficha), 1, fichero); //escribimos los datos de la ficha
				cout << ("datos escritos\n");
				fclose(fichero); //cerramos el fichero
				cout << ("fichero cerrado\n");
				free(nueva); //liberamos memoria
				cout << ("memoria liberada\n");
			}
			else cout << ("No hay sitio para mas fichas (maximo 1000)"); //si hay mas de 1000 fichas, avisamos
			break;
		case 2:
			//Refrescamos los datos del fichero
			free(datos); //primero liberamos de la memoria los datos que había hasta ahora
			datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas);
			met.MostrarNombres(datos, numFichas, agenda, fichero);
			break;

		case 3:
			//Refrescamos los datos del fichero
			free(datos); //primero liberamos de la memoria los datos que había hasta ahora
			datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas);
			met.MostrarTodo(datos, numFichas, agenda, fichero);
			break;

		case 4:
			//Refrescamos los datos del fichero
			free(datos); //primero liberamos de la memoria los datos que había hasta ahora
			met.Buscar(datos, numFichas,agenda,fichero, textotemporal);
			break;
		case 0:
			cout << ("Terminando...");
			free(datos);
			break;

		default:
			cout << ("Opcion no valida");
			break;

		}
	} while (menu != 0);



	return 0;
}
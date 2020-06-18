/*
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	struct ficha {
		char nombre[50];
		char direccion[50];
		char movil[9];
		char email[50];
		short int cumpledia;
		short int cumplemes;
		int cumpleyear;
	};
	// cargar en la memoria los datos del fichero
	ficha* datos;
	// anadir nuevas fichas
	ficha* nueva;
	char agenda[80] = "n20.dat";
	int numFichas = 0;
	int tamano = 0;
	datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas);
	char textotemporal[10];
	int menu;
	int i;
	int sindatos = 0;
	ifstream fichero;
	// Calculamos cuántos datos hay actualmente en el fichero
	fichero.open(agenda); //abrimos el fichero en modo lectura
	if (!fichero ) { //si el fichero no existe...
		cout << ("No existe el fichero.\n");
	}
	else { //si el fichero existe...
		fichero.seekg(0,2);
		tamano = fichero.tellg(); //tamaño total del fichero
		numFichas = (tamano / sizeof(struct ficha));;
		//El numero de fichas existentes es iguala la longitud total del fichero entre el tamaño del struct ficha
		fichero.close(); //cerramos el fichero
		cout << "El numero de fichas existentes es \n" << numFichas; //Indicamos el numero de fichas que existen actualmente

	}
	//cargamos los datos existentes en el fichero
	fichero.open(agenda); //abrimos el fichero en modo lectura
	if (!fichero) { //si el fichero no existe...
		cout << ("Comenzamos un fichero nuevo.\n");
	}
	else { //si el fichero existe...
		datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas); //Reservamos el espacio para las fichas existentes
		if (datos == NULL) { //Si no hay espacio suficiente, salimos del programa
			cout << ("No hay suficiente espacio en memoria\n");
			exit(1);
		}
		while (!fichero.eof()) { //Leemos todos los datos hasta el final del fichero
			for (i = 0; i < numFichas; i++)// y los cargamos en la memoria que hemos reservado
				fichero.read((char*)datos+i, sizeof(struct ficha));
		}
		fichero.close(); //Cerramos el fichero
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
				cout << ("Introduce el año de nacimiento: ");
				cin >> nueva->cumpleyear;
				numFichas++;
				ofstream ficherox(agenda, std::ios::binary);
				cout << ("fichero abierto\n");
				ficherox.write((char*)nueva, sizeof(struct ficha)); //escribimos los datos de la ficha
				cout << ("datos escritos\n");
				ficherox.close(); //cerramos el fichero
				cout << ("fichero cerrado\n");
				free(nueva); //liberamos memoria
				cout << ("memoria liberada\n");

			}
			else cout << ("No hay sitio para mas fichas (maximo 1000)"); //si hay mas de 1000 fichas, avisamos
			break;

		case 2:
			//Refrescamos los datos del fichero
			free(datos); //primero liberamos de la memoria los datos que había hasta ahora
			fichero.open(agenda); //abrimos el fichero en modo lectura
			if (!fichero) { //si el fichero no existe...
				cout << ("No hay datos.\n");
			}
			else { //si el fichero existe...
				datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas); //Reservamos el espacio para las fichas existentes
				if (datos == NULL) { //Si no hay espacio suficiente, salimos del programa
					cout << ("No hay suficiente espacio en memoria\n");
					exit(1);
				}
				while (!fichero.eof()) { //Leemos todos los datos hasta el final del fichero
					for (i = 0; i < numFichas; i++)//y los cargamos en la memoria que hemos reservado
						fichero.read((char*)datos+i, sizeof(struct ficha));
				}
				fichero.close(); //Cerramos el fichero
			}

			//sacamos los datos por pantalla
			cout << ("Los nombres existentes son:\n");
			for (i = 0; i < numFichas; i++) {
				cout << "Nombre:" << (datos + i)->nombre << endl;
			}

			break;

		case 3:
			//Refrescamos los datos del fichero
			free(datos); //primero liberamos de la memoria los datos que había hasta ahora
			fichero.open(agenda); //abrimos el fichero en modo lectura
			if (!fichero ) { //si el fichero no existe...
				cout << ("No hay datos.\n");
			}
			else { //si el fichero existe...
				datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas); //Reservamos el espacio para las fichas existentes
				if (datos == NULL) { //Si no hay espacio suficiente, salimos del programa
					cout << ("No hay suficiente espacio en memoria\n");
					exit(1);
				}
				while (!fichero.eof()) { //Leemos todos los datos hasta el final del fichero
					for (i = 0; i < numFichas; i++)// y los cargamos en la memoria que hemos reservado
						fichero.read((char*)datos + i, sizeof(struct ficha));
				}
				fichero.close(); //Cerramos el fichero
			}

			//sacamos los datos por pantalla
			cout << ("Los datos existentes son:\n");
			for (i = 0; i < numFichas; i++) {
				cout << "\n================================================";
				cout << "\nDatos:\nNombre:" << (datos + i)->nombre << "\nDireccion:" << (datos + i)->direccion << "\nTlf Movil:" << (datos + i)->movil <<
					"\nEmail:" << (datos + i)->email << "\nCumpleanyos:" << (datos + i)->cumpledia
					<< "/ " << (datos + i)->cumplemes << "/ " << (datos + i)->cumpleyear;
				cout << "\n================================================\n";
			}

			break;

		case 4:
			//Refrescamos los datos del fichero
			free(datos); //primero liberamos de la memoria los datos que había hasta ahora
			fichero.open(agenda); //abrimos el fichero en modo lectura
			if (!fichero) { //si el fichero no existe...
				cout << ("No hay datos.\n");
			}
			else { //si el fichero existe...
				datos = (struct ficha*) malloc(sizeof(struct ficha) * numFichas); //Reservamos el espacio para las fichas existentes
				if (datos == NULL) { //Si no hay espacio suficiente, salimos del programa
					cout << ("No hay suficiente espacio en memoria\n");
					exit(1);
				}
				while (!fichero.eof()) { //Leemos todos los datos hasta el final del fichero
					for (i = 0; i < numFichas; i++) // y los cargamos en la memoria que hemos reservado
						fichero.read((char*)datos + i, sizeof(struct ficha));
				}
				fichero.close(); //Cerramos el fichero
			}

			//sacamos los datos por pantalla
			cout << ("Escribe el nombre a buscar: ");
			cin.getline(textotemporal, 10);
			cin.getline(textotemporal, 10);
			sindatos = 0; //inicializamos la variable que nos dirá si ha encontrado coincidencias o no
			for (i = 0; i < numFichas; i++) {
				if (strcmp((datos + i)->nombre, textotemporal) == 0) {//hacemos la comparacion, si existe el nombre escribimos los datos
					cout << "\n================================================\n";
					cout << "Datos:\nNombre:" << (datos + i)->nombre << "\nDireccion:" << (datos + i)->direccion << "\nTlf Movil:" << (datos + i)->movil <<
						"\nEmail:" << (datos + i)->email << "\nCumpleanyos:" << (datos + i)->cumpledia << "/ " << (datos + i)->cumplemes << "/ " << (datos + i)->cumpleyear;
					sindatos++; //y la variable sindatos cambia de valor
					cout << "\n================================================\n";
				}
			}
			//Si la variable sindatos sigue siendo igual a 0 es que no ha encontrado el nombre, cosa que indicamos
			if (sindatos == 0) cout << "No se disponen de datos para\n"<<textotemporal;

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


*/
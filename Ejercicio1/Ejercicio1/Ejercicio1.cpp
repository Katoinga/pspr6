//comentando todo
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Ficheros.h"
using namespace std;

int main()
{
	Ficheros metodos;
	//color elegido
	system("color f0");
	int opc;

	do {
		system("cls");
		cout << "\n\tManejo de archivos en c++\n\n";
		cout << "\n\t1.-Altas";
		cout << "\n\t2.-Bajas";
		cout << "\n\t3.-Consultas";
		cout << "\n\t4.-Buscar un registro";
		cout << "\n\t5.-Modificaciones";
		cout << "\n\t6.-Salir";
		cout << "\n\n\tElige una opcion:  ";
		cin >> opc;
		// switch para manejar archivos
		switch (opc)
		{
		//cada caso realiza una operacion del menu
		case 1: {
			system("cls");
			metodos.altas();
			cout << "\n\t\t";
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			metodos.bajas();
			cout << "\n\t\t";
			system("pause");
			break;
		}

		case 3: {
			system("cls");
			metodos.consultas();
			cout << "\n\t\t";
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			metodos.buscar();
			cout << "\n\t\t";
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			metodos.modificar();
			cout << "\n\t\t";
			system("pause");

			break;
		}
		case 6: {
			cout << "\n\n\tHa elegido salir...\n\n\t\t"; system("pause");
			break;
		}
		default: {
			cout << "\n\n\tHa elegido una opcion inexistente...\n\n\t\t"; system("pause");
			break;
		}
		}//fin switch

	} while (opc != 6);

	system("cls");

	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
	char cadena[100], nombre[50], op[20];
	cout << "Ingrese el nombre del fichero\n";
	cin >> nombre;
	cin.getline(op, 20);
	ifstream fe(nombre);
	if (!fe) {
		cout << "No se pudo abrir";
		return 0;
	}
	while (!fe.eof()) {
		cout << "\nMostrando 25 lineas\n";
		for (int i = 0;i < 25;i++) {
			if (!fe.eof()) {
				fe.getline(cadena, 128);
				cout << cadena << endl;
			}
		}
		cout << "\nDesea mostrar las siguientes 25?\n";
		cout << "Presione enter\n";
		cout << "Si no desea presione otra tecla\n";
		cin.getline(op, 20);
		if (op[0] != '\0' && op[0] != ' '
			&& op[0] != '\t') {
			cout << "Saliendo..\n";
			break;
		}
		else {
			cout << "Continuando..\n";
		}

	}
	fe.close();
	
	return 0;
}
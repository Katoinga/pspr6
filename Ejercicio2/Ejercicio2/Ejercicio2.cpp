#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	struct Tdato
	{
		int b;
		char s[100];
	};
	int x, n, a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	double f;
	char nombre[] = "Ejercicios ficheros binarios";
	Tdato p;
	ifstream f1;
	ofstream f2;
	f1.open("f1.dat", ios::binary);
	f2.open("f1.dat", ios::binary);

	//a. Escribir el dato entero x en el fichero.
	x = 12345;
	f2.write((char*)&x, sizeof(int));

	//b. Escribir el dato double f en el fichero.
	f = 34.218;
	f2.write((char*)&f, sizeof(double));

	//c. Escribir los 5 primeros elementos del array a en el fichero.
	f2.write((char*)&a[0], 5 * sizeof(int));

	//d. Escribir los 10 primeros caracteres de la cadena nombre en el fichero.
	f2.write(nombre, 10);

	//e. Escribir el dato de tipo Tdato p en el fichero.
	p.b = 12;
	strcpy_s(p.s,"cadena");
	f2.write((char*)&p, sizeof(Tdato));

	f2.close();
	f1.open("f1.dat", ios::binary);

	//f. Leer un dato entero del fichero y almacenarlo en la variable x. 
	f1.read((char*)&x, sizeof(int));

	//g. Leer un dato double del fichero y almacenarlo en la variable f.
	f1.read((char*)&f, sizeof(double));

	//h. Leer 5 enteros almacenarlos en el array a.
	f1.read((char*)&a[0], 5 * sizeof(int));

	//i. Leer 10 caracteres y almacenarlos en la cadena nombre.
	f1.read(nombre, 10);

	//j. Leer un dato de tipo Tdato y almacenarlo en la variable p.
	f1.read((char*)&p, sizeof(Tdato));
	f1.close();

	cout << x << endl;
	cout << f << endl;
	cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << endl;
	cout << nombre << endl;
	cout << p.b << endl;
	cout << p.s << endl;
	return 0;
}
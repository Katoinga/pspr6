
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
	char frase[128];
	char cadena[128];
	ofstream fs("frases.txt");
	do {
		cout << "Ingrese una frase\n"
			<<"Si no desea solo presione intro sin teclear nada\n\n";
		cin.getline(frase, 128);
		fs << frase<<"\n";

	} while (frase[0] != '\0' && frase[0] != ' '
		&& frase[0] != '\t');


	fs.close();

	cout << "Imprimiendo las frases:\n";
	ifstream fe("frases.txt");
	while (!fe.eof()) {
		fe.getline(cadena,128);
		cout << cadena<< endl;
		
	}
	fe.close();

	return 0;
}


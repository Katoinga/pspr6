#pragma once

struct ficha {
public:
	char nombre[50];
	char direccion[50];
	char movil[9];
	char email[50];
	short int cumpledia;
	short int cumplemes;
	int cumpleyear;
	void MostrarNombres(ficha* datos, int numFichas, char agenda[80], FILE* fichero);
	void MostrarTodo(ficha* datos, int numFichas, char agenda[80], FILE* fichero);
	void Buscar(ficha* datos, int numFichas, char agenda[80], FILE* fichero,char textotemporal[20]);

};
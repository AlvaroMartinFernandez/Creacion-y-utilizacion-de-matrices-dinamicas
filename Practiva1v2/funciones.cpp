#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"
#include "MemoryManager.h"
#include<vector>
using namespace std;
vector<vector<float> >ConstruirMatriz(int nFilas, int nColumnas) {
		vector<vector<float>>Matriz(nFilas,vector<float>(nColumnas, 0));
		return Matriz;
}

void IntroducirDatos(vector<vector<float> >& v) {
	float valor=0;
	int Filas=0, Columnas=0;
	printf("Seleccione la fila en la que quiere introducir datos:\n");
	do {
		if (scanf_s("%d", &Filas) != 1) {
			printf("Valor introducidono valido, ejecute de nuevo.\n\n");
			exit(0);
		}
		if (Filas >= v.size())
			printf("ERROR, el numero de FILAS debe estar entre (0-%d)\n", v.size());
	} while (Filas >= v.size());
	printf("Seleccione la columna en la que quiere introducir datos\n");
	do {
		if (scanf_s("%d", &Columnas) != 1) {
			printf("Valor introducidono valido, ejecute de nuevo.\n\n");
			exit(0);
		}
		if (Columnas >= v[Filas].size())
			printf("ERROR, el numero de	COLUMNAS debe estar entre (0-%d)\n", v[Filas].size() - 1);
	} while (Columnas >= v[Filas].size());

	printf("Seleccione el valor (float) que quiere dar al lugar indicado\n");
	if (scanf_s("%f", &valor) != 1) {
		printf("Valor introducidono valido, ejecute de nuevo.\n\n");
		exit(0);
	}
	v[Filas][Columnas] = valor;
}

void Mostrar(vector<vector<float> >& v) {
	int i=0, j=0;
	printf("La matriz es la siguiente\n");
	for (i = 0; i < v.size(); i++) {
		for (j = 0; j < v[i].size(); j++)
			printf("%f \t", v[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
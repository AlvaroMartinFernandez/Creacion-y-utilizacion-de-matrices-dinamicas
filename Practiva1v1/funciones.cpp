#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"
#include "MemoryManager.h"

float** ConstruirMatriz(int nFilas, int nColumnas) {
	float** Matriz= NULL;
	int i= 0;
	int j = 0;
	Matriz = (float**) malloc ( sizeof(float)*nFilas);				//Asignamos memorias a las filas
	if (Matriz == NULL)
	{
		printf("NO SE PUDO CREAR LA MATRIZ \n");					// Verificamos que la asignacion de memoria a sido correcta
			exit(0);
	}
	for (i = 0; i < nFilas; i++) 
		Matriz[i] = (float*)malloc(sizeof(float)*nColumnas);		// asignamos memoria a los datos de cada fila "Columnas"
	
	if (Matriz == NULL)												//verificamos que la memoria a sido asignada
	{
		free(Matriz);												//liberamos memoria asignada previamente
		printf("NO SE PUDO CREAR LA MATRIZ \n");
		exit(0);
	}
	for (i = 0; i < nFilas; i++) {									// inicializamos la matriz a 0
		for (j = 0; j < nColumnas; j++)
			Matriz[i][j] = 0;
	}

	return Matriz;
}

void IntroducirDatos(MatFloat* pDestino) {
	float datos=0;
	printf("Seleccione el valor de tipo Float que quiere dar al lugar indicado: \n");
	if (scanf_s("%f", &datos) != 1) {
		printf("Dato Introducido no es un tipo Float.Ejecute nuevamente el programa\n\n");
		exit(0);
	}
	else {
		pDestino->ppMatrizF[pDestino->nFilas][pDestino->nColumnas] = datos;
	}
}

void Mostrar(MatFloat mOrigen){
	int i = 0;
	int j = 0;
	printf("LA MATRIZ SERA LA SIGUIENTE: \n");
	for ( i = 0; i < mOrigen.nFilas; i++){
		for (j = 0; j < mOrigen.nColumnas; j++) {
			printf("%f\t", mOrigen.ppMatrizF[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void Destruir(MatFloat* pMatFloat) {
	int i = 0;
	if (pMatFloat->ppMatrizF == NULL) {
		printf("No hay matriz que destruir.\n\n");
	}
	else {
		for (i = 0; i < pMatFloat->nFilas; i++) {
			free(pMatFloat->ppMatrizF[i]);
		}
		free(pMatFloat->ppMatrizF);
		pMatFloat->ppMatrizF = NULL;
	}
}
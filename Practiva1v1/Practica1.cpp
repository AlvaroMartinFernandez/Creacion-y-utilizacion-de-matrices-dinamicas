#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"
#include "MemoryManager.h"

int main() {
	{
		int funcion = 0, nFilas= 0, nColumnas = 0, aux=0;
		float** matriz = NULL;
		MatFloat* pDestino = NULL;
		MatFloat* pIntroducir = NULL;

		while (1) {
			printf("1. Construir Matriz\n2. Introducir Matriz\n3. Volcar Matriz\n4. Destruir Matriz\n5. Terminar\n\n");
			aux = scanf_s("%d", &funcion);
			fflush(stdin);
			if (aux != 1) {
				printf("Valor no valido,ejecute programa nuevamente.\n\n");
				fflush(stdin);
				exit(0);
			}
			else {
				switch (funcion) {
				case 1:
				{
					printf("Introduce en numero de filas:\n");
					do {
						if (scanf_s("%d", &nFilas) != 1) {
							printf("Valor no valido,ejecte el programa nuevamente.\n\n");
							exit(0);
						}
						if (nFilas <= 0)
							printf("El numero de filas no puede ser menor de 1\n");
					} while (nFilas <= 0);
					printf("Introduce en numero de columnas:\n");
					do {
						if (scanf_s("%d", &nColumnas) != 1) {
							printf("Valor no valido,ejecte el programa nuevamente.\n\n");
							exit(0);
						}
						if (nColumnas <= 0)
							printf("El numero de columnas no puede ser menor de 1\n");
					} while (nColumnas <= 0);
					matriz = ConstruirMatriz(nFilas, nColumnas);
					pDestino = (MatFloat*)malloc(sizeof(MatFloat));
					break;
				}
				case 2:
				{
					if (matriz == NULL) {
						printf("Error, no hay matriz creada.\n\n");
						break;
					}
					pIntroducir = (MatFloat*)malloc(sizeof(MatFloat));
					pIntroducir->ppMatrizF = matriz;
					printf("Seleccione la fila en la que quiere introducir datos(0-%d)\n", nFilas - 1);
					do {
						if (scanf_s("%d", &pIntroducir->nFilas) != 1) {
							printf("Valor introducido no valido. Ejecute programa nuevamente.\n\n");
							exit(0);
						}
						if (pIntroducir->nFilas >= nFilas)
							printf("ERROR, el numero de FILAS debe estar entre (0-%d)\n", nFilas - 1);
					} while (pIntroducir->nFilas >= nFilas);
					printf("Seleccione la columna en la que quiere introducir datos(0-%d)\n", nColumnas - 1);
					do {
						if (scanf_s("%d", &pIntroducir->nColumnas) != 1) {
							printf("Valor introducido no valido. Ejecute programa nuevamente.\n\n");
							exit(0);
						}
						if (pIntroducir->nColumnas >= nColumnas)
							printf("ERROR, el numero de	COLUMNAS debe estar entre (0-%d)\n", nColumnas - 1);
					} while (pIntroducir->nColumnas >= nColumnas);
					IntroducirDatos(pIntroducir);
					free(pIntroducir);
					break;
				}
				case 3:
				{
					if (matriz == NULL) {
						printf("Error, no hay matriz creada.\n\n");
						break;
					}
					pDestino->nFilas = nFilas;
					pDestino->nColumnas = nColumnas;
					pDestino->ppMatrizF = matriz;
					Mostrar(*pDestino);
					break;
				}
				case 4:
				{
					if (matriz == NULL) {
						printf("Error, no hay matriz creada.\n\n");
						break;
					}
					Destruir(pDestino);
					break;
				}
				case 5:
				{
					if (pDestino == NULL) {
						printf("No hay nada que liberar.\n\n");
					}
					else {
						printf("Se va a liberar la memoria dinamica\n\n");
						Destruir(pDestino);
						free(pDestino);
					}
					if (pIntroducir == NULL) {}
					else
						free(pIntroducir);
					if (matriz == NULL) {}
					else
					{
						printf("BORRAR MATRIZ AUXILIAR\n\n");
						for (int i = 0; i < nFilas; i++) {
							free(matriz[i]);
						}
						free(matriz);
					}
					MemoryManager::dumpMemoryLeaks();
					exit(0);
				}
				default:
				{
					printf("La opcion elegida no esta disponible.\n\n");
					break;
				}
				}
			}
		}
	}
}
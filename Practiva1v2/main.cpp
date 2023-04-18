#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"
#include "MemoryManager.h"

int main() {
	{
		int funcion = 0, nFilas= 0, nColumnas = 0;
		vector<vector<float>>Matriz;
		vector<vector<float>>Matriznula;

		while (1) {
			printf("1. Construir Matriz\n2. Introducir Matriz\n3. Volcar Matriz\n4. Destruir Matriz\n5. Terminar\n\n");
			scanf_s("%d", &funcion);
			switch (funcion) {
			case 1:
			{
				printf("Introduce en numero de filas:\n");
				do {
					if (scanf_s("%d", &nFilas) != 1) {
						printf("Valor introducidono valido, ejecute de nuevo.\n\n");
						exit(0);
					}
					if (nFilas <= 0)
						printf("El numero de filas no puede ser menor de 1\n");
				} while (nFilas <= 0);
				printf("Introduce en numero de columnas:\n");
				do {
					if (scanf_s("%d", &nColumnas) != 1) {
						printf("Valor introducidono valido, ejecute de nuevo.\n\n");
						exit(0);
					}
					if (nColumnas <= 0)
						printf("El numero de columnas no puede ser menor de 1\n");
				} while (nColumnas <= 0);
				Matriz = ConstruirMatriz(nFilas, nColumnas);
				break;
			}
			case 2:
			{
				if (Matriz == Matriznula) {
					printf("error, no hay matriz creada.\n\n");
					break;
				}
				IntroducirDatos(Matriz);
				break;
			}
			case 3:
			{
				if (Matriz == Matriznula) {
					printf("Error, no hay matriz creada.\n\n");
					break;
				}
				Mostrar(Matriz);
				break;
			}
			case 4:
			{
				Matriz = Matriznula;
				break;
			}
				
			case 5:
			{
				MemoryManager::dumpMemoryLeaks();
				exit(1);
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
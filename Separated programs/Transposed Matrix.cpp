#include <stdio.h>
int matriz[30][30];
int matrizB[30][30];
int f, c;

void llenar(int A[][30], int f, int c)
{
	int i, j;
	i = 0;
	while (i <= f)
	{
		j = 0;
		while (j <= c)
		{
			printf("A [%d", i);
			printf(", %d", j);
			printf("] = \n");
			scanf_s("%d", &A[i][j]);
			j++;
		}
		i++;
	}

}

void mostrar(int A[][30], int f, int c)
{
	int i, j;
	i = 0;
	while (i <= f)
	{
		j = 0;
		while (j <= c)
		{
			printf("%d", A[i][j]);
			printf(" | ");
			j++;
		}
		printf(" \n");
		i++;
	}
}

void trasponer(int A[][30], int n, int B[][30])
{
	int i, j;
	i = 0;
	j = 0;
	while (i <= n)
	{
		j = 0;
		while (j <= n)
		{
			B[j][i] = A[i][j];
			j++;
		}
		i++;
	}
}

int main()
{
	do
	{
		printf("Dimensiones de la matriz (filas)\n");
		scanf_s("%d", &f);
		printf("Dimensiones de la matriz (columnas) \n");
		scanf_s("%d", &c);
	} while (c > 30);
	llenar(matriz, f, c);
	mostrar(matriz, f, c);
	printf("Matriz traspuesta es \n");
	trasponer(matriz, f, matrizB);
	mostrar(matrizB, f, c);
}



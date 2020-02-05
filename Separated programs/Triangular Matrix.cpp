#include <stdio.h>
int matriz[30][30];
int n, t;

void llenar(int A[][30], int d)
{
	int i, j;
	i = 0;
	while (i <= d)
	{
		j = 0;
		while (j <= d)
		{
			printf("A [%d, %d]\n", i,j);
			scanf_s("%d", &A[i][j]);
			j++;
		}
		i++;
	}

}

void mostrar(int A[][30], int d)
{
	int i, j;
	i = 0;
	while (i <= d)
	{
		j = 0;
		while (j <= d)
		{
			printf("%d", A[i][j]);
			printf(" | ");
			j++;
		}
		printf(" \n");
		i++;
	}
}

int triangular(int A[][30], int n)
{
	int tri, cont, i, j;
	cont = 1;
	tri = 1; //boolean
	i = 2;
	while ((i <= n) && (tri == 1))
	{
		j = 0;
		while ((j <= cont) && (tri == 1))
		{
			if ((A[i][j] != 0) || (A[j][i] != 0))
			{
				tri = 0;
			}
			j++;
		}
		cont++;
		i++;
	}
	j = 3;
	i = 0;
	while (i <= n - 2)
	{
		j = 3;
		while (j <= n)
		{
			if (A[i][j] != 0)
			{
				tri = 0;
			}
			j++;
		}
		i++;
	}
	return tri;
}

int main()
{
	do
	{
		printf("Dimensiones de la matriz (filas y columnas)\n");
		scanf_s("%d", &n);
	} while (n > 30);
	llenar(matriz, n);
	mostrar(matriz, n);
	t = triangular(matriz, n);
	if (t == 1)
	{
		printf("La matriz es triangular\n");
	}
	else
	{
		printf("La matriz no es triangular\n");
	}
	getchar();
}

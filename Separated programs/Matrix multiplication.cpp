#include <stdio.h>
int matriz[30][30];
int matriz2[30][30];
int multi[30][30];
int f1, c1, f2, c2;

void llenar(int A[][30], int f, int c)
{
	int i, j;
	i = 0;
	while (i <= f)
	{
		j = 0;
		while (j <= c)
		{
			printf("A [%d, %d]\n", i,j);
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

void multiplicar(int A[][30], int B[][30], int C[][30], int n, int n2, int n3)
{
	int i, j, l, suma;
	i = 0;
	j = 0;
	l = 0;
	while (i <= n)
	{
		j = 0;
		l = 0;
		while (l <= n3)
		{
			suma = 0;
			j = 0;
			while (j <= n2)
			{
				suma = suma + A[i][j] * B[j][l];
				j++;
			}
			C[i][l] = suma;
			l++;
		}
		i++;
	}
}

int main()
{
	do
	{
		printf("Number of rows from Matrix 1\n");
		scanf_s("%d", &f1);
		printf("Number of columns from Matrix 2\n");
		scanf_s("%d", &c1);
	} while (c1 > 30);
	printf("Matriz 1 \n");
	llenar(matriz, f1-1, c1-1);
	mostrar(matriz, f1-1, c1-1);
	do
	{
		printf("Number of rows from Matrix 2\n");
		scanf_s("%d", &f2);
		printf("Number of columns from Matrix 2\n");
		scanf_s("%d", &c2);
	} while (c2 > 30);
	printf("Matriz 2 \n");
	llenar(matriz2, f2-1, c2-1);
	mostrar(matriz2, f2-1, c2-1);
	multiplicar(matriz, matriz2, multi, f1, f2, c2);
	printf("Result\n");
	mostrar(multi, f1-1, c2-1);
}

#include <stdio.h>
int matriz[30][30];
int f, c, min;

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

int minimo(int E[][30], int f, int c)
{
	int i, j, min;
	min = E[0][0];
	i = 0;
	while (i <= f)
	{
		j = 0;
		while (j <= c)
		{
			if (E[i][j] < min)
				min = E[i][j];
			j++;
		}
		i++;
	}
	return min;
}

int main()
{
	do
	{
		printf("Number of rows\n");
		scanf_s("%d", &f);
		printf("Number of columns\n");
		scanf_s("%d", &c);
	} while (c > 30);
	llenar(matriz, f, c);
	mostrar(matriz, f, c);
	min = minimo(matriz, f, c);
	printf("The minimum number in the matrix is %d \n", min);
	return 0;
}


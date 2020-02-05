#include <stdio.h>
int vector[50];
int vector2[50];
int n;
void llenar(int* A, int t)
{
	int i;
	i = 0;
	while (i <= t)
	{
		printf("A[ %d ", i);
		printf("]\n");
		scanf_s("%d", &A[i]);
		i++;
	}
}

void mostrar(int A[], int t)
{
	int i;
	i = 0;
	while (i <= t)
	{
		printf(" %d ", A[i]);
		printf(" | ");
		i++;
	}
}

void generar(int A[], int n, int* B)
{
	int i, j, k;
	j = 0;
	k = n;
	i = 0;
	while (i <= n)
	{
		if (A[i] % 2 == 0)
		{
			B[j] = A[i];
			j++;
		}
		else
		{
			B[k] = A[i];
			k--;
		}
		i++;
	}
}

int main()
{
	printf("Array's size \n");
	scanf_s("%d", &n);
	n--;
	llenar(vector, n);
	mostrar(vector, n);
	generar(vector, n, vector2);
	printf("\nResult \n");
	mostrar(vector2, n);
	return 0;
}

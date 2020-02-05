#include <stdio.h>
int notas[4];
int x, p;
void llenar(int A[])
{
	int i;
	i = 1;
	while (i <= 4)
	{
		printf("Grade of the student \n");
		scanf_s("%d", &A[i]);
		i++;
	}
}

int promedio(int A[])
{
	int s, i;
	s = 0;
	i = 1;
	while (i <= 4)
	{
		s = s + A[i];
		i++;
	}
	return s / 4;
}

int maximo(int A[])
{
	int m, i;
	m = A[1];
	i = 2;
	while (i <= 4)
	{
		if (A[i] > m)
		{
			m = A[i];
		}
		i++;
	}
	return m;
}

int main()
{
	llenar(notas);
	p = promedio(notas);
	printf("Average is %d \n", p);
	x = maximo(notas);
	printf("Maximum is %d\n", x);
	return 0;
}

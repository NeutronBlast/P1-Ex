#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mix(char * t1, char * t2) {
	int i, j;
	char palabra[1000];
	char t3[100];
	strcpy_s(t3, "");
	i = 0;
	j = 0;

	if ((strlen(t1) > 0) && (t1[strlen(t1) - 1] == '\n'))
		t1[strlen(t1) - 1] = '\0';

	if ((strlen(t2) > 0) && (t2[strlen(t2) - 1] == '\n'))
		t2[strlen(t2) - 1] = '\0';

	while (i <= strlen(t1) && j <= strlen(t2))
	{
		strcpy_s(palabra, "");
		while ((i <= strlen(t1)) && (j <= strlen(t2)) && (t1[i] != ' ') && (t2[j] != ' '))
		{
			strncat_s(palabra, &t1[i], 1);
			strncat_s(palabra, &t2[j], 1);
			i++;
			j++;
		}

		while ((i <= strlen(t1)) && (t1[i] != ' '))
		{
			strncat_s(palabra, &t1[i], 1);
			i++;
		}

		while ((j <= strlen(t2)) && (t2[j] != ' '))
		{
			strncat_s(palabra, &t2[j], 1);
			j++;
		}
		strcat_s(t3, palabra);
		strcat_s(t3, " ");

		while ((i <= strlen(t1)) && (t1[i] == ' '))
		{
			i++;
		}

		while ((j <= strlen(t2)) && (t2[j] == ' '))
		{
			j++;
		}
	}
	printf("The final text is %s \n", t3);
	return;
}

int crapula(int n)
{
	int suma;
	while (n > 9)
	{
		suma = 0;
		while (n > 0)
		{
			suma = (suma + (n % 10));
			n = n / 10;
		}
		n = suma;
	}
	return n;
}

void desglosar(int n)
{
	int aux, p, x;
	aux = n;
	p = 1;
	while (aux > 9)
	{
		p = p * 10;
		aux = aux / 10;
	}
	x = 0;
	while (p > 0)
	{
		x = ((n / p) + (x * 10));
		printf("%d\n", x);
		n = n % p;
		p = p / 10;
	}
}

long int common(int x, int y) {
	long int z, p, dx, dy, comun, auy;
	z = 0;
	p = 1;
	while (x > 0)
	{
		comun = 0;
		dx = x % 10;
		auy = y;
		while ((auy > 0) && (comun == 0))
		{
			dy = auy % 10;
			if (dx == dy)
			{
				z = z + (dx * p);
				p = p * 10;
				comun = 1;
			}
			auy = auy / 10;
		}
		x = x / 10;
	}
	return z;
}

void crypt(int n, char *t1) {
	int i, p = 0;
	char ABC[27] = "abcdefghijklmnopqrstuvwxyz";
	char t2[100];
	strcpy_s(t2, "");

	for (i = 0; i < strlen(t1); i++) {
		//Search the letter in the alphabet string
		for (p = 0; p <= strlen(ABC); p++) {
			if (t1[i] == ABC[p])
				break;
		}

		if (p <= strlen(ABC) && (t1[i] != ' ')) {
			p += n;
			if (p > strlen(ABC))
				p -= strlen(ABC);
			strncat_s(t2, &ABC[p], 1);
		}
		else {
			strncat_s(t2, &t1[i], 1);
		}
	}

	printf("Encoded text is: %s \n\n ", t2);
}

void llenar(int A[], int n)
{
	int i;
	i = 0;
	while (i <= n)
	{
		printf("A[%d]\n",i);
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

int promedio(int A[], int n)
{
	int s, i;
	s = 0;
	i = 0;
	while (i <= n)
	{
		s = s + A[i];
		i++;
	}
	return s / n;
}

int maximo(int A[], int n)
{
	int m, i;
	m = A[0];
	i = 1;
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

void llenarM(int A[][100], int f, int c)
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

void mostrarM(int A[][100], int f, int c)
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

void trasponer(int A[][100], int n, int B[][100])
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


int triangular(int A[][100], int n)
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

int minimo(int E[][100], int f, int c)
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

void multiplicar(int A[][100], int B[][100], int C[][100], int n, int n2, int n3)
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

void main() {
	/* T is reserved for size of array, I,J reserved for matrix */
	int op = -1, n = 0, o = 0, t = 0, i = 0, j = 0;
	long int x = 0, y = 0;
	char t1[100];
	char t2[100];
	int * A = NULL;
	int * D = NULL;
	int B[100][100], C[100][100], M[100][100];
	while (op) {
		system("cls");
		printf("\n\n\t\tMENU OF BASIC ALGORITHMS EXERCISES\n ");
		printf("1.\tCombine two words \n ");
		printf("2.\tSum the digits of a number consecutively\n ");
		printf("3.\tBreak down a number\n ");
		printf("4.\tGenerate a number with the common digits from 2 numbers\n ");
		printf("5.\tEncode a text\n ");
		printf("6.\tAverage and maximum value of an array\n ");
		printf("7.\tTransposed matrix\n ");
		printf("8.\tCheck if matrix is triangular\n ");
		printf("9.\tCalculate minimum value of a matrix\n ");
		printf("10.\tMultiply 2 matrixes\n ");
		printf("11.\tGroup even numbers at the beginning of an array\n\n\n ");




		printf("98.\tFill a matrix\n ");
		printf("99.\tFill an array\n ");
		printf("0.\tSALIR del sistema\n\n ");
		scanf_s("%i", &op);
		getchar();

		switch (op) {
		case 1:
			fflush(stdin);
			printf("Word 1? \n");
			fgets(t1, 100, stdin);
			printf("Word 2? \n");
			fgets(t2, 100, stdin);
			if ((strlen(t1) > 0) && (t1[strlen(t1) - 1] == '\n'))
				t1[strlen(t1) - 1] = '\0';

			if ((strlen(t2) > 0) && (t2[strlen(t2) - 1] == '\n'))
				t2[strlen(t2) - 1] = '\0';

			mix(t1, t2);
			break;

		case 2:
			fflush(stdin);
			printf("Introduce a number \n");
			scanf_s("%d", &n);
			o = crapula(n);
			printf("The output is %d", o);
			n = 0;
			break;

		case 3:
			fflush(stdin);
			printf("Number? \n");
			scanf_s("%d", &n);
			desglosar(n);
			n = 0;
			break;

		case 4:
			fflush(stdin);
			printf("X = \n");
			scanf_s("%ld", &x);
			printf("Y = \n");
			scanf_s("%ld", &y);
			printf("The number generated is %ld\n", common(x, y));
			break;

		case 5: 
			fflush(stdin);
			printf("Type a text, the program will crypt it 'n' positions forward in the alphabet \n");
			fgets(t1, 100, stdin);

			if ((strlen(t1) > 0) && (t1[strlen(t1) - 1] == '\n'))
				t1[strlen(t1) - 1] = '\0';
			do
			{
				printf("Type the number of positions in the alphabet that the program will crypt on \n");
				scanf_s("%d", &n);
			} while (n < 0);

			crypt(n, t1);
			break;

		case 6:
			fflush(stdin);
			if (!A) {
				printf("Array is empty, please fill it before doing this action\n");
			}
			else {
				x = promedio(A, t);
				y = maximo(A, t);
				printf("Average = %d, Maximum = %d\n", x, y);

			}
			break;

		case 7: 
			fflush(stdin);
			if (i>0 && j>0){
				printf("Normal matrix is \n");
				mostrarM(B, i, j);
				trasponer(B, i, C);
				printf("Transposed matrix is \n");
				mostrarM(C, i, j);
			}
			else {
				printf("Matrix is empty, please fill it before doing this action");
			}
			break;

		case 8:
			fflush(stdin);
			if (j != i && j > 0 && i > 0) {
				printf("Given matrix isn't a square matrix (same number of rows and columns), make a square matrix and try again\n");
			}
			else if (j==i && j>0 && i>0) {
				triangular(B, i);
			}
			else{
				printf("Matrix is empty, please fill a matrix before doing this action\n");
			}

			x = triangular(B, i);
			if (x == 0) printf("Matrix is not triangular\n");
			else printf("Matrix is triangular\n");
			break;

		case 9:
			fflush(stdin);
			if (j>0 && i>0){
				printf("The minimum value of the matrix is %d\n", minimo(B, i, j));
			}
			else{
				printf("Matrix is empty, please fill a matrix before doing this action\n");
			}
			break;

		case 10:
			fflush(stdin);
			int k, l;
			do
			{
				printf("Number of rows from Matrix 1\n");
				scanf_s("%d", &i);
				printf("Number of rows from Matrix 2 \n");
				scanf_s("%d", &k);
				printf("Number of columns from Matrix 1\n");
				scanf_s("%d", &j);
				printf("Number of columns from Matrix 2\n");
				scanf_s("%d", &l);
			} while (j!=k || i>100 || j > 100 || k > 100 || l > 100 || i < 1 || j < 1 || k < 1 || l < 1);
			j--; k--; l--; i--;
			printf("Matrix 1 \n\n");
			llenarM(B, i, j);
			mostrarM(B, i, j);

			printf("Matrix 2 \n\n");
			llenarM(C, k, l);
			mostrarM(C, k, l);
			multiplicar(B, C, M, i, k, l);
			printf("Result\n\n");
			mostrarM(M, i, l);
			break;

		case 11:
			fflush(stdin);
			if (!A) {
				printf("Array is empty, please fill the array before performing this action\n");
			}
			else {
				generar(A, t, D);
				printf("\nResult \n");
				mostrar(D, t);
			}
			break;

		case 98:
			fflush(stdin);
			do
			{
				printf("Number of rows (no more than 99)\n");
				scanf_s("%d", &i);
				printf("Number of columns (no more than 99)\n");
				scanf_s("%d", &j);
			} while (i > 99 || j > 99);
			i--;
			j--;
			llenarM(B, i, j);
			mostrarM(B, i, j);
			break;
		case 99: 
			fflush(stdin);
			printf("Array size\n");
			scanf_s("%d", &t);
			A = (int*)malloc(t*sizeof(int));
			D = (int*)malloc(t * sizeof(int));
			t--;
			llenar(A, t);
			break;
		}



		system("pause");
	};


}
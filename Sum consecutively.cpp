#include <stdio.h>
	int c,n;
		int crapula (int n)
		{
			int suma;
				while (n>9)
				{
					suma=0;
					while (n>0)
					{
						suma=(suma+(n%10));
						n=n/10;
					}
				n=suma;
				}
		return n;
		}

		int main()
		{
			printf("Introduce a number, to end the program introduce 0 \n");
			scanf("%d", &n);
				while (n>0)
				{
					c=crapula(n);
					printf("The output is %d", n);
					printf(" es %d\n", c);
					printf("Introduce another number, to end the program introduce 0\n");
					scanf("%d", &n);
				}
			getchar();
		}

#include <stdio.h>
	int n;
		void desglosar (int n)
		{
			int aux, p,x;
				aux=n;
				p=1;
					while (aux>9)
					{
						p=p*10;
						aux=aux/10;
					}
				x=0;
					while (p>0)
					{
						x=((n/p)+(x*10));
						printf("%d\n", x);
						n=n%p;
						p=p/10;
					}
		}

		int main ()
		{
			printf("Numero? \n");
			scanf("%d", &n);
			desglosar(n);
			getchar();
		}

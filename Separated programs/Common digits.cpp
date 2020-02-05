#include <stdio.h>
	int main ()
	{
		long int z,p,x,y,dx,dy,comun,auy;
		printf("Escribe 2 numeros y el programa generara un tercero con los digitos comunes de x e y \n" );
		scanf_s("%ld", &x);
		printf("y? \n");
		scanf_s("%ld", &y);
		z=0;
		p=1;
			while (x>0)
			{
				comun=0;
				dx=x%10;
				auy=y;
				while ((auy>0) && (comun==0))
				{
					dy=auy%10;
						if (dx==dy)
						{
							z=z+(dx*p);
							p=p*10;
							comun=1;
						}	
				auy=auy/10;
				}		
			x=x/10;
			}
		printf("El numero generado es %ld \n", z);
		getchar();
	}

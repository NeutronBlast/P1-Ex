#include <stdio.h>
#include <string.h>
int main()
{
	int i, p=0, n;
	char t1[75];
	char t2[75];
	char ABC[27] = "abcdefghijklmnopqrstuvwxyz";
	printf("Escribe un texto y el programa lo encriptara en 'n' posiciones del abecedario \n");
	fgets(t1, 75, stdin);
	strcpy_s(t2, "");

	if ((strlen(t1) > 0) && (t1[strlen(t1) - 1] == '\n'))
		t1[strlen(t1) - 1] = '\0';
	do
	{
		printf("Escribe el numero de posiciones del abecedario donde se movera \n");
		scanf_s("%d", &n);
	} while (n < 0);

	i = 0;

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

	printf("%s \n\n ", t2);
	return 0;
}
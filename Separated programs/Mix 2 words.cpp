#include <stdio.h>
#include <string.h>
int main()
{
	int i, j;
	char palabra[75];
	char t1[75];
	char t2[75];
	char t3[75];
	printf("Word 1? \n");
	fgets(t1, 75, stdin);
	printf("Word 2? \n");
	fgets(t2, 75, stdin);
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
	return 0;
}

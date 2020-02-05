/* 2 Menu para manejo dinamico de listas en C */

#include <stdio.h>
#include <stdlib.h>
struct lista {
	int valor;
	lista* prox;
};

lista* v = NULL; //lista volteada

void insertarcab(lista** cab, int x) {
	/* Inserta x por el comienzo de la lista p */
	/* Opcion 1 */
	lista* t = new lista;
	t->valor = x;
	t->prox = *cab;
	*cab = t;
}

void insertarcola(lista** p, int x) {
	/* Inserta x al final de la lista p */
	/* Opcion 2 */
	lista* ax = new lista, * t = *p;
	ax->valor = x;
	ax->prox = NULL;
	if (t == NULL)
		*p = ax;
	else {
		while (t->prox != NULL)
			t = t->prox;
		t->prox = ax;
	}
}

void insertarcolanr(lista** p, int x) {
	/* Inserta un valor en la lista p sin repeticiones */
	/* Opcion 3 */

	lista* ax = new lista, * t = *p;
	int r = 0;
	ax->valor = x;
	ax->prox = NULL;
	if (t == NULL) //lista vacia
		*p = ax;
	else
		if (t->valor == ax->valor) //valor se repite en la primera casilla
			printf("No se puede insertar el elemento %d a la lista porque ya existe\n", ax->valor);
		else {
			while (t->prox != NULL)
			{
				if (t->prox->valor == ax->valor) {
					r = 1;
					printf("No se puede insertar el elemento %d a la lista porque ya existe\n", ax->valor);
				}
				t = t->prox;
			}
			if (r == 0) {
				t->prox = ax;
			}
		}
}

void insertarord(lista** p, int x) {
	/* Inserta x ordenadamente */
	/* Opcion 4 */
	lista* t = *p, * ax = new lista;
	ax->valor = x;
	ax->prox = NULL;

	if (!t) {
		ax->prox = *p;
		*p = ax;
	}
	//endif

	if (t && t->valor >= x) {
		ax->prox = *p;
		(*p) = ax;
		return;
	}
	else if (t && t->valor<=x){
		while (t->prox && t->prox->valor<=x) {
			t = t->prox;
		}
		ax->prox = t->prox;
		t->prox = ax;
	}
}

void insertaordnr(lista** p, int x) {
	/* Inserta ordenadamente en la lista sin repeticiones */
	/* Opcion 5 */
	lista* t = *p, * ax = new lista;
	ax->valor = x;
	ax->prox = NULL;

	if (!t) {
		ax->prox = *p;
		*p = ax;
		return;
	}
	//endif

	if (t && t->valor > x) {
		ax->prox = *p;
		(*p) = ax;
	}
	else if (t && t->valor <= x) {
		while (t->prox && t->prox->valor <= x) {
			if (t->prox->valor == x) {
				printf("No se puede insertar el valor %d a la lista porque ya existe", x);
				return;
			}
			t = t->prox;
		}
		ax->prox = t->prox;
		t->prox = ax;
	}
}

void insertarordd(lista** p, int x, int y) {
	/* Inserta un valor en la lista antes de un valor x dado */
	/* Opcion 6 */
	lista* t = *p, * aux = new lista;
	aux->valor = x; //Nuevo valor
	aux->prox = NULL;
	if (!t) { //Si la lista esta vacia el valor x sera insertado al principio de la lista
		*p = aux;
		return;
	}

	if (t && t->valor == y) {
		aux->prox = (*p);
		*p = aux;
		return;
	}

	else {
		while (t->prox && t->prox->valor != y) {
			t = t->prox;
		}
		aux->prox = t->prox;
		t->prox = aux;
	}
}

void insertarorda(lista** p, int x, int y) {
	/* Inserta un valor en la lista luego de un valor x dado */
	/* Opcion 7 */
	lista* t = *p, * aux = new lista;
	aux->valor = x; //Nuevo valor
	aux->prox = NULL;
	if (!t) { //Si la lista esta vacia el valor x sera insertado al principio de la lista
		*p = aux;
		return;
	}

	if (t && t->valor == y) {
		if ((*p)->prox) {
			aux->prox = (*p)->prox;
			(*p)->prox = aux;
			return;
		}
		(*p)->prox = aux;
		return;
	}

	else {
		while (t && t->valor != y) {
			t = t->prox;
		}

		if (!t) {
			printf("No se puede insertar el valor %d porque %d no existe en la lista", x, y);
			return;
		}
		aux->prox = t->prox;
		t->prox = aux;
		return;
	}
}

void eliminar(lista** p, int x) {
	/* Elimina la primera ocurrencia del valor x en la lista p */
	/* Opcion 8 */
	lista* t = *p;
	if (t)
		if (t->valor == x) {
			*p = (*p)->prox;
			delete(t);
		}
		else {
			while ((t->prox) && (t->prox->valor != x)) t = t->prox;
			if (t->prox) {
				lista* aux = t->prox;
				t->prox = t->prox->prox;
				delete(aux);
			}
		}
}

void repetidos(lista* p) {
	/* Elimina elementos repetidos */
	/* Opcion 9 */
	lista* t = p, * ax = t, * temp = t;
	while (t) {
		*ax = *t;
		while (ax->prox != NULL) {
			if (ax->prox->valor == t->valor) {
				temp = ax->prox;
				ax->prox = temp->prox;
				delete(temp);
			}
			else
				ax = ax->prox;
		}
		t = t->prox;
	}
}

void primos(lista** p)
/* Elimina numeros primos */
/* Opcion 10 */
{
	lista* t = *p, * aux = *p, * temp = *p;
	int div = 2, prim = 1;
	while (t)
	{
		prim = 1;
		while ((div <= (t->valor) / 2) && (prim == 1))
		{
			if (t->valor % div == 0)
				prim = 0;
			div++;
		}

		if (prim == 1)
		{
			aux = t->prox;
			temp = t;
			t = t->prox;
			delete(temp);
		}
		else t = t->prox;

	}
}

void mostrar(lista* cab) {
	/* Muestra por pantalla la lista enlazada */
	/* Opcion 11 */
	lista* t = cab;
	system("cls");
	printf("\n\nMostrar lista\n\n  Cab ");
	while (t) {
		printf("->[%i]", t->valor);
		t = t->prox;
	}
	printf("->NULL\n\n");
}

void voltear(lista** p, int y)
/* Voltea la lista con una lista auxiliar */
/* Opcion 12 */
{
	lista* t = *p;
	while (t != NULL)
	{
		y = t->valor;
		insertarcab(&v, y);
		t = t->prox;
	}
}


int main() {
	int op = -1, x = 0, y = 0;
	lista* p = NULL;
	while (op) {
		system("cls");
		printf("\n\n\t\tMENU DE MANEJO DE LISTAS \n ");
		printf("1.\tInsertar por comienzo de lista\n ");
		printf("2.\tInsertar al final de lista\n ");
		printf("3.\tInsertar al final de la lista sin repeticiones\n ");
		printf("4.\tInsertar ordenadamente\n ");
		printf("5.\tInsertar ordenadamente sin repeticiones\n ");
		printf("6.\tInsertar dato antes de un valor dado\n ");
		printf("7.\tInsertar dato luego de un valor dado\n ");
		printf("8.\tEliminar dato\n ");
		printf("9.\tEliminar repetidos\n ");
		printf("10.\tEliminar numeros primos\n ");
		printf("11.\tMostrar lista\n ");
		printf("12.\tVoltear lista utilizando lista auxiliar\n\n\n");
		printf(" 0.\tSALIR del sistema\n\n ");
		scanf_s("%i", &op);

		switch (op) {
		case 1: printf("\nIndique dato a insertar\n");
			scanf_s("%i", &x);
			insertarcab(&p, x);
			break;
		case 2: printf("\nIndique dato a insertar\n");
			scanf_s("%i", &x);
			insertarcola(&p, x);
			break;
		case 3: printf("\nIndique dato a Insertar\n");
			scanf_s("%i", &x);
			insertarcolanr(&p, x);
			break;
		case 4: printf("\nIndique dato a insertar\n");
			scanf_s("%i", &x);
			insertarord(&p, x);
			break;
		case 5: printf("\nIndique dato a Insertar\n");
			scanf_s("%i", &x);
			insertaordnr(&p, x);
			break;
		case 6: printf("\nIndique dato a insertar\n");
			scanf_s("%i", &x);
			printf("\nAntes de que valor le gustaria insertar dicho numero?\n");
			scanf_s("%i", &y);
			insertarordd(&p, x, y);
			break;
		case 7: printf("\nIndique dato a insertar\n");
			scanf_s("%i", &x);
			printf("\nDetras de que valor le gustaria insertar dicho numero?\n");
			scanf_s("%i", &y);
			insertarorda(&p, x, y);
			break;
		case 8: printf("\nIndique dato a eliminar\n ");
			scanf_s("%i", &x);
			eliminar(&p, x);
			break;
		case 9: repetidos(p);
			printf("Se han eliminado los repetidos\n");
			break;
		case 10: primos(&p);
			printf("Se han eliminado los numeros primos\n");
			break;
		case 11: mostrar(p);
			break;
		case 12: voltear(&p, 0);
			mostrar(v);
			break;
		}

		system("pause");
	};


}

/* FIN de Menu para manejo dinamico de listas en C */
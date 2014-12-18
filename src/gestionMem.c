/*
	gestionMem.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "conio.h"

char *lireChaine();

void main(int argc, char **argv) {

	char *nom, *p;
	printf("Entrez nom\n");
	nom = lireChaine();
	printf("Nom : %s\n",nom);
	exit(0);
	free(nom);
}

char * lireChaine() {
	int taille = 1;
	char *p;
	p = (char *) malloc(1);
	while((p[taille-1]=getche()) != '\r' && (p != NULL)) {
		p = (char *) realloc(p,++taille);
	}
	p[taille-1] = '\0';
	return p;
}
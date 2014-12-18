/*
	pointeur_de_pointeur.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void affiche(char **p, int taille);
void bulle(char **p, int taille);
void bulleV2(char **p, int taille);

void main(int argc, char **argv) {
	static char *pnom[10] = {"Alfred", "Etienne", "Bob", "Serge", "Pierre", "Laurent", "Herve", "Denis", "Vero", "Paul"};
	//affiche(pnom,10);
	//bulle(pnom,10);
	affiche(pnom,10),
	bulleV2(pnom,10);
	affiche(pnom,10);

	exit(0);
}

void affiche(char **p, int taille) {
	int i;
	for(i = 0; i < taille; i++) {
		printf("Nom %d : %s\n",i+1,*(p+i));
	}
}

void bulle(char **p, int colonne) {
	int i, j;
	char *ptmp;
	for(i = colonne - 1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(strcmp(*(p+j), *(p+j+1)) > 0) {
				ptmp = *(p+j);;
				*(p+j) = *(p+(j+1));
				*(p+(j+1)) = ptmp;
			}
		}
	}
}

void bulleV2(char **p, int colonne) {
	char **fin, *ptmp, **deb;
	for(fin = (p+colonne-1); fin != p; fin--) {
		for(deb = p; deb < fin; deb++) {
			if(strcmp(*(deb), *(deb+1)) > 0) {
				ptmp = *(deb);
				*(deb) = *(deb+1);
				*(deb+1) = ptmp;
			}
		}
	}

}
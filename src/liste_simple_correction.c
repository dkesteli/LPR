/*
	pgm : liste_simple_correction.c
	author : Denis Kestelier
*/

#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"

struct element {
	short num;
	char texte[7];
	struct element *suiv;
};

int main(int argc, char **argv) {
	struct element *debut = NULL, *p, *tmp;
	static char mot[7] = "TEXTE  ";
	short i;
	/*creation*/
	debut = (struct element *) malloc(sizeof(struct element));
	debut->num = 1;
	mot[6] = '1';
	strcpy(debut->texte,mot);
	tmp = debut;

	for(i = 2; i < 6; i++) {
		p = (struct element *) malloc(sizeof(struct element));
		p->num = i;
		mot[6] = i + 48;
		strcpy(p->texte,mot);
		tmp->suiv = p;
		tmp = p;
	}
	p->suiv = NULL;
	/*afficher*/
	p= debut;
	while(p) {
		printf("\n%d %s",p->num,p->texte);
		p = p->suiv;
	}
	/*detruire*/
	p = debut;
	while(p) {
		tmp = p;
		p = p->suiv;
		free(tmp);
	}
	debut = NULL;

}
/*
	pgm : liste_double_void_correction.c
	author : Denis Kestelier
*/

#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"

struct element {
	short num;
	char chaine[25];
	struct element *suiv, *prec;
};

void insertion_debut(struct element **d, struct element **f);
void afficher_debut(struct element *d);

int main(int argc, char **argv) {
	struct element *debut = NULL, *fin = NULL;
	short choix;
	do {
		printf("1. Insertion au debut\n");
		printf("2. Afficher a partir du debut\n");
		printf("Choix? ");
		scanf("%hd",&choix);
		switch(choix) {
			case 1:
				insertion_debut(&debut,&fin);
				break;
			case 2:
				afficher_debut(debut);
				break;
		}
	} while(choix);

}

void insertion_debut(struct element **d, struct element **f) {
	struct element *p = (struct element *) malloc(sizeof(struct element));

	printf("\nChaine :");
	gets(p->chaine);
	printf("\nNumero :");
	scanf("%hd",&p->num);
	if(*d) {
		(*d)->prec = p;
	} else {
		*f = p;
	}
	p->prec = NULL;
	p->suiv = *d;
	*d = p;
}

void afficher_debut(struct element *d) {
	if(!d) {
		printf("Liste vide\n");
	} else {
		while(d) {
			printf("Numero : %d\n",d->num);
			printf("Texte : %s\n",d->chaine);
			d = d->suiv;
		}
	}
}
/*
	exam2_q2.c
	author : Denis Kestelier
	Question : 
	Fonction qui reçoit : 
	2 listes simplement chainée de fiches avec un entier et  un mot de 25 caractères.
	qui supprime la 1ère fiche de la 2ème liste
	et ajoute les valeurs à la 1ère fiche de la 1ère liste.
	Rq : si le mot est trop long, il n'est pas ajouté mais il écrase.
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct element {
	short nombre;
	char mot[5];
	struct element *suiv;
};

void addFromL2ToL1(struct element **l1, struct element **l2);

int main(int argc, char **argv) {
	struct element *l1 = NULL, *l2 = NULL, *tmp;
	l1 = (struct element *) malloc(sizeof(struct element));
	l2 = (struct element *) malloc(sizeof(struct element));
	l1->nombre = 1;
	strcpy(l1->mot,"Hello");
	l1->suiv = NULL;
	l2->nombre = 4;
	strcpy(l2->mot," Denis");
	l2->suiv = NULL;
	addFromL2ToL1(&l1,&l2);
	tmp = l1;
	while(tmp) {
		printf("\n%d %s",tmp->nombre,tmp->mot);
		tmp = tmp->suiv;
	}
	tmp = l2;
	while(tmp) {
		printf("\n%d %s",tmp->nombre,tmp->mot);
		tmp = tmp->suiv;
	}

	return 0;
}

void addFromL2ToL1(struct element **l1, struct element **l2) {
	struct element *tmp = *l2;
	if((strlen((*l2)->mot) + strlen((*l1)->mot)) < 5) {
		strcat((*l1)->mot,(*l2)->mot);
	} else {
		strcpy((*l1)->mot,(*l2)->mot);
	}
	(*l1)->nombre += (*l2)->nombre;
	(*l2) = tmp->suiv;
	free(tmp);

}
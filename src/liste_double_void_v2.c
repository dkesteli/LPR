/*
	pgm : liste_double.c
	author : Denis Kestelier
*/

#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"

struct comp {
	int num;
	char mot[20];
};

struct liste{
	struct comp composante;
	struct liste *next;
	struct liste *prev;
};

struct liste *nouvelElement();
void afficherListe(struct liste *pliste);
void insDeb(struct liste **debut, struct liste **fin);
void insFin(struct liste **debut, struct liste **fin);
void supprimerEnTete(struct liste **debut, struct liste **fin);
void supprimerEnFin(struct liste **debut, struct liste **fin);
char menu();

int main(int argc, char **argv) {
	struct liste **debut = NULL, **fin = NULL;
	char c;
	debut = malloc(sizeof(struct liste));
	*debut = NULL;
	fin = malloc(sizeof(struct liste));
	*fin = NULL;
	while((c = menu()) != '0') {
		putchar('\n');
		switch(c) {
			case '1':
				insDeb(debut,fin);
				break;
			case '2':
				insFin(debut,fin);
				break;
			case '3':
				supprimerEnTete(debut,fin);
				break;
			case '4':
				supprimerEnFin(debut,fin);
				break;
			case '5':
				afficherListe(*debut);
				break;
			default:
				printf("Mauvaise option!\n");
		}
	}
	return 0;
}
struct liste *nouvelElement() {
	struct liste *new = malloc(sizeof(struct liste));
	printf("Entrez un numero\n");
	scanf("%d",&new->composante.num);
	printf("Entrez un texte\n");
	scanf("%s",new->composante.mot);
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void insDeb(struct liste **debut, struct liste **fin) {
	struct liste *new;
	if(*debut == NULL) { /*liste vide */
		new = nouvelElement();
		*debut = new;
		*fin = new;
	} else {
		new = nouvelElement();
		new->next = *debut;
		*debut = new;
	}
}

void insFin(struct liste **debut, struct liste **fin) {
	struct liste *new;
	if(*fin == NULL) {
		insDeb(debut,fin);
	} else {
		new = nouvelElement();
		new->prev = *fin;
		(*fin)->next = new;
		*fin = new;
	}
}

void supprimerEnTete(struct liste **debut, struct liste **fin) {
	struct liste *tmp;
	if(*debut == NULL) {
		printf("Erreur! Liste vide\n");
	}
	else if(*debut == *fin) {
		tmp = *debut;
		*debut = NULL;
		*fin = NULL;
		free(tmp);
	} else {
		tmp = *debut;
		*debut = tmp->next;
		free(tmp);
	}
}

void supprimerEnFin(struct liste **debut, struct liste **fin) {
	struct liste *tmp;
	if(*fin == NULL) {
		printf("Erreur! Liste vide\n");
	}
	else if(*debut == *fin) {
		supprimerEnTete(debut,fin);
	} else {
		tmp = *fin;
		tmp->prev->next = NULL;
		*fin = tmp->prev;
		free(tmp);
	}
}

void afficherListe(struct liste *debut) {
	struct liste *tmp = debut;
	if(tmp == NULL) {
		printf("Liste vide\n");
	} else {
		while(tmp != NULL) {
			printf("Numero : %d\n",tmp->composante.num);
			printf("Texte : %s\n",tmp->composante.mot);
			tmp = tmp->next;
		}
	}
}

char menu() {
	printf("Menu : \n");
	printf("1 : Inserer en debut de liste\n");
	printf("2 : Inserer en fin de liste\n");
	printf("3 : Supprimer en tete de liste\n");
	printf("4 : Supprimer en fin de liste\n");
	printf("5 : Afficher la liste\n");
	printf("0 : Quitter\n");
	printf("Choix : ");
	return getche();
}
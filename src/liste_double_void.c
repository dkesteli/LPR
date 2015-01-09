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

struct elem{
	struct comp composante;
	struct elem *next;
	struct elem *prev;
};

struct liste {
	struct elem * debut;
	struct elem * fin;
};

struct elem *nouvelElement();
void afficherListe(struct liste *pliste);
void init(struct liste *pliste);
void insDeb(struct liste *pliste);
void insFin(struct liste *pliste);
void supprimerEnTete(struct liste *pliste);
void supprimerEnFin(struct liste *pliste);
char menu();

int main(int argc, char **argv) {
	struct liste *pliste = NULL;
	char c;

	pliste = malloc(sizeof(struct liste));
	init(pliste);
	while((c = menu()) != '0') {
		putchar('\n');
		switch(c) {
			case '1':
				insDeb(pliste);
				break;
			case '2':
				insFin(pliste);
				break;
			case '3':
				supprimerEnTete(pliste);
				break;
			case '4':
				supprimerEnFin(pliste);
				break;
			case '5':
				afficherListe(pliste);
				break;
			default:
				printf("Mauvaise option!\n");
		}
	}
	return 0;
}
struct elem *nouvelElement() {
	struct elem *new = malloc(sizeof(struct elem));
	printf("Entrez un numero\n");
	scanf("%d",&new->composante.num);
	printf("Entrez un texte\n");
	scanf("%s",new->composante.mot);
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void init(struct liste *pliste) {
	pliste->debut = NULL;
	pliste->fin = NULL;
}

void insDeb(struct liste *pliste) {
	struct elem *new;
	if(pliste->debut == NULL) { /*liste vide */
		new = nouvelElement();
		pliste->debut = new;
		pliste->fin = new;
	} else {
		new = nouvelElement();
		new->next = pliste->debut;
		pliste->debut = new;
	}
}

void insFin(struct liste *pliste) {
	struct elem *new;
	if(pliste->fin == NULL) {
		insDeb(pliste);
	} else {
		new = nouvelElement();
		new->prev = pliste->fin;
		pliste->fin->next = new;
		pliste->fin = new;

	}
}

void supprimerEnTete(struct liste *pliste) {
	struct elem *tmp;
	if(pliste->debut == NULL) {
		printf("Erreur! Liste vide");
	}
	else if(pliste->debut == pliste->fin) {
		tmp = pliste->debut;
		pliste->debut = NULL;
		pliste->fin = NULL;
		free(tmp);
	} else {
		tmp = pliste->debut;
		pliste->debut = tmp->next;
		free(tmp);
	}
}

void supprimerEnFin(struct liste *pliste) {
	struct elem *tmp;
	if(pliste->fin == NULL) {
		printf("Erreur! Liste vide");
	}
	else if(pliste->debut == pliste->fin) {
		supprimerEnTete(pliste);
	} else {
		tmp = pliste->fin;
		pliste->fin->prev->next = NULL;
		pliste->fin = pliste->fin->prev;
		free(tmp);
	}
}

void afficherListe(struct liste *pliste) {
	struct elem *tmp = pliste->debut;
	if(tmp == NULL) {
		printf("Liste vide\n");
	} else {
		printf("pointeur debut : %d\n",pliste->debut);
		printf("pointeur fin : %d\n",pliste->fin);
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
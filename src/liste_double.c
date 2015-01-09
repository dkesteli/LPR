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
struct liste *ajouterEnTete(struct liste *pliste);
struct liste *ajouterEnFin(struct liste *pliste);
struct liste *supprimerEnTete(struct liste *pliste);
struct liste *supprimerEnFin(struct liste *pliste);
void afficherListe(struct liste *pliste);
char menu();
 
int main(int argc, char **argv) {
	struct liste *liste = NULL;
	char c;

	while((c = menu()) != '0') {
		putchar('\n');
		switch(c) {
			case '1':
				liste = ajouterEnTete(liste);
				break;
			case '2':
				liste = ajouterEnFin(liste);
				break;
			case '3':
				liste =  supprimerEnTete(liste);
				break;
			case '4':
				liste = supprimerEnFin(liste);
				break;
			case '5':
				afficherListe(liste);
				break;
			default:
				printf("Mauvaise option!\n");
		}
	}
	free(liste);
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

struct liste *ajouterEnTete(struct liste *pliste) {
	struct liste *new;
	new = nouvelElement();
	new->next = pliste;
	return new;
}

struct liste *ajouterEnFin(struct liste *pliste) {
	struct liste *tmp = pliste, *new = NULL;
	if(pliste == NULL) {
		pliste = ajouterEnTete(pliste);
	} else {
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		new = nouvelElement();
		tmp->next = new;
		new->prev = tmp;
	}
	return pliste;

}

struct liste *supprimerEnTete(struct liste *pliste) {
	struct liste *tmp = pliste;
	if(pliste == NULL) {
		fprintf(stderr, "Erreur : liste vide!\n");
		return NULL;
	}
	pliste = tmp->next;
	free(tmp);
	return pliste;
}

struct liste *supprimerEnFin(struct liste *pliste) {
	struct liste *tmp = pliste;
	if(pliste == NULL) {
		fprintf(stderr, "Erreur : liste vide!\n");
		return NULL;
	}
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->prev->next = NULL;
	free(tmp);
	return pliste;
}

void afficherListe(struct liste *pliste) {
	struct liste *tmp = pliste;
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
	printf("1 : Ajouter en tete de liste\n");
	printf("2 : Ajouter en fin de liste\n");
	printf("3 : Supprimer en tete de liste\n");
	printf("4 : Supprimer en fin de liste\n");
	printf("5 : Afficher la liste\n");
	printf("6 : Inserer en debut de liste\n");
	printf("7 : Inserer en fin de liste\n");
	printf("0 : Quitter\n");
	printf("Choix : ");
	return getche();
}

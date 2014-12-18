/*
	chaine_caractere.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void afficheV1(char nom[][21], int ligne);
void triV1(char nom[][21], int ligne);
void afficheV2(char *pnom[21], int colonne);
void triV2(char *pnom[21], int colonne);
void remplirNomV1(char nom[][21], int ligne);

int main(int argc, char *argv[]) {
	static char nom[10][21] = {"Alfred", "Etienne", "Bob", "Serge", "Pierre", "Laurent", "Herve", "Denis", "Vero", "Paul"};
	static char *pnom[10] = {"Alfred", "Etienne", "Bob", "Serge", "Pierre", "Laurent", "Herve", "Denis", "Vero", "Paul"};
	printf("Version 1 :\n");
	afficheV1(nom, 10);
	triV1(nom,10);
	afficheV1(nom,10);
	remplirNomV1(nom,10);
	afficheV1(nom,10);
	triV1(nom,10);
	afficheV1(nom,10);
	printf("Version 2 :\n");
	afficheV2(pnom,10);
	triV2(pnom,10);
	afficheV2(pnom,10);
	exit(0);
}

void afficheV1(char nom[][21], int ligne) {
	int i;
	for(i = 0; i < ligne; i++) {
		printf("nom %d : %s\n",i+1,nom[i]);
	}
}

void afficheV2(char *nom[], int colonne) {
	int i;
	for(i = 0; i < colonne; i++) {
		printf("Nom %d : %s\n",i+1,nom[i]);
	}
}

void triV1(char nom[][21], int ligne) {
	int i, j;
	char tmp[21];
	for(i = ligne-1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(strcmp(nom[j],nom[j+1]) > 0) {
				strcpy(tmp, nom[j]);
				strcpy(nom[j], nom[j+1]);
				strcpy(nom[j+1],tmp);
			}
		}
	}
}

void triV2(char *pnom[], int colonne) {
	int i, j;
	char *ptmp;
	for(i = colonne - 1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(strcmp(pnom[j], pnom[j+1]) > 0) {
				ptmp = pnom[j];
				pnom[j] = pnom[j+1];
				pnom[j+1] = ptmp;
			}
		}
	}
}

void remplirNomV1(char nom[][21], int ligne) {
	int i;
	for(i = 0; i < ligne; i++) {
		printf("Entrez nom %d : ",i+1);
		gets(nom[i]);
	}
}
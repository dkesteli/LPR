/*
	cptcaractere.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

void erreur(char *nomFichier);

void main(int argc, char *argv[]) {
	FILE *fp;
	short nb, somme = 0, v[512];

	if(argc != 2) {
		printf("Erreur! Usage : %s fichier",argv[0]);
		exit(1);
	}
	if((fp = fopen(argv[1],"r")) == NULL) {
		erreur(argv[1]);
		exit(2);
	}
	while((nb = fread(v, 1, 512, fp))) {
		somme += nb;
	}
	printf("Nombre de caractere dans le fichier : %d",somme);
	exit(0);

}

void erreur(char *nomFichier) {
	printf("\nProbleme d'ouverture du fichier %s",nomFichier);
	exit(3);
}
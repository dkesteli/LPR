/*
	copy.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

void erreur(char *nomFichier);

void main(int argc, char *argv[]) {
	FILE *fp1, *fp2;
	short c;
	if(argc == 1) {
		fp1 = stdin;
		fp2 = stdout;
	} else if(argc == 2) {
		if((fp1 = fopen(argv[1],"r")) == NULL) {
			erreur(argv[1]);
			exit(3);
		}
		fp2 = stdout;
	} else if (argc == 3) {
		if((fp1 = fopen(argv[1],"r")) == NULL) {
			erreur(argv[1]);
			exit(3);
		}
		if((fp2 = fopen(argv[2],"w")) == NULL) {
			erreur(argv[2]);
			exit(3);
		}
	} else {
		fprintf(stderr, "\nMal lance");
	}
	while((c=fgetc(fp1)) != EOF) {
			fputc(c,fp2);
	}
	exit(0);
}

void erreur(char *nomFichier) {
	printf("\nProbleme d'ouverture du fichier %s",nomFichier);
	exit(3);
}
/*
	copyV2.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

void erreur(char *nomFichier);

void main(int argc, char *argv[]) {
	FILE *fp1, *fp2;
	int nbR, nbW, blocChar = 10000;
	char v[10000];
	if(argc != 3) {
		fprintf(stderr,"Mauvais nombre de parametres! Requis : 2");
		exit(1);
	}
	if((fp1 = fopen(argv[1],"r")) == NULL) {
		erreur(argv[1]);
		exit(3);
	}
	if((fp2 = fopen(argv[2],"w")) == NULL) {
		erreur(argv[2]);
		exit(3);
	}

	while((nbR=fread(v,1,blocChar,fp1))) {
			nbW = fwrite(v,1,nbR,fp2);
			if(ferror(fp2)) {
				erreur(argv[2]);
				exit(3);
			}
	}
	if(feof(fp1)) {
		exit(0);
	} else {
		erreur(argv[1]);
		exit(3);
	}
}

void erreur(char *nomFichier) {
	fprintf(stderr,"\nProbleme d'ouverture du fichier %s\n",nomFichier);
	perror(nomFichier);
	exit(3);
}
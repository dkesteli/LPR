/*
	pointeurs.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

void type(char *ch);
void copy(char *ch1, char *ch2);
void erreur(char *nomFichier);

int main(int argc, char*argv[]) {

	if(argc == 2) {
		type(argv[1]);
	} else if (argc == 3) {
		copy(argv[1],argv[2]);
	} else {
		printf("Mauvais nombre d'arguments");
		exit(1);
	}
	exit(0);
}

void type(char *ch) {
	FILE *fp;
	short c;
	if((fp = fopen(ch,"r")) != NULL) {
		while((c=fgetc(fp)) != EOF) {
			putchar(c);
		}
	}
}

void copy(char *ch1, char *ch2) {
	FILE *fp1, *fp2;
	short c;
	if(((fp1 = fopen(ch1,"r")) != NULL) && ((fp2 = fopen(ch2,"w")) != NULL)) {
		while((c=fgetc(fp1)) != EOF) {
			fputc(c,fp2);
		}
	}
}

void erreur(char *nomFichier) {
	printf("\nProblème d'ouverture du fichier %s",nomFichier);
	exit(3);
}

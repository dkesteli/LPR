/*
	cpyautoexec.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

void erreur(char *nomFichier);

void main() {
	FILE *f1, *f2;
	if(!(f1 = fopen("C:\\autoexec.bat","r"))) {
		erreur("C:\\autoexec.bat");
	}
	if(!(f2 = fopen("C:\\autoexec.bak","w"))) {
		erreur("C:\\autoexec.bak");
	}
	while(!feof(f1)) {
		fputc(fgetc(f1),f2);
	}
	exit(0);
}

void erreur(char *nomFichier) {
	fprintf(stderr,"\nProbleme d'ouverture du fichier %s\n",nomFichier);
	perror(nomFichier);
	exit(3);
}
/*
	cptmots.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

void main(int argc, char *argv[]) {
	FILE *fp;
	short cpt = 0;
	char mot[30];
	if(argc != 2) {
		printf("Mauvais nombre d'arguments! Usage : cptmots fichier");
		exit(1);
	}
	if((fp = fopen(argv[1],"r")) != NULL) {
		while(fscanf(fp, "%s",mot) != EOF) {
			cpt++;
		}
	}
	printf("Nombre de mot dans le fichier %s : %d",argv[1],cpt);
	exit(0);
}
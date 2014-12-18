/*
	cptligne.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

void main(int argc, char *argv[]) {
	FILE *fp;
	short cpt = 0;
	char ligne[128];
	if(argc != 2) {
		printf("Mauvais nombre d'arguments! Usage : cptligne fichier");
		exit(1);
	}
	if((fp = fopen(argv[1],"r")) != NULL) {
		while(fgets(ligne,128,fp) != NULL) {
			cpt++;
		}
	}
	printf("Nombre de ligne dans le fichier %s : %d",argv[1],cpt);
	exit(0);

}
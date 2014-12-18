/*
	pyramide.c
	author : Denis Kestelier
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void main(int argc, char *argv[]) {
	int nbLignes, i, j;
	if(argc != 2) {
		printf("Mauvais nombre d'arguments");
		exit(1);
	}
	nbLignes=atoi(argv[1]);
	if(nbLignes <= 0) {
		printf("Mauvais argument");
		exit(2);
	}
	if(nbLignes > 20) {
		printf("Pyramide trop grande");
		exit(3);
	}
	for (i = 1; i <= nbLignes; i++) {
		for(j = 0; j < nbLignes - i; j++) {
			putchar(' ');
		}
		for (j = 0; j < 2*i-1; j++) {
			putchar('*');
		}
		printf("\n");
	}
	exit(0);
}
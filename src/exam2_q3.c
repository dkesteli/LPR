/*
	exam2_q3.c
	author : Denis Kestelier
	Question : 
	Programme qui fait la moyenne d'une suite de rééls passé en ligne de commande.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	double somme = 0, nb;
	int i;

	if(argc < 3) {
		fprintf(stderr, "Erreur pas assez d'arguments");
		exit(1);
	}
	for(i = 1; i < argc; i++) {
		if((nb = atof(argv[i]))) {
			somme += nb;
		}
	}
	fprintf(stdout, "\nLa sommes des nombres est : %.3f", somme);
	return 0;
}
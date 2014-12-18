/*
	exam_q2.c
	author : Denis Kestelier
	Question : 
	Programme qui calcule et affiche la somme d'entiers positifs passés en ligne de commande.
	Rq : ne pas utiliser de fonction de bibliothèque.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

int atoint(char *ch);

void main(int argc, char *argv[]) {
	short somme = 0, nb, i;
	if(argc < 3) {
		printf("Mauvais nombre d'arguments");
		exit(1);
	}
	for(i = 1; i < argc; i++) {
		if((nb = atoint(argv[i]))) {
			somme += nb;
		}
	}
	fprintf(stdout, "\nLa sommes des nombres est : %d", somme);
}

int atoint(char *ch) {
	int nombre = 0;
	while((*ch >= '0') && (*ch <= '9') && (*ch != '\0')) {
			nombre *= 10;
			nombre += (*ch-48);
			ch++;
	}
	return ((*ch == '\0') ? nombre : 0);
}


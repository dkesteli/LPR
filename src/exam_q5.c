/*
	exam_q5.c
	author : Denis Kestelier
	Question : 
	Fonction qui reçoit un vecteur d'entiers de 2 bytes créé de façon dynamique.
	Elle supprime tous les négatifs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

int supprimeNeg(short **v, short taille);

int main(int argc, char **argv) {

	short *v, n = 2, i;
	short newTaille, taille = 5;
	if((v = (short *) calloc(taille,sizeof(short)))) {
		for(i = 0; i < taille; i++) {
			*(v+i) = n;
			n = (n*-1) * 2;
		}
	}
	for(i = 0; i < taille; i++) {
		printf("%d\n",*(v+i));
	}
	newTaille = supprimeNeg(&v,taille);
	printf("newTaille : %d\n",newTaille);
	for(i = 0; i < newTaille; i++) {
		printf("%d\n",*(v+i));
	}
	return 0;
}

int supprimeNeg(short **vect, short taille) {
	short *vreturn = NULL, i, cpt = 0, *v = *vect;
	for(i = 0; i < taille; i++) {
		if(*(v+i) >= 0) {
			if(vreturn == NULL) {
				vreturn = (short *) malloc(sizeof(short));
				*(vreturn + cpt) = *(v+i);
				cpt++;
			} else {
				vreturn = (short *) realloc(vreturn, (cpt+1)*sizeof(short));
				*(vreturn + cpt) = *(v+i);
				cpt++;
			}

		}
	}
	*vect = vreturn;
	return ((cpt < taille) ? cpt:taille);
}
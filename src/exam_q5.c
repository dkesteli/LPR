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

short * supprimeNeg(short *v);

int main(int argc, char **argv) {

	short *v, n = 2, i;
	if((v = (short *) calloc(5,sizeof(short)))) {
		for(i = 0; i < 5; i++) {
			*(v+i) = n;
			n = (n*-1) * 2;
		}
	}
	for(i = 0; i < 5; i++) {
		printf("%d\n",*(v+i));
	}
	v = supprimeNeg(v);
	for(i = 0; i < 5; i++) {
		printf("%d\n",*(v+i));
	}
	return 0;
}

short * supprimeNeg(short * v) {
	short *vreturn = NULL, i, cpt = 0;
	for(i = 0; i < 5; i++) {
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
	return vreturn;
}
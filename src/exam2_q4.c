/*
	exam2_q4.c
	author : Denis Kestelier
	Question : 
	Soit un vecteur de pointeurs pointant vers des mots.
	Pour continuer le jeu du pendu, fonction qui reçoit ce vecteur et un entier désignant le mot avec lequel on joue et qui reçoit
	une lettre qui est la proposition du joueur. Elle place la lettre en majuscule aux différents endroits dans le moule et renvoie son occurence.
	Rq : travail sans [].
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int tentative(char **v, int pos, char c, char **moule);
char * moule(char **v, short pos);

int main(int argc, char **argv) {
	char *mot[5] = {"armature", "chemise", "ordinateur", "rateau", "hutte"}, *v;
	int occRetour;
	v = moule(mot,0);
	printf("v : %s",v);
	occRetour = tentative(mot,0,'a',&v);
	printf("\nResultat tentative : %d",occRetour);
	printf("\nv : %s",v);
	occRetour = tentative(mot,0,'z',&v);
	printf("\nResultat tentative : %d",occRetour);
	printf("\nv : %s",v);


	return 0;
}

int tentative(char **v, int pos, char c, char **moule) {
	int i, taille = strlen(*(v+pos)), occurence = 0;
	char *tmp = *moule;

	for(i = 1; i < taille - 1; i++) {
		if(*(*(v+pos)+i) == c) {
			*(tmp+i) = c-32;
			occurence++;
		}
	}
	return occurence;
}

char * moule(char **v, short pos) {
	char *m = *(v+pos), *r = (char *) malloc(strlen(m)+1);
	short i = strlen(m);
	if(m[0] >= 'a' && m[0] <= 'z') {
		r[0] = m[0] - 32;
	} else {
		r[0] = m[0];
	}
	for(i = 1; m[i+1] != '\0'; i++) {
		r[i] = '-';
	}
	if(m[i] >= 'a' && m[i] <= 'z') {
		r[i] = m[i] - 32;
	} else {
		r[i] = m[i];
	}
	r[i+1] = '\0';
	
	return r;
}
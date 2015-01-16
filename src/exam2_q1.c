/*
	exam2_q1.c
	author : Denis Kestelier
	Question : 
	Soit un vecteur de pointeur pointant vers des mots
	Pour démarrer le jeu du pendu, fonction qui recoit ce vecteur et un entier désignant le mot avec lequel on joue et qui construit de facon dynamique
	le moule du mot à trouver. (1ere et dernière lettre en majuscules, - dans les autres).
	Note : il faut juste écrire la fonction.
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char * moule(char **v, short pos);

int main(int argc, char **argv) {
	char *mot[5] = {"armature", "chemise", "ordinateur", "rateau", "hutte"};
	char *v;
	v = moule(mot,0);
	printf("v : %s",v);

	return 0;
}

char * moule(char **v, short pos) {
	char *m = *(v+pos), *r = (char *) malloc(strlen(m)+1);
	short i;
	i = strlen(m);
	printf("i : %d",i);
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
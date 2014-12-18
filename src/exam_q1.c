/*
	exam_q1.c
	author : Denis Kestelier
	Question : 
	Fonction qui reçoit un vecteur de pointeurs pointant vers des chaînes et un caractère.
	Elle recherche la chaîne contenant le plus de fois ce caractère. Si ça existe, elle crée une structure contenant l'adresse de cette chaîne et l'occurrence du caractère.
	Rq : travail sans [ ]
*/

#include "stdio.h"
#include "stdlib.h"

struct retour {
	char *chaine;
	int cpt;
};

void rechercheChar(char **v, char c);

int main(int argc, char **argv) {
	static char *pChaine[4] = {"Albert", "Arlette", "tttt", "rtt"};
	rechercheChar(pChaine, 't');
}

void rechercheChar(char **v, char c) {
	int i, j, tmpCpt;
	struct retour retour;
	retour.cpt = 0;
	retour.chaine = NULL;
	for(i = 0; i < 4; i++) {
		j = 0;
		tmpCpt = 0;
		while(*(*(v+i)+j) != '\0') {
			printf("Char : %c\n",*(*(v+i)+j));
			if(*(*(v+i)+j) == c) {
				tmpCpt++;
			}
			j++;
		}
		if(retour.cpt < tmpCpt) {
			retour.cpt = tmpCpt;
			retour.chaine = *(v+i);
		}
	}
	printf("Occurence de %c : %d\n",c,retour.cpt);
	printf("adresse de la chaine : %d",*retour.chaine);
}
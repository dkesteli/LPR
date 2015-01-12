/*
	liste_simple.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "conio.h"
#include "string.h"

struct comp{
	short num;
	char mot[5];
};

struct liste{
	struct comp composante;
	struct liste *next;
};

int main(int argc, char **argv) {

	struct liste *debut = NULL, *tmp = NULL;
	int i;

	struct liste* nouvelElement =(struct liste*) malloc(sizeof(struct liste));
	nouvelElement->next = NULL;
	nouvelElement->composante.num = 1;
	strcpy(nouvelElement->composante.mot,"MOT 1");
	debut = nouvelElement;
	tmp = debut;
	for(i = 2; i <= 6; i++) {
		nouvelElement = (struct liste*) malloc(sizeof(struct liste));
		nouvelElement->composante.num = i;
		sprintf(nouvelElement->composante.mot,"MOT %d",i);
		nouvelElement->next = NULL;
		tmp->next = nouvelElement;
		tmp = nouvelElement;
	}
	for(tmp = debut; tmp != NULL; tmp = tmp->next) {
		printf("Composante %d\nTexte : %s\n",tmp->composante.num,tmp->composante.mot);
	}
	printf("Destruction de la chaine\n");
	tmp = debut;
	while(tmp != NULL) {
		debut = tmp->next;
		free(tmp);
		tmp = debut;
	}
	debut = NULL;
	return 0;

}
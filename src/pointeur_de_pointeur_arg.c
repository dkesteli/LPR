/*
	pointeur_de_pointeur_arg.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "ctype.h"

/*correction */
void upper(char *ligne);
void quit();
/*fin correction */

void main(int argc, char **argv) {
	FILE *fp = NULL;
	char ligne[1024], c, *fichier;
	int i, bloc = 0, m = 0, cpt = 0;
	if((argc < 2) || (argc > 4)) {
		printf("Mauvais nombre d'arguments! Usage : %s fichier [options]\n",*(argv));
		exit(1);
	}
	for(i = 1; i < argc; i++) {
		if(*(*(argv+i)) == '-') {
			c = toupper(*(*(argv+i)+1));
			if(c == 'D') {
				if(!bloc) {
					bloc = 10;
				} else {
					printf("Mauvais argument\n");
					exit(2);
				}
			} else if (c == 'Q') {
				if(!bloc) {
					bloc = 15;
				} else {
					printf("Mauvais argument\n");
					exit(2);
				}
			} else if (c == 'M') {
				if(!m) {
					m = 1;
				} else {
					printf("Mauvais argument\n");
					exit(2);
				}
			} else {
				printf("Mauvais argument\n");
				exit(2);
			}
		} else {
			if(fp) {
				printf("Mauvais argument\n");
				exit(2);
			} else {	
				fichier = *(argv+i);	
			}
		}
	}
	printf("bloc : %d, m : %d, fichier : %s\n",bloc,m,fichier);
	if((fp = fopen(fichier,"r")) != NULL) {
		while(fgets(ligne,1024,fp) != NULL) {
			/*if(bloc) {
				if(cpt < bloc) {
					cpt++;
				} else {
					cpt = 1;
					printf("Appuyer sur une touche pour continuer\n");
					getche();
				}
			}
			if(m) {
				i = 0;
				while(ligne[i] != '\0') {
					ligne[i] = toupper(ligne[i]);
					i++;
				}
			}
			printf("%3d : %s",cpt,ligne);*/
			/*correction*/
			cpt++;
			if(m) {
				upper(ligne);
			}
			printf("%3d : %s",cpt,ligne);
			if(bloc && (cpt % bloc == 0)) {
				printf("Appuyer sur une touche pour continuer\n");
				getche();
				//clrscr();
			}
		}
	} else {
		fprintf(stderr,"\nProbleme d'ouverture du fichier %s",fichier);
		exit(3);
	}
	exit(0);
}

void upper(char *ligne) {
	while(*ligne) {
		*ligne = toupper(*ligne);
		++ligne;
	}
}
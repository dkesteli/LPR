/*
	exam2_q6.c
	author : Denis Kestelier
	Question : 
	Programme qui affiche un enregistrement d'un fichier passé en ligne de commande.
	Un enregistrement se compose de : nom(20 caractères), numéro(entier 2 bytes), ville(25 caractères)
	Le programme est lancé en ligne de commande par : 
	prog fichier -m Durant (pour afficher l'enregistrement recherché selon un nom)
	prog fichier -c 2 (pour afficher l'enregistrement dont le numéro se termine par le chiffre)
	Note : -m -> recherche la première personne avec le nom
	-c -> recherche un chiffre, et qui se termine par chiffre
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "ctype.h"

struct record {
	char nom[20], ville[25];
	short num;
};

void affiche(struct record enreg);
void erreur(char *nomFichier);

int main(int argc, char **argv) {

	FILE *fp;
	struct record enreg;
	char c;
	short found = 0, num;
	if(argc != 4) {
		fprintf(stderr,"Erreur mauvais nombre d'arguments\nUsage : %s fichier [options] critere\nOptions : -c / -m",argv[0]);
		exit(1);
	}
	if((fp = fopen(argv[1],"r")) == NULL) {
		erreur(argv[1]);
		exit(2);
	}
	c = toupper(*(*(argv+2)+1));
	switch(c) {
		case 'M':
			fseek(fp,0,SEEK_SET);
			while((fread(&enreg,sizeof(struct record),1,fp)) && (!found)) {			
				if(strcmp(argv[3],enreg.nom) == 0) {
					found = 1;
					affiche(enreg);
				}
			}
			break;
		case 'C':
			num = atoi(argv[3]);
			fseek(fp,0,SEEK_SET);
			while((fread(&enreg,sizeof(struct record),1,fp)) && (!found)) {			
				if((enreg.num % 10) == num) {
					found = 1;
					affiche(enreg);
				}
			}
			break;
		default :
			printf("Erreur");
			exit(1);
	}	

	return 0;
}

void affiche(struct record enreg) {
	printf("Numero : %hd\n",enreg.num);
	printf("Nom : %s\n",enreg.nom);
	printf("Ville : %s\n",enreg.ville);
}

void erreur(char *nomFichier) {
	printf("\nProbleme d'ouverture du fichier %s",nomFichier);
	exit(3);
}
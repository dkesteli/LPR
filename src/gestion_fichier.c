/*
	gestion_fichier.c
	author : Denis Kestelier
	Description : programme qui permet de créer un ficier, le lire, de créer des enregistrements depuis une structure.
	Usage : gestion_fichier nomFichier
	
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

struct record {
	char nom[20], ville[25];
	short num;
};

void lireFichier(FILE *fp);
void ecrireEnreg(FILE *fp);
void affiche(struct record enreg);
void erreur(char *nomFichier);
char menu();

int main(int argc, char **argv) {
	FILE *fp;
	char c;
	if(argc != 2) {
		fprintf(stderr,"Erreur! mauvais nombre d'arguments\n");
		fprintf(stderr,"Usage : %s nomFichier\n",argv[0]);
		exit(1);
	}
	if((fp = fopen(argv[1],"w+")) == NULL) {
		erreur(argv[1]);
		exit(3);
	}
	while((c = menu()) != '0') {
		putchar('\n');
		switch(c) {
			case '1':
				lireFichier(fp);
				break;
			case '2':
				ecrireEnreg(fp);
				break;
			default :
				printf("Mauvaise option\n");
		}
	}
	fclose(fp);
	return 0;
}

void lireFichier(FILE *fp) {
	struct record enreg;
	fseek(fp,0,SEEK_SET);
	while(fread(&enreg,sizeof(struct record),1,fp)) {
		affiche(enreg);
	}
}

void ecrireEnreg(FILE *fp) {
	struct record enreg;
	printf("Nom : ");
	scanf("%s",enreg.nom);
	printf("Ville : ");
	scanf("%s",enreg.ville);
	printf("Numero : ");
	scanf("%hd",&enreg.num);
	fwrite(&enreg,sizeof(struct record),1,fp);
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

char menu() {
	printf("1 : Lire le fichier\n");
	printf("2 : Ecrire un enregistrement\n");
	printf("0 : Quitter\n");
	printf("Choix : ");
	return getche();
}
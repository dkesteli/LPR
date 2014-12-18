/*
	struct_fichier.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "ctype.h"

struct cheque{
	int num, jour, mois, annee;
	char beneficiaire[21];
	double montant;
};

void erreur(char *nomFichier);
void affiche(struct cheque cheque);
void remplir(struct cheque *pcheque, int num);
void initFile(struct cheque input);
void menu();

void main(int argc, char **argv) {

	FILE *outfile;
	struct cheque input;
	char c, cClient;
	int i,numClient;
	if(argc != 2) {
		printf("Erreur! Usage : %s fichier",*argv);
		exit(1);
	}

	if((outfile = fopen(*(argv+1),"r+b")) == NULL) {
		erreur(*(argv+1));
		exit(3);
	}
	/*init file*/
	input.num = 0;
	input.jour = 0;
	input.mois = 0;
	input.annee = 0;
	strcpy(input.beneficiaire,"");
	input.montant = 0.0;
	for(i = 0; i < 50; i++) {
		fwrite(&input,sizeof(struct cheque),1,outfile);
	}
	/*fin init*/
	printf("Entrez un numero de client: ");
	while((cClient = getche()) != '0') {
		numClient = cClient - 48;
		putchar('\n');
		menu();
		while((c = getche()) != '0') {
			putchar('\n');
			switch(c) {	
				case '1': 
					fseek(outfile,(numClient-1)*sizeof(struct cheque)*10,SEEK_SET);
					i = 0;
					while((i < 10) && (fread(&input,sizeof(struct cheque),1,outfile)) && (input.num != 0)) {
						i++;
					}
					if(i != 10) {
						/*Probleme d'ecriture dans le fichier si pas de fseek apres fread qui n'est pas arrive a EOF*/
						fseek(outfile,-1*(sizeof(struct cheque)),SEEK_CUR);
						remplir(&input,i+1);
						if(fwrite(&input,sizeof(struct cheque),1,outfile)) {
							printf("Cheque encode!\n");
						} else {
							printf("Probleme lors de l'encodage\n");
						}
					}
					break;
				case '2': 
					printf("Affichage des cheque du client %d\n",numClient);
					fseek(outfile,(numClient-1)*sizeof(struct cheque)*10,SEEK_SET);
					i = 0;
					while((i < 10) && fread(&input,sizeof(struct cheque),1,outfile) && (input.num != 0)) {
						affiche(input);
						i++;
					}
					if(i == 0) {
						printf("Pas de cheque pour ce client\n");
					}
					break;
				case '3': 
					printf("Remise a 0 du chequier du client %d\n",numClient);
					fseek(outfile,(numClient-1)*sizeof(struct cheque)*10,SEEK_SET);
					input.num = 0;
					input.jour = 0;
					input.mois = 0;
					input.annee = 0;
					strcpy(input.beneficiaire,"");
					input.montant = 0.0;
					for(i = 0; i < 10; i++) {
						fwrite(&input,sizeof(struct cheque),1,outfile);
					}
					break;
				case '4':  printf("Affichage de tous les cheques\n");
					fseek(outfile,0,SEEK_SET);
					while(fread(&input,sizeof(struct cheque),1,outfile)) {
						affiche(input);
					}
					break;
				default: menu();
					break;
			}
			menu();
		}
		printf("\nEntrez un numero de client: ");
	}
	fclose(outfile);
	exit(0);
}

void affiche(struct cheque cheque) {
	printf("Numero : %d\nDate : %d/%d/%d\nBeneficiaire : %s\nMontant : %.2f\n",cheque.num,cheque.jour,cheque.mois,cheque.annee,cheque.beneficiaire,cheque.montant);
}

void remplir(struct cheque *pcheque, int num) {
	pcheque->num = num;
	printf("Entrez une date (jj/mm/aaaa)\n");
	scanf("%d %d %d",&pcheque->jour,&pcheque->mois,&pcheque->annee);
	printf("Entrez un beneficiaire\n");
	scanf("%s",pcheque->beneficiaire);
	printf("Entrez un montant\n");
	scanf("%lf",&pcheque->montant);
}

void menu() {
	printf("1 : Nouveau cheque\n");
	printf("2 : Voir les cheques\n");
	printf("3 : Nouveau carnet\n");
	printf("0 : Quitter\n");
	printf("Choix ? ");
}


void erreur(char *nomFichier) {
	printf("\nProbleme d'ouverture du fichier %s",nomFichier);
	exit(3);
}
/*
	struct.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "ctype.h"

struct cheque{
	int num, jour, mois, annee;
	char beneficiaire[21];
	double montant;
};
void affiche(struct cheque cheque);
void remplir(struct cheque *pcheque, int num);

void main(int argc, char **argv) {
	struct cheque cheque1, cheque2, vCheque[25];
	char c;
	int nbCheque = 0, i;
	/*remplir(&cheque1,1);
	remplir(&cheque2,2);
	affiche(cheque1);
	affiche(cheque2);*/
	printf("(A)jout\n(V)oir\n(Q)uitter\nChoix : ");
	putchar('\n');
	while((c = toupper(getche())) != 'Q') {
		switch(c) {
			case 'A' :
				if(nbCheque < 25) {
					remplir(vCheque+nbCheque,nbCheque+1); /*&vCheque[nbCheque]*/
					nbCheque++;
				} else {
					printf("Impossible d'ajouter de nouveaux cheques!");
				}
				break;
			case 'V' : 
				if(nbCheque != 0) {
					for(i = 0; i < nbCheque; i++) {
						affiche(*(vCheque+i)); /*vCheque[i]*/
					}
				} else {
					printf("Pas de cheque encode!\n");
				}
				break;
			case 'Q' : 
				break;
		}
		printf("(A)jout\n(V)oir\n(Q)uitter\nChoix : ");
		putchar('\n');
	}
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
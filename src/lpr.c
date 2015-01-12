
/*
 * lpr.c
 *
 *  Created on: 15-sept.-2014
 *      Author: Denis
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

char minToMaj(char c);
void equation();
void affiche_table_ascii();
void affiche_decimal_hexa();
void corr_affiche_decimal_hexa();
void devine_nombre();
void devine_nombre_v2();
void pyramide();
void affiche_menu(int nb1, int nb2);
void armstrong();
int carre(int n);
int cube(int n);
void addition_soustraction();
void calculatrice();
void affiche_vecteur(short v[], short taille);
void permute_vecteur(short v[], short taille);
void fonction_vecteur();
void swap_entier(short *p1, short *p2);
void permute_vecteur_v2(short *p, short taille);
void permute_vecteur_v2(short *p, short taille);
void fonction_vecteur_v2();

int main() {

	/*equation();*/
	/*affiche_table_ascii();*/
	/*affiche_decimal_hexa();
	corr_affiche_decimal_hexa();*/
	/*devine_nombre();*/
	/*devine_nombre_v2();*/
	/*pyramide();*/
	/*armstrong();*/
	/*addition_soustraction();*/
	/*calculatrice();*/
	/*fonction_vecteur();*/
	fonction_vecteur_v2();
	return 0;
}
/*Exercice 2 15/09/2014 */
void equation() {
	int a, b, c, delta;
	float solution1, solution2;
	printf("\nEntrez 3 nombres pour une équation :");
	scanf("%d %d %d", &a, &b, &c);
	if (a != 0) {
		printf("\nEquation : %dx² + %dx + %d = 0", a,b,c);

		delta = (b*b) - 4*a*c;
		printf("\nDelta : %d", delta);
		if (delta > 0) {
			solution1 = (-b + sqrt(delta)) / (2*a);
			solution2 = (-(float)b - sqrt(delta)) / (2*a);
			printf("\nSolution 1 : %.2f Solution 2 : %.2f", solution1, solution2);
		} else if (delta == 0) {
			printf("\nSolution x = %f", -(float)b/(2*a));

		} else {
			printf("\nPas de solution");
		}
	} else {
		printf("\nDivision par zero impossible");
	}
}
/*Exercice 3 15/09/2014 */
void affiche_table_ascii() {
	int i = 0;
	for (; i < 32; ++i) {
		printf("\nDecimal : %03d, octal : %03x, hexa : %02x, ASCII : \'ctrl\'", i, i, i);
	}
	for (; i < 256; ++i) {
		printf("\nDecimal : %03d, octal : %03x, hexa : %02x, ASCII : \'%c\'", i, i, i, i);
	}

}
/*Exercice 4 15/09/2014 */
void affiche_decimal_hexa () {
	int nombre = 0, i = 0;
	char c;
	printf("\nEntrez un nombre en binaire : ");
	do {
		c = getche();
		if(c == 49) {
			nombre <<=1; /*décalage vers la gauche = nombre*2 */
			nombre +=1;
		} else if (c == 48) {
			nombre <<=1;
		}
		i++;
	} while (i < 16 && (c == 48 || c == 49));
	printf("\nCe nombre vaut %d en decimal ou %x en hexa", nombre, nombre);
}
/*Correction Exercice 4 */
void corr_affiche_decimal_hexa() {
	long nombre = 0, i = 0;
	char c;
	printf("\nEntrez un nombre en binaire : ");
	while ((i++ < 16) && (((c=getche()) == '0') || (c == '1'))) {
		nombre = nombre<<1 | (c - 48);
	}
	printf("\nCe nombre vaut %d en decimal ou %x en hexa", nombre, nombre);
}
/*Exercice 5 15/09/2014 */
void devine_nombre() {
	char c;
	int nombre = 8, pas = 4;
	printf("\nTentative pour trouver a quel nombre vous pensez");
	printf("\nEntrez : h pour trop haut, b pour trop bas, e pour exact, s pour stop");
	printf("\nEst-ce %d?", nombre);
	do {
		c = getche();
		switch(c) {
			case 'h':
			case 'H':
				nombre -= pas;
				printf("\nEst-ce %d", nombre);
				pas /= 2;
				break;
			case 'b':
			case 'B':
				nombre += pas;
				printf("\nEst-ce %d", nombre);
				pas /= 2;
				break;
			case 'e':
			case 's':
				break;
			default :
				printf("\nMauvais caractere!\nEst-ce %d?", nombre);
		}
	} while ((pas >= 1) && (c != 'e') && (c != 's'));
	printf("\nVotre nombre est : %d", nombre);
}

void devine_nombre_v2() {

	char c;
	int nombre = 8, pas = 4, cpt = 1;
	printf("\nTentative pour trouver a quel nombre vous pensez");
	printf("\nEntrez : (h/H) pour trop haut, (b/B) pour trop bas, (e/E) pour exact, (s/S) pour stop");
	printf("\nEst-ce %d? ", nombre);
	while (((c=minToMaj(getche())) != 'E') && (c != 'S')) {

		switch(c) {
			case 'H':
				nombre -= pas;
				printf("\nEst-ce %d? ", nombre);
				pas /= 2;
				cpt++;
				break;
			case 'B':
				nombre += pas;
				printf("\nEst-ce %d? ", nombre);
				pas /= 2;
				cpt++;
				break;
			case 'E':
			case 'S':
				break;
			default :
				printf("\nMauvais caractere!\nEst-ce %d? ", nombre);
		}
	}
	if (c == 'E') {
		printf("\nVotre nombre est : %d\nTrouve en %d coups", nombre, cpt);
	}
}

char minToMaj(char c) {
	/*if (c >= 'a' && c <= 'z') {
		return (c-32);
	} else {
		return (c);
	}
	return ((c>='a') && (c <= 'z')? c&0xDF:c);
	return (islower(c) ? c - 32 : c*/
	return ((c>='a') && (c <= 'z')? c-32:c);
}
/*Exercice pyramide 18/09/2014*/
void pyramide(){
	int nbLignes = 10;
	int i,j,k,valeurAffichage = 0;

	for (i = 1; i <= nbLignes; i++) {
		for(j = 0; j < nbLignes - i; j++) {
			printf(" ");
		}
		for (k = 0; k <= i-1; k++) {
			valeurAffichage = k+i;
			printf("%d",(valeurAffichage%10));
		}
		for (k = 0; k < i-1; k++) {
			valeurAffichage--;
			printf("%d",(valeurAffichage%10));
		}
		printf("\n");
	}
}

int carre(int n) {
	return (n*n);
}

int cube(int n) {
	return (n*carre(n));
}

void armstrong() {
	int i, limite = 1000, nombre, reste, armstrong = 0;
	for(i = 1; i < limite; i++) {
		nombre = i;
		while (nombre != 0) {
			reste = nombre % 10;
			nombre /= 10;
			armstrong += cube(reste);
		}
		if (armstrong == i) {
			printf("\n%d est un nombre d'Armstrong",armstrong);
		}
		armstrong = 0;
	}
}

int entrer_entier() {
	int nombre = 0;
	char c;
	while (((c=getche()) >= '0') && (c <= '9')) {
		nombre *= 10;
		nombre += (c-48);
	}
	return ((c == '\r') ? nombre : 0);
}

void affiche_menu(int nb1, int nb2) {
	printf("\nMenu");
	printf("\n1. Addition de %d et %d", nb1, nb2);
	printf("\n2. Soustraction de %d et %d", nb1, nb2);
	printf("\n3. Soustraction de %d et %d", nb2, nb1);
	printf("\nChoix? ");
}
/*Exercice 25/09/14*/
void addition_soustraction() {
	int nb1, nb2;
	char choix;
	printf("\nEntrez deux nombres :\n");
	if((nb1 = entrer_entier()) && (nb2 = entrer_entier())) {
		affiche_menu(nb1,nb2);
		while((choix=getche()) < '1' && (choix > '3')) {
			printf("\nChoix : 1, 2 ou 3");
		}
		switch(choix) {
			case '1' :
				printf("\nSomme de %d et %d : %d",nb1,nb2, nb1 + nb2);
				break;
			case '2' :
				printf("\nSoustraction de %d et %d : %d",nb1,nb2, nb1 - nb2);
				break;
			case '3' :
				printf("\nSoustraction de %d et %d : %d",nb2,nb1, nb2 - nb1);
				break;
		}
	} else {
		printf("\nEntier pas correct!");
	}
}

/*Exercice 1 Calculatrice Notation polonaise inversée 29/09/2014*/
void calculatrice() {
	short tab[20], i = 0, nb = 0;
	char c, ok = 1;
	printf("\nEntrez un nombre (s ou S pour arreter)\n");
	while(ok && ((c=minToMaj(getche())) != 'S')) {
		if(c == 'I') {
			if(i != 0) {
				printf("\nDernier élément : tab[%d] =  %d \n",i-1,tab[i-1]);
			} else {
				printf("\nCalculatrice vide!");
				ok = 0;
			}
		} else if((c >= '0') && (c <= '9')) { /*isdigit(c)*/
			nb = nb * 10 + c - 48;
		} else if (c == '\r') {
			putchar('\n'); /*affiche un et un seul caractere, plus rapide que printf*/
			if (nb != 0){
				tab[i] = nb;
				nb = 0;
				i++;
			}
		} else if (c == '+') {
			if(i > 1) {
				tab[i-2] += tab[i-1];
				i--;
			} else {
				ok = 0;
			}
		}
		else {
			printf("\nImpossible");
		}
	}
}

/*Exercice permutation vecteur 29/09/2014*/
void affiche_vecteur(short v[], short taille) {
	short i;
	printf("\nVecteur : ");
	for(i = 0; i < taille -1; i++) {
		printf("%d, ",v[i]);
	}
	printf("%d\n",v[i]);
}

void permute_vecteur(short v[], short taille) {
	int i, j = taille-1, tmp;
	for(i = 0; i < taille/2; i++) {
		tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
		j--;
	}
}

void fonction_vecteur() {
	int i;
	static short v[7];
	printf("\nFonction vecteur, Remplissez le vecteur\n");
	for(i = 0; i < 7; i++) {
		v[i] = entrer_entier();
	}
	printf("\nAvant permutation\n");
	affiche_vecteur(v,7);
	permute_vecteur(v,7);
	printf("\nApres permutation\n");
	affiche_vecteur(v,7);
}
/*Exercice pointeur 02/10/2014*/
void swap_entier(short *p1, short *p2) {
	short tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void affiche_vecteur_v2(short *p, short taille) {
	short i;
	for(i = 0; i < taille; i++) {
		printf("%d ",*p++);
	}
}

void permute_vecteur_v2(short *p, short taille) {
	short *p2 = p + taille-1, tmp, i;
	/*v1 et v2
	for(i = 0; i < taille/2; i++) {
		v1
		tmp = *p;
		*p = *p2;
		*p2 = tmp;
		p++;
		p2--;
		v2
		swap_entier(p++,p2--);
	}
	/*v3*/
	while(p < p2) {
		swap_entier(p++,p2--);
	}
}

void fonction_vecteur_v2() {
	int i;
	static short v[7];
	printf("\nFonction vecteur, Remplissez le vecteur\n");
	for(i = 0; i < 7; i++) {
		v[i] = entrer_entier();
	}
	printf("\nAvant permutation\n");
	affiche_vecteur(v,7);
	permute_vecteur(v,7);
	printf("\nApres permutation\n");
	affiche_vecteur(v,7);
}

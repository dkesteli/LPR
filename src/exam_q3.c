/*
	exam_q3.c
	author : Denis Kestelier
	Question : 
	Fonction qui reçoit une table à 4 dimensions de maximum 10 x 20 x 30 x 40 entiers de 2 bytes.
	Elle affiche la somme des éléments de chaque table à 3 dimensions qu'elle contient.
	Le calcul de chaque table à 3 dimensions se fait en appelant une fonction qui calcule la somme des éléments d'une table à 2dimensions, 
	qui elle-même appelle une fonction qui calcule la somme des éléments d'une table à 1 dimension.
*/

#include "stdio.h"
#include "stdlib.h"

int sommeMat1Dim(int tab[], int colonne);
int sommeMat2Dim(int tab[][40], int ligne, int colonne);
int sommeMat3Dim(int tab[][30][40], int plan, int ligne, int colonne);
void sommeMat4Dim(int tab[][20][30][40], int dim4, int plan, int ligne, int colonne);
void affiche(int m[][20][30][40], int dim4, int plan, int ligne, int colonne);

void main(int argc, char *argv[]) {
	int tab[10][20][30][40], i, j, k, l, dim4 = 2, plan = 2, ligne = 2, colonne = 4, cpt = 1;
	
	for(i = 0; i < dim4; i++) {
		for(j = 0; j < plan; j++) {
			for(k = 0; k < ligne; k ++) {
				for(l = 0; l < colonne; l++) {
					tab[i][j][k][l] = cpt++;
				}
			}
		}
	}
	affiche(tab,dim4,plan,ligne,colonne);
	sommeMat4Dim(tab,dim4,plan,ligne,colonne);
	exit(0);
}

int sommeMat1Dim(int tab[], int taille) {
	int i,somme = 0;
	for(i = 0; i < taille; i++) {
		somme+= tab[i];
	}

	return (somme);
}

int sommeMat2Dim(int tab[][40], int ligne, int colonne) {
	int i,somme = 0;
	for(i = 0; i < ligne; i++) {
		somme += sommeMat1Dim(tab[i], colonne);
	}
	return (somme);
}

int sommeMat3Dim(int tab[][30][40], int plan, int ligne, int colonne) {
	int i, somme = 0;
	for(i = 0; i < plan; i++) {
		somme += sommeMat2Dim(tab[i], ligne, colonne);
	}
	return somme;
}

void sommeMat4Dim(int tab[][20][30][40], int dim4, int plan, int ligne, int colonne) {
	int i;
	for(i = 0; i < dim4; i++) {
		printf("Somme des tables a 3 dimensions de la dimension %d : %d\n",i+1,sommeMat3Dim(tab[i],plan,ligne,colonne));
	}
}

void affiche(int m[][20][30][40], int dim4, int plan, int ligne, int colonne) {
	int i, j, k, l;
	for(l = 0; l < dim4; l++) {
		for(i = 0; i < plan; i++) {
			printf("Plan : %d\n",i);
			for(j = 0; j < ligne; j++) {
				for(k = 0; k < colonne; k++) {
					printf("%d ", m[l][i][j][k]);
				}
				printf("\n");
			}
		}
	}
}


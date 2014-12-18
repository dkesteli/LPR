/*
	table_n_dimensions.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

void affiche(int m[][20][20], int plan, int ligne, int colonne);
void remplirMatrice(int m[][20], int ligne, int colonne);
void decalePlan(int m[][20][20], int plan, int ligne, int colonne);
void decaleLigne(int m[][20], int ligne, int colonne);
void decaleVecteur(int m[], int colonne);

void main(int argc, char *argv[]) {

	int plan, ligne, colonne,i, j;
	int m[20][20][20];
	printf("Entrez le nombre de plan : ");
	scanf("%d", &plan);
	printf("Entrez le nombre de ligne : ");
	scanf("%d", &ligne);
	printf("Entrez le nombre de colonne : ");
	scanf("%d", &colonne);
	for(i = 0; i < plan; i++) {
		remplirMatrice(m[i],ligne,colonne);
	}
	printf("Initialisation : \n");
	affiche(m,plan,ligne,colonne);
	decalePlan(m,plan,ligne,colonne);
	printf("Apres decalage plan : \n");
	affiche(m,plan,ligne,colonne);
	for(i = 0; i < plan; i++) {
		remplirMatrice(m[i],ligne,colonne);
	}
	printf("Apres reinitialisation : \n");
	affiche(m,plan,ligne,colonne);
	printf("Decalage ligne : \n");
	for(i = 0; i < plan; i++) {
		decaleLigne(m[i],ligne,colonne);
	}
	printf("Apres decalage ligne : \n");
	affiche(m,plan,ligne,colonne);
	for(i = 0; i < plan; i++) {
		remplirMatrice(m[i],ligne,colonne);
	}
	printf("Apres reinitialisation : \n");
	affiche(m,plan,ligne,colonne);
	printf("Decalage vecteur : \n");
	for(i = 0; i < plan; i++) {
		for(j = 0; j < ligne; j++) {
			decaleVecteur(m[i][j],colonne);
		}
	}
	printf("Apres decalage vecteur : \n");
	affiche(m,plan,ligne,colonne);
	exit(0);
}

void affiche(int m[][20][20], int plan, int ligne, int colonne) {
	int i, j,k;
	for(i = 0; i < plan; i++) {
		printf("Plan : %d\n",i);
		for(j = 0; j < ligne; j++) {
			for(k = 0; k < colonne; k++) {
				printf("%d ", m[i][j][k]);
			}
			printf("\n");
		}
	}
}

void remplirMatrice(int m[][20], int ligne, int colonne) {
	static int cpt = 1;
	int i, j;
	for(i = 0; i < ligne; i++) {
		for(j = 0; j < colonne; j++) {
			m[i][j] = cpt++;
		}
	}
}

void decalePlan(int m[][20][20], int plan, int ligne, int colonne) {
	int i, j, k, tmp;
	for(i = 0; i < ligne; i++) {
		for(j = 0; j < colonne; j++) {
			tmp = m[plan-1][i][j];
			for(k = plan-1; k > 0; k--) {
				m[k][i][j] = m[k-1][i][j];
			}
			m[k][i][j] = tmp;
		}
	}
}

void decaleLigne(int m[][20], int ligne, int colonne) {
	int i, j, tmp;
	for(i = 0; i < colonne; i++) {
		tmp = m[ligne-1][i];
		for(j = ligne-1; j > 0; j--) {
			m[j][i] = m[j-1][i];
		}
		m[j][i] = tmp;
	}
}

void decaleVecteur(int m[20], int colonne) {
	int i, tmp;
	tmp = m[colonne-1];
	for(i = colonne-1; i > 0; i--) {
		m[i] = m[i-1];
	}
	m[i] = tmp;
}
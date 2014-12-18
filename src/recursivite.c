/*
	recursivite.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"

int factorielle(int n);
int pgcd(int a, int b);
int pgcdv2(int a, int b);
int fibonacci(int n);
int combinaison(int n, int p);

int main(int argc, char *argv[]) {
	int n = 6, i, j, max = 0;
	if(argc == 2) {
		if((max = atoi(argv[1]) <= 0) && (max > 10)) {
			fprintf(stderr, "\nMauvais nombre");
		}
		fprintf(stdout,"%s",argv[1]);
		fprintf(stdout,"\nTriangle de : %d",max);
		fprintf(stdout,"max : %d\n",max);
		for(i = 0; i <= max; i++) {
			for(j = 0; j <= i; j++) {
				fprintf(stdout, "%d ",combinaison(j,i));
			}
			putchar('\n');
		}
	} else if(argc == 1) {
		fprintf(stdout,"\nFactorielle de %d : %d",n,factorielle(n));
		fprintf(stdout,"\nFibonnaci de %d : %d",n,fibonacci(n));
		fprintf(stdout,"\nPGCD de 1111 et 297 : %d",pgcd(1111,297));
		fprintf(stdout,"\nPGCDV2 de 1111 et 297 : %d",pgcdv2(1111,297));
	} else {
		fprintf(stderr, "Mauvais nombre d'arguments! Usage : %s [entier]",argv[0]);
		exit(1);
	}
	exit(0);

}

int factorielle(int n) {
	return (n ? n*factorielle(n-1) : 1);
}

int pgcd(int a, int b) {
	return(a%b == 0 ? b : pgcd(b,a%b));
}

int pgcdv2(int a, int b) {
	if(b > a) {
		return (pgcdv2(a, b-a));
	}
	if(a > b) {
		return (pgcdv2(a-b,b));
	}
	return a;
	/*correction : 
	if(a > b) {
		return (pgcdv2(a-b,b));
	} else {
		return (a<b ? pgcdv2(a,b-a) : a);
	}*/
}

int fibonacci(int n){
  return(n < 2 ? n : (fibonacci(n-1) + fibonacci(n-2)));
}

int combinaison(int i, int j) {
	return ((i == 0) || (i == j) ? 1 : (combinaison(i,j-1) + combinaison(i-1, j-1)));
}
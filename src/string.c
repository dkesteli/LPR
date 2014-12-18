/*
 * string.c
 *
 *  Created on: 06/10/2014
 *      Author: Denis
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

void getS(char *ch, int taille);
void putS(char *ch);
void strCpy(char *ch2,char *ch1);
void strCat(char *ch2,char *ch1);
int strLen(char *ch);
int strCmp(char *ch1,char *ch2);

int main() {
	static char message[20] = "Salut";
	static char ch2[] = "hello";
	static char ch1[] = "hi";
	printf("\nEntrez un message\n");
	getS(message,25);
	printf("\nAffichage message : ");
	putS(message);
	strCpy(ch2,ch1);
	printf("\nAffichage message apres copy de hi dans hello: ");
	putS(ch2);
	printf("%d",strLen("Plop8"));
	printf("\nstrCmp1 : %d",strCmp("plop","plop"));
	printf("\nstrCmp2 : %d",strCmp("ABCD","ABEFG"));
	printf("\nstrCmp3 : %d",strCmp("plop","plo"));
	printf("\nstrCat : ");
	strCat(message," Denis");
	putS(message);
}

void getS(char *ch, int taille) {
	int cpt = 0;
	while((cpt < taille-1) && (*ch=getche()) != '\r') {
		if(!iscntrl(*ch)) {
			cpt++;
			ch++;
		} else if(*ch == '\b') {
			cpt--;
			ch--;
		}
	}
	*ch = '\0';
}

void putS(char *ch) {
	while(*ch != '\0') {
		putchar(*ch++);
	}
	putchar('\n');
}

void strCpy(char *ch2, char *ch1) {
	while(*ch1 != '\0') {
		*ch2++ = *ch1++;
	}
	*ch2++ = '\0';
	/*Correction
		while(*ch2++ = *ch1++);
	*/
}

void strCat(char *ch2, char *ch1) {
	while(*ch2 != '\0') {
		ch2++;
	}
	while(*ch1 != '\0') {
		*ch2++ = *ch1++;
	}
	*ch2++ = '\0';
}

int strLen(char *ch) {
	int cpt = 0;
	while(*ch != '\0') {
		cpt++;
		ch++;
	}
	return (cpt);
}

int strCmp(char *ch1, char *ch2) {
	int res = 0;
	while((!(res = *ch1 - *ch2)) && (*ch1 != '\0') && (*ch2 != '\0')) {
		ch1++;
		ch2++;
	}
	return res;
	/*Correction
		while((*ch1 == *ch2) && (*ch1)) {
			ch1++;
			ch2++;
		}
		return (*ch1 - *ch2);*/
}

char *strChr(char *message, char c) {
	while((*message) && (*message != c)) {
		*message++;
	}
	return (*message == c ? message : NULL);
}
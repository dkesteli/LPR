/*
	pointeurs.c
	author : Denis Kestelier
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void f1(char *ch);
void f2(char *ch);
void f3(char *ch);
void f4(char *ch);
void f5(char *ch);
void f6(char *ch);
void f7(char *ch);
void f8(char *ch);
void f9(char *ch);

void main(int argc, char *argv[]) {

	char mess[10];
	strcpy(mess,"Bob");
	f1(mess);
	f2(mess);
	f3(mess);
	f4(mess);
	f5(mess);
	f6(mess);
	f7(mess);
	f8(mess);
	f9(mess);
}

void f1(char *ch) {
	printf("%c",*ch++); /*affiche : 'B'*/
	putchar(*ch); /*affiche : 'o'*/
}

void f2(char *ch) {
	putchar(*++ch); /*affiche : 'o'*/
	putchar(*ch); /*affiche : 'o'*/
}

void f3(char *ch) {
	putchar(*(ch++)); /*affiche : 'B' parenthèses servent a rien*/
	putchar(*ch); /*affiche : 'o'*/
}

void f4(char *ch) {
	putchar(*(++ch)); /*affiche : 'o' parenthèses servent à rien*/
	putchar(*ch); /*affiche : 'o'*/
}

void f5(char *ch) {
	putchar((*ch)++); /*affiche : 'B' et le modifie pour passer à C*/
	putchar(*ch); /*affiche : 'C'*/
}

void f6(char *ch) {
	putchar(++(*ch)); /*affiche : 'D'*/
	putchar(*ch); /*affiche : 'D'*/
}

void f7(char *ch) {
	putchar(++(*ch++)); /*affiche : 'E'*/
	putchar(++(*ch)); /*affiche : 'p'*/
}

void f8(char *ch) {
	putchar((*ch++)++); /*affiche : 'E' et ensuite met F à la place de E*/
	putchar(*ch); /*affiche : 'p'*/
	putchar(*ch-1); /*affiche : 'o' effectue le calcul mais ne le change pas en mémoire centrale*/
	putchar((*ch-1)); /*affiche : 'o'*/
	putchar(*(ch-1)); /*affiche : 'F'*/
	putchar(++(*ch)); /*affiche : 'q' le pointeur ne bouge pas de place*/
	putchar((*ch)++); /*affiche : 'q' et le modifie pour passer à r*/
}

void f9(char *ch) {
	printf("%s",ch++); /*affiche : Frb*/
	puts(++ch); /*affiche : b*/
}
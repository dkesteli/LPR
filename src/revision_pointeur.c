/*
	revision_pointeur.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "ctype.h"

void f(char **ch);

void main(int argc, char **argv) {
	static char *mes[] = {"Jean", "Lundi", "Bob", "Vendredi", "Marie"};
	f(mes);

}

void f(char **ch) {
	printf("%c ",**ch); /*affiche J*/
	printf("%c ",**(ch+1)); /*affiche L*/
	printf("%c ",*(*ch+1)); /*affiche e*/
	printf("%c ",**ch+1); /*affiche K*/
	++ch;
	printf("%c ",**(++ch)); /*affiche B*/
	printf("%c ",**(++ch+1)); /*affiche M*/
	printf("%c ",*(*(ch+1))); /*affiche M*/
	printf("%c ",**((ch--)+1)); /*affiche M*/
	printf("%c ",*(*ch+1)); /*affiche o*/
	printf("%c ",**(ch++)+1); /*affiche C*/
	printf("%c ",**(ch+1)); /*affiche M*/

	printf("%s", *ch); /*affiche Vendredi*/
	printf("%s ",*ch+1); /*affiche endredi*/
	printf("%s ",*(ch+1)); /*affiche Marie*/

	printf("%c ",*(*(ch+1)+1)+1); /*affiche b (du a de Marie)*/
}
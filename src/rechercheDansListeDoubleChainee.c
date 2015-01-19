/*
 ============================================================================
  8 Soit une list doublement chainee d'elements comprenats
	une chaine de 25 characters
	un numero entier de 2 bits.
	-> ecrire une fonction qui renvoi l'adresse d'un element en passant sa posiotion dans la
	chaine (positive apartir du debut ,negatif � partir de la fin)
  
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct obj{
	char nom[25];
	short num;
	struct obj *next;
	struct obj *prev;
};

struct obj *adresse(struct obj *deb,struct obj *fin,short pos);

int main(void) {
	struct obj *debut, *fin, *tmp; //creation d'une liste doublement chain�e
	struct obj un, deux,trois; //cr�ation de 3 structures
	strcpy( un.nom , "willian" ); //initialisation des don�es
	strcpy( deux.nom , "007" );
	strcpy( trois.nom , "Dehaineau" );
	un.num=11223;
	deux.num=2789;
	trois.num=335;
	un.next=&deux;// on cr�e un doublement chain�e
	deux.next=&trois;
	trois.next=NULL;
	un.prev=NULL;
	deux.prev=&un;
	trois.prev=&deux;
	debut=&un;
	fin=&trois;

	tmp = adresse(debut,fin,1);
	printf("Adresse de l'element : %d",tmp);
	printf("\n\n\n");
	system("pause");
}
struct obj *adresse(struct obj *deb,struct obj *fin,short pos){

	struct obj  *tmp;
	tmp=NULL;
	short cpt=0;
		if (pos>0){
			 tmp=deb;
			    /* Tant que l'on n'est pas au bout de la liste */
			    while(tmp != NULL)
			    {
			    	cpt++;
			        if(cpt == pos)
			        {
			        	printf("\n%s ",tmp->nom);
			        	printf("%d ",tmp->num);
			            /* Si l'�l�ment a la valeur recherch�e, on renvoie son adresse */
			            return tmp;
			        }
			        tmp = tmp->next;
			    }
		}
		else if (pos<0){
			tmp=fin;
			while(tmp != NULL){
				cpt--;
				if(cpt == pos){
					printf("\n%s ",tmp->nom);
					printf("%d ",tmp->num);
					/* Si l'�l�ment a la valeur recherch�e, on renvoie son adresse */
					return tmp;

				}
				tmp = tmp->prev;
			}
		}
return tmp; // si element pas trouv� on renvoi un pointeur null
}

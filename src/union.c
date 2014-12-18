/*
	union.c
	author : Denis Kestelier
*/

#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

union nombre {
	short s;
	float f;
};
void erreur(char *nomFichier);

void main(int argc, char **argv) {
	
	FILE *outfile, *infileShort, *infileFloat;
	union nombre n;
	char option;
	/*short i,sh = 0;
	float fl = 0.5;*/
	if((argc != 3) || (*(*(argv+1)+1) != '\0')) {
		printf("Erreur : %s [option] fichier\n",*argv);
		printf("Options : f (float) / s (short)");
		exit(2);
	}

	if((outfile = fopen(*(argv+2),"r")) == NULL) {
		erreur(*(argv+2));
	}
	/*if((infileShort = fopen("_shortNumber","w")) == NULL) {
		erreur("_shortNumber");
	}
	if((infileFloat = fopen("_FloatNumber","w")) == NULL) {
		erreur("_FloatNumber");
	}
	for(i = 0; i < 20; i++) {
		//fwrite(&sh,sizeof(short),1,infileShort);
		fwrite(&fl,sizeof(float),1,infileFloat);
		sh++;
		fl += 1;
	}*/
	option = toupper(*(*(argv+1)));
	switch(option) {
		case 'S':
			while(fread(&n.s,sizeof(short),1,outfile)) {
				printf("Nombre : %d\n",n.s);
			}
			break;
		case 'F':
			while(fread(&n.f,sizeof(float),1,outfile)) {
				printf("Nombre : %.2f\n",n.f);
			}
			break;
		default:
			fprintf(stderr,"Mauvaise option");
			exit(1);
	}
	fclose(outfile);
	//fclose(infileShort);
	//fclose(infileFloat);
	exit(0);

}

void erreur(char *nomFichier) {
	printf("\nProbleme d'ouverture du fichier %s",nomFichier);
	exit(3);
}
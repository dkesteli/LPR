/*
 ============================================================================
 7  Fichier d'entier a lire et additionner par bloc de n element ( à creer dynamiquement)
    le nom du fichier et n sont passes par ligne de commande.
 ============================================================================
 */



#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

void func(char *name, char *cSize){

    FILE *fp=fopen(name, "rb");

    short size=atoi(cSize);
    short max=0;

    char *ch=(char *)malloc( sizeof(char) *(size+1));
    *(ch+size)='\0';

    char ctemp;

    short j=0, i=0;

    while ((ctemp=fgetc(fp)) != EOF){

        if(isdigit(ctemp)){
            ch[i]=ctemp;
            i++;
        }

        if(i == size){
            i=0;
            max+=atoi(ch);
        }
    }

    short temp=0;

    for(; j<i; j++){

        ctemp=*(ch+j);

        if( j>0 )
            temp*=10;

        temp+=atoi(&ctemp);
    }
    max+=temp;

    printf("\n%d",max);
}

int main(int argc, char **argv){

    if (argc != 3){
        printf("\nIncorrect arguments");
        exit(1);
    }
    func(*(argv+1), *(argv+2));

    return 0;
}
/*
 ============================================================================
 Soit une table à 4 dimensions de short m[3][3][3][3], écrire une fonction qui recoit une
 matrice ce trouvant dans cette table et un short qui renvoi l'occurence de ce short dans la
 matrice

 Indiquer comment l'appeler pour le cas illustré sur le tableau.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
short renvoi(short mat[][3][3],short dim, short ligne,short col, short nb);
void main() {
	 short t[3][3][3][3];
	 short i,j,k,l,aff=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				for(k=0;k<3;k++){
					for(l=0;l<3;l++){
						t[i][j][k][l]=5;
					}
				}
			}
		}
		t[2][2][1][3]=2;
		t[1][2][1][2]=2;
		t[1][2][2][1]=2;
		t[1][2][2][2]=2;
		for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						for(k=0;k<3;k++){
							for(l=0;l<3;l++){
								printf("%hd",t[i][j][k][l]);
							}
						}
					}
				}
		aff=renvoi(t[1],3,3,3,2); // je recherche dans la 1ere dimension tous les 2
	printf("\nle nobmre de fois =%hd",aff);
	system("pause");

}
short  renvoi(short mat[][3][3],short dim, short ligne,short col, short nb){
	short i,j,k;
	short cpt=0;

	for(i=0;i<ligne;i++){
		for(j=0;j<col;j++){
			for(k=0;k<dim;k++){

			printf("\n xxxxxx= %hd",mat[i][j][k]);
			if(mat[i][j][k]==nb)
				cpt+=1;
			printf("\n%hd",cpt);

		}
		}
	}

	return cpt;

}


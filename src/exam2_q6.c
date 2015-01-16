/*
	exam2_q6.c
	author : Denis Kestelier
	Question : 
	Programme qui affiche un enregistrement d'un fichier passé en ligne de commande.
	Un enregistrement se compose de : nom(20 caractères), numéro(entier 2 bytes), ville(25 caractères)
	Le programme est lancé en ligne de commande par : 
	prog fichier -m Durant (pour afficher l'enregistrement recherché selon un nom)
	prog fichier -c 2 (pour afficher l'enregistrement dont le numéro se termine par le chiffre)
	Note : -m -> recherche la première personne avec le nom
	-c -> recherche un chiffre, et qui se termine par chiffre
*/
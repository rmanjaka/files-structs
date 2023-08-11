#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libPC.h"

///La fonction qui trier les informations d'ordre alphabetique
void trierParmarque(PC *PCs, int taille) {
    for (int i = 1; i < taille; i++) {
        PC PCCourante = PCs[i];
        int j = i - 1;
        while (j >= 0 && strcmp(PCs[j].marque, PCCourante.marque) > 0) {
            PCs[j + 1] = PCs[j];
            j--;
        }
        PCs[j + 1] = PCCourante;
    }
}

///La focntion pour ajouter des informations des nouveaux étudiants
int ajouterPCs(const char* nomFichier,int n){
	FILE* fichier=fopen(nomFichier,"a+");
	PC* x= malloc(sizeof(PC)*n);
	for(int i=0;i<n;i++){
		x[i]=saisirPC();
		printf("\n");
	}
				
	for(int i=0;i<n;i++){
		fprintf(fichier,"%s,%s,%s\n",x[i].marque,x[i].label,x[i].mac);
	}
	fclose(fichier);
	return 1;
}

///La fonction pour saisir les informations dans la structure
PC saisirPC(){
	PC x;
	char marque[100];
	printf("Taper Entrer pour le continuer");
	fgets(marque, sizeof(x.marque), stdin); 	marque[strlen(marque) - 1] = '\0';
	printf("\nMarque : ");
	fgets(x.marque, sizeof(x.marque), stdin); 	x.marque[strlen(x.marque) - 1] = '\0';
    printf("Label : ");
	fgets(x.label,100, stdin);	x.label[strlen(x.label) - 1] = '\0';
    printf("Mac: ");
    fgets(x.mac,100, stdin);	x.mac[strlen(x.mac) - 1] = '\0';
    
	return x;
} 

///La focntion pour afficher la contenu d'un fichier
void afficherContenu(const char* nomfichier){
	FILE *fichier=fopen(nomfichier,"r");
	
	///Si le fichier n'existe pas ou son contenu est vide
	if(fichier==NULL){
		printf("Erreur lors de l'ouverture de fichier %s",nomfichier);	
		exit(1);	
	}
	
	///Deplacer le curseur au debut du fichier
	fseek(fichier,0,SEEK_SET);
	char ligne[100];
	
	///Affichage de la chaine qui a parcouru chaque ligne du fichier
	while(fgets(ligne,100,fichier)!=NULL){	
		printf("%s",ligne);
	}
	fclose(fichier);
}

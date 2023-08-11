#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libPC.h"

int main(){
	char nomFichier[20]="InfoPC.csv";
	FILE* fichier=fopen(nomFichier,"r");
	if (fichier == NULL) {
        printf("Erreur lors de l'enregistrement du fichier.\n");
        exit(1);
    }
    
	PC x[46];
	int i=0;
	while(fscanf(fichier, "%[^,],%[^,],%[^\n]\n",
		x[i].marque, x[i].label, x[i].mac)==3){
		//printf("%s,%s,%s\n",x[i].marque, x[i].label, x[i].BACC);
		i++;
	}
	fclose(fichier);
	int choix=0;
	do{
		system("clear");
		printf("\nMenu :\n");
        printf("1. Afficher les informations dans le fichier\n");
        printf("2. Ajouter des informations pour de nouveau PC\n");
        printf("3. Trier les informations des étudiants par ordre alphabétique des marques\n");
        printf("4. Quitter\n");
		printf("Entrer un choix: ");
		scanf("%d",&choix);
		
		switch(choix){
			case 1:{
				system("clear");
				afficherContenu(nomFichier);
			}break;
			
			case 2:{
				system("clear");
				int n=1;
				printf("ENTRER LE NOMBRE D'PC A AJOUTER:"); scanf("%d",&n);
				int ver=ajouterPCs(nomFichier,n);
				if(ver==1)
					printf("Les informations sont ajoutees dans le fichier.");
				
			}break;
			
			case 3:{
				system("clear");
				FILE* fic=fopen(nomFichier,"w");
				if (fic == NULL) {
					printf("Erreur lors de l'enregistrement du fichier.\n");
				exit(1);
				}
				int taille =i;
				trierParmarque(x, taille);
				
				for (int i = 0; i < taille; i++) {
					fprintf(fic,"%s,%s,%s\n",x[i].marque, x[i].label, x[i].mac);	
				}		
				printf("Les informations triees sont ajoutees dans le fichier.");
				fclose(fic);
			}break;
			
			case 4:{
				system("clear");
				printf("AU REVOIR...");
				exit(1);
			}break;
			
			default:{
				printf("CHOIX INVALIDE!!!");
			}break;
		}
	printf("\nTaper Entrer pour continuer...");
	getchar();getchar();
	sleep(1);
	}while(1);
	free(x);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libStudent.h"

int main(){
	char nomFichier[20]="etudiants.csv";
	FILE* fichier=fopen(nomFichier,"r");
	if (fichier == NULL) {
        printf("Erreur lors de l'enregistrement du fichier.\n");
        exit(1);
    }
    
	Etudiant x[46];
	int i=0;
	while(fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
		x[i].Nom, x[i].Prenom, x[i].Tel,x[i].Email,x[i].DateDeNaissance,x[i].LieuDeNaissance,
		x[i].BACC, x[i].genre, x[i].URL)==9){
		//printf("%s,%s,%s\n",x[i].Nom, x[i].Prenom, x[i].BACC);
		i++;
	}
	fclose(fichier);
	int choix=0;
	
	while(1){
		printf("\nMenu :\n");
        printf("1. Afficher les informations dans le fichier\n");
        printf("2. Ajouter des informations pour de nouveaux étudiants\n");
        printf("3. Rechercher des informations a partir d'un nom\n");
        printf("4. Trier les informations des étudiants par ordre alphabétique des noms\n");
        printf("5. Quitter\n");
		printf("Entrer un choix: ");
		scanf("%d",&choix);
		
		switch(choix){
			case 1:{
				printf("VOICI LES INFORMATIONS DES ETUDIANTS DANS LA LISTE:\n"); 
				int taille =i;
				for (int i = 0; i < taille; i++) {
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",x[i].Nom, x[i].Prenom, x[i].Tel,x[i].Email,
					x[i].DateDeNaissance,x[i].LieuDeNaissance,x[i].BACC, x[i].genre, x[i].URL);	
				}
			}break;
			
			case 2:{
				system("clear");
				int n=1;
				printf("ENTRER LE NOMBRE D'ETUDIANT A AJOUTER:"); scanf("%d",&n);
				int ver=ajouterEtudiants(nomFichier,n);
				if(ver==1)
					printf("Les informations sont ajoutees dans le fichier.");
				
			}break;
			
			case 3:{
				int nombreEtudiants = i;
				char nomRecherche[] = " ";
				printf("\nENTRER LE NOM D'ETUDIANT POUR LA RECHERCHE: "); scanf("%s",nomRecherche);
				Etudiant etudiantTrouve = rechercherEtudiantParNom(x, nombreEtudiants, nomRecherche);
				if (etudiantTrouve.Nom) {
					printf("L'étudiant trouvé qui a un nom: %s", nomRecherche);
					printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",etudiantTrouve.Nom,etudiantTrouve.Prenom, etudiantTrouve.Tel,etudiantTrouve.Email,
					etudiantTrouve.DateDeNaissance,etudiantTrouve.LieuDeNaissance,etudiantTrouve.BACC, etudiantTrouve.genre, etudiantTrouve.URL);	
				}
				else {
					printf("Aucun étudiant trouvé avec le nom : %s\n", nomRecherche);
				}
			}break;
			
			
			case 4:{
				system("clear");
				char nomFichier[20]="etudiants.csv";
				FILE* fic=fopen(nomFichier,"w");
				if (fic == NULL){
					printf("Erreur lors de l'enregistrement du fichier.\n");
					exit(1);
				}
				int taille =i;
				trierParNom(x, taille);
				for (int i = 0; i < taille; i++) {
					fprintf(fic,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",x[i].Nom, x[i].Prenom, x[i].Tel,x[i].Email,
					x[i].DateDeNaissance,x[i].LieuDeNaissance,x[i].BACC, x[i].genre, x[i].URL);	
				}		
				printf("Les informations triees sont ajoutees dans le fichier");
				fclose(fic);
			}break;
			
			case 5:{
				printf("AU REVOIR...");
				exit(1);
			}break;
			
			default:{
				printf("CHOIX INVALIDE!!!");
			}break;
		}
	printf("\nTaper Entrer pour continuer...");
	getchar();getchar();
	sleep(1);system("clear");	
	}
	free(x);
	return 0;
}

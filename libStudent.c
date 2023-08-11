#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libStudent.h"

/// Fonction de recherche d'un étudiant par nom
Etudiant rechercherEtudiantParNom(Etudiant x[], int nombreEtudiants, char nomRecherche[]) {
   Etudiant etudiantInconnu = {"","","","","","","","",""}; // Valeur par défaut si l'étudiant n'est pas trouvé
    
    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(x[i].Nom, nomRecherche) == 0) {
            return x[i]; // Retourne l'étudiant trouvé
        }
    }    
    return etudiantInconnu; // Retourne un étudiant avec des informations vides
}

///La fonction qui trier les informations d'ordre alphabetique
void trierParNom(Etudiant *etudiants, int taille) {
    for (int i = 1; i < taille; i++) {
        Etudiant EtudiantCourante = etudiants[i];
        int j = i - 1;
        while (j >= 0 && strcmp(etudiants[j].Nom, EtudiantCourante.Nom) > 0) {
            etudiants[j + 1] = etudiants[j];
            j--;
        }
        etudiants[j + 1] = EtudiantCourante;
    }
}

///La focntion pour ajouter des informations des nouveaux étudiants
int ajouterEtudiants(char* nomFichier,int n){
	FILE* fichier=fopen(nomFichier,"a+");
	Etudiant* x= malloc(sizeof(Etudiant)*n);
	for(int i=0;i<n;i++){
		x[i]=saisirEtudiant();printf("\n");
	}			
	for(int i=0;i<n;i++){
		fprintf(fichier,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",x[i].Nom,x[i].Prenom,x[i].Tel,x[i].Email,x[i].DateDeNaissance,x[i].LieuDeNaissance,
		x[i].BACC,x[i].genre,x[i].URL);
	}
	fclose(fichier);
	return 1;
}

///La fonction pour saisir les informations dans la structure
Etudiant saisirEtudiant(){
	Etudiant x;
	char nom[100];
	printf("Taper Entrer pour le continuer");
	fgets(nom, sizeof(x.Nom), stdin); 	nom[strlen(nom) - 1] = '\0';
	printf("\nNom : ");
	fgets(x.Nom, sizeof(x.Nom), stdin); 	x.Nom[strlen(x.Nom) - 1] = '\0';
    printf("Prénom : ");
	fgets(x.Prenom,100, stdin);	x.Prenom[strlen(x.Prenom) - 1] = '\0';
    printf("Téléphone : ");
    fgets(x.Tel,100, stdin);	x.Tel[strlen(x.Tel) - 1] = '\0';
    printf("Email : ");
    fgets(x.Email,100, stdin); x.Email[strlen(x.Email) - 1] = '\0';
    printf("Date de naissance : ");
    fgets(x.DateDeNaissance, 100, stdin); x.DateDeNaissance[strlen(x.DateDeNaissance) - 1] = '\0';
    printf("Lieu de naissance : ");
    fgets(x.LieuDeNaissance, sizeof(x.LieuDeNaissance), stdin); x.LieuDeNaissance[strlen(x.LieuDeNaissance) - 1] = '\0';
    printf("BACC : ");
    fgets(x.BACC, sizeof(x.BACC), stdin); x.BACC[strlen(x.BACC) - 1] = '\0';
    printf("Genre : ");
    fgets(x.genre, sizeof(x.genre), stdin); 
    x.genre[strlen(x.genre) - 1] = '\0';
    printf("URL : ");
    fgets(x.URL, sizeof(x.URL), stdin); x.URL[strlen(x.URL) - 1] = '\0';
	return x;
} 


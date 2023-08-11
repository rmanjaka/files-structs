#ifndef STUDENT_H
#define STUDENT_H
typedef struct{
	char Nom[100],
	Prenom[100],
	Tel[100],
	Email[100],
	DateDeNaissance[100],
	LieuDeNaissance[100],
	BACC[100],
	genre[100],
	URL[100];
	
}Etudiant;

Etudiant saisirEtudiant();
int ajouterEtudiants(char* nomFichier,int n);
void trierParNom(Etudiant *etudiants, int taille);
Etudiant rechercherEtudiantParNom(Etudiant x[], int nombreEtudiants,char nomRecherche[]);

#endif

#ifndef STUDENT_H
#define STUDENT_H
typedef struct{
	char marque[100],
	label[100],
	mac[100];
	
}PC;

PC saisirPC();
int ajouterPCs(const char* nomFichier,int n);
void trierParmarque(PC *PCs, int taille);
void afficherContenu(const char* nomfichier);
#endif

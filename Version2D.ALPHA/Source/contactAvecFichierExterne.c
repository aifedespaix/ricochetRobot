#include "include.h"

void recupererInfosMap(Parametres *ParametresDuJeu)
{
    /*DEBUT REINITIALISE LA MAP*/
    int i;
    for (i=0; i<2000; i++)
        ParametresDuJeu->contenuFichierMap[i]='\0';
    /*FIN REINITIALISE LA MAP*/

    FILE *fichierMap = NULL;
    fichierMap = fopen(ParametresDuJeu->fichierMap, "r");
    if (fichierMap != NULL)
    {
        fgets(ParametresDuJeu->contenuFichierMap, 500, fichierMap);
//prototype : char* fgets(char* chaine, int nbreDeCaracteresALire, FILE* pointeurSurFichier);
        fclose(fichierMap);
    }
}

void enregistrerInfosMap(Parametres *ParametresDuJeu)
{
    FILE *fichierMap = NULL;
    fichierMap = fopen(ParametresDuJeu->fichierMap, "r+");
    if (fichierMap != NULL)
    {
        fprintf(fichierMap, ParametresDuJeu->contenuFichierMap);
        fclose(fichierMap);
    }
}


void recupererTitreMap(Parametres *ParametresDuJeu)
{
    int i;
    /*DEBUT REINITIALISE NOM MAP*/
    for (i=0; i<50; i++)
        ParametresDuJeu->titreMap[i]='\0';
    /*FIN REINITIALISE NOM MAP*/

    FILE *fichierTitre = NULL;
    fichierTitre = fopen(ParametresDuJeu->fichierTitreMap, "r");
    if (fichierTitre != NULL)
    {
        fgets(ParametresDuJeu->titreMap, 500, fichierTitre);
//prototype : char* fgets(char* chaine, int nbreDeCaracteresALire, FILE* pointeurSurFichier);
        fclose(fichierTitre);
    }
}

void enregistrerTitreMap(Parametres *ParametresDuJeu)
{
    FILE *fichierTitre = NULL;
    fichierTitre = fopen(ParametresDuJeu->fichierTitreMap, "r+");
    if (fichierTitre != NULL)
    {
        fprintf(fichierTitre, ParametresDuJeu->titreMap);
        fclose(fichierTitre);
    }
}

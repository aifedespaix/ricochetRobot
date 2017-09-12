#include "include.h"

void creerMapBase(Jeu jeu[33][33])
{
    int i, j;
    //Reinitialise MAP
    for(i=0; i<33; i++)
        for(j=0; j<33; j++)
            jeu[i][j].x=j;
            jeu[i][j].y=i;// I J VERIFIE SALOPE : MERCI OK JREGARDE
            jeu[i][j].type=VIDE;
    // Fin reinitialise MAP

    for (i=0; i<33; i++)
    {
        for (j=0; j<33; j++)
        {
            if (i==0 || i==32)                          // Ligne haut ou ligne bas
            {
                if (j%2==0)
                {
                    jeu[i][j].type=CROISEMENT;
                }
                else
                {
                    jeu[i][j].type=MUR1;
                }
            }
            else
            {
                if (i%2 == 1)                           // Ligne pair : bordures + vide
                {
                    if (j==0 || j==32)
                    {
                        jeu[i][j].type= MUR2;
                    }

                    else
                    {
                        jeu[i][j].type=VIDE;
                    }
                }
                else                                    // Ligne impaire : bordures + vide une fois sur deux + '+' le reste du temps
                {
                    if (j==0 || j==32)
                    {
                        jeu[i][j].type=MUR2;
                    }

                    else
                    {
                        if(j%2 == 1)
                        {
                            jeu[i][j].type=VIDE;
                        }

                        else
                        {
                            jeu[i][j].type=CROISEMENT;
                        }
                    }
                }
            }
        }
    }
}

void creerMap(Composantes *composantes, SDL_Surface *screen, Jeu jeu[33][33], Parametres *ParametresDuJeu)
{
//ROBOT ROUGE
    composantes->robots[0].images = SDL_LoadBMP("images/robots/red.bmp");

// ROBOT VERT
    composantes->robots[1].images = SDL_LoadBMP("images/robots/green.bmp");

// ROBOT BLEU
    composantes->robots[2].images = SDL_LoadBMP("images/robots/blue.bmp");

// ROBOT JAUNE
    composantes->robots[3].images = SDL_LoadBMP("images/robots/yellow.bmp");
/* ROBOTS */

    creerMapBase(jeu);
    recupererInfosMap(ParametresDuJeu);
    Objet Stock;
    int i=0;
    while(i<2000)
    {
        if (((int)ParametresDuJeu->contenuFichierMap[i] > 57 || (int)ParametresDuJeu->contenuFichierMap[i] < 48) && ParametresDuJeu->contenuFichierMap[i] != ',' ) // Si le charactère n'est pas un entier entre 0 et 9
        {
            // Partie 1, coordonnée x
            Stock.charactere=ParametresDuJeu->contenuFichierMap[i];
            if ( (int)(ParametresDuJeu->contenuFichierMap[i+2]) >= 48 && (int)(ParametresDuJeu->contenuFichierMap[i+2]) <= 57 ) // Si le char +2 est un entier entre 0 et 9
            {
                Stock.x=((int)(ParametresDuJeu->contenuFichierMap[i+2]))-48;
                Stock.x += (((int)(ParametresDuJeu->contenuFichierMap[i+1]))-48)*10;
                i+=3; // on arrive à la prochaine virgule
            }
            else // Si le char +2 est n'est pas un entier entre 0 et 9, c'est donc une virgule
            {
                Stock.x=((int)(ParametresDuJeu->contenuFichierMap[i+1])-48);
                i+=2; // on arrive à la prochaine virgule
            }
            // i est donc à la position d'une virgule dans le tableau


            //Partie 2, coordonnée y
            if ( (int)(ParametresDuJeu->contenuFichierMap[i+2]) >= 48 && (int)(ParametresDuJeu->contenuFichierMap[i+2]) <= 57 ) // Si le char +2 est un entier entre 0 et 9
            {
                Stock.y=((int)(ParametresDuJeu->contenuFichierMap[i+2]))-48;
                Stock.y += (((int)(ParametresDuJeu->contenuFichierMap[i+1]))-48)*10;
                i+=2; // On arrive à la prochaine lettre
            }
            else
            {
                Stock.y=((int)(ParametresDuJeu->contenuFichierMap[i+1])-48);
                i+=1;  // On arrive à la prochaine lettre
            }

            //Partie 3, on place dans le jeu


            if (Stock.charactere == 'Q')
            {
                jeu[Stock.x][Stock.y].type=ROBOT;
                jeu[Stock.x][Stock.y].charactere=Stock.charactere;
                composantes->robots[0].x=Stock.x;
                //ParametresDuJeu->contenuFichierMap[0]=Stock.x; //WTF PUTAIN DE MERDE
                composantes->robots[0].y=Stock.y;
                composantes->robots[0].position.x=((composantes->robots[0].x)/2)*37+5;
                composantes->robots[0].position.y=((composantes->robots[0].y)/2)*37+5+ORDONNEE;
                composantes->robots[0].type=ROBOT;
                composantes->robots[0].amovible=1;
            }
            else if (Stock.charactere == 'W')
            {
                jeu[Stock.x][Stock.y].type=ROBOT;
                jeu[Stock.x][Stock.y].charactere=Stock.charactere;
                composantes->robots[1].x=Stock.x;
                composantes->robots[1].y=Stock.y;
                composantes->robots[1].position.x=((composantes->robots[1].x)/2)*37+5;
                composantes->robots[1].position.y=((composantes->robots[1].y)/2)*37+5+ORDONNEE;
                composantes->robots[1].type=ROBOT;
                composantes->robots[1].amovible=1;
            }
            else if (Stock.charactere == 'E')
            {
                jeu[Stock.x][Stock.y].type=ROBOT;
                jeu[Stock.x][Stock.y].charactere=Stock.charactere;
                composantes->robots[2].x=Stock.x;
                composantes->robots[2].y=Stock.y;
                composantes->robots[2].position.x=((composantes->robots[2].x)/2)*37+5;
                composantes->robots[2].position.y=((composantes->robots[2].y)/2)*37+5+ORDONNEE;
                composantes->robots[2].type=ROBOT;
                composantes->robots[2].amovible=1;
            }
            else if (Stock.charactere == 'R')
            {
                jeu[Stock.x][Stock.y].type=ROBOT;
                jeu[Stock.x][Stock.y].charactere=Stock.charactere;
                composantes->robots[3].x=Stock.x;
                composantes->robots[3].y=Stock.y;
                composantes->robots[3].position.x=((composantes->robots[3].x)/2)*37+5;
                composantes->robots[3].position.y=((composantes->robots[3].y)/2)*37+5+ORDONNEE;
                composantes->robots[3].type=ROBOT;
                composantes->robots[3].amovible=1;
            }
            else if (Stock.charactere == '#')
            {
                jeu[Stock.x][Stock.y].type=OBJECTIF;
                jeu[Stock.x][Stock.y].charactere=Stock.charactere;
                composantes->objectif.x=Stock.x;
                composantes->objectif.y=Stock.y;
                composantes->objectif.position.x = ((Stock.x)/2)*37+5;
                composantes->objectif.position.y = ((Stock.y)/2)*37+5+ORDONNEE;
            }
            else
            {
                if(Stock.x % 2 == 0)
                {
                    jeu[Stock.x][Stock.y].type=MUR1;
                    jeu[Stock.x][Stock.y].charactere='|';
                }
                else
                {
                    jeu[Stock.x][Stock.y].type=MUR2;
                    jeu[Stock.x][Stock.y].charactere='-';
                }
            }
        }
        i++;
    }
}


void sauvegarderDansTableau(Jeu jeu[33][33], Parametres *ParametresDuJeu)
{
    int i, j;
    for(i=0; i<2000; i++)
        ParametresDuJeu->contenuFichierMap[i] = '\0';

    char charactere;
    char evoBot[4];
    int k=0;
    evoBot[0]='Q';
    evoBot[1]='W';
    evoBot[2]='E';
    evoBot[3]='R';

    for (i=1; i<32; i++)
        for (j=1; j<32; j++)
        {
            if ((i%2 != 0 || j%2 != 0) && (jeu[i][j].type != VIDE)) // Je ne veux pas des cases à coordonnées paires/paires, car ce sont des cases "+", ni les cases ou j'ai un espace " "
            {
                switch (jeu[i][j].type)
                {
                    case MUR1:
                        charactere='|';
                        break;

                    case MUR2:
                        charactere='-';
                        break;

                    case ROBOT:
                        charactere=evoBot[k];
                        k++;
                        break;

                    case OBJECTIF:
                        charactere='#';
                        break;

                    default:
                        break;
                }
                sprintf(ParametresDuJeu->contenuFichierMap, "%s%c%d,%d", ParametresDuJeu->contenuFichierMap, charactere, i, j);
            }
        }
    //enregistrerInfosMap(ParametresDuJeu);
}

#include "include.h"

void creerMapRandom(Jeu jeu[33][33], Objet robots[4], Parametres *ParametresDuJeu)
{
    do
    {
        creerMapBase(jeu);
        int nombreDeMurs = Random(50,100);
        placeMursRandoms(jeu, nombreDeMurs);
        placeObjetsRandoms(jeu, robots);
    } while (testMap(jeu, robots, ParametresDuJeu));
    sauvegarderDansTableau(jeu, ParametresDuJeu);
    enregistrerInfosMap(ParametresDuJeu);
}

void placeMursRandoms(Jeu jeu[33][33], int nombreDeMurs)
{
    int i;
    int x, y;
    for (i=0; i<nombreDeMurs; i++)
    {
        int recommencer=1;
        while(recommencer) // Tant que l'on peut pas placer de mur on redemande l'alléatoire
        {
            recommencer=0;
            x = Random(1,32);
            y = Random(1,32);
            if(x%2 == 0 && y%2 == 1)
            {
                jeu[x][y].type = MUR2;
            }
            else if(x%2 == 1 && y%2 == 0)
            {
                jeu[x][y].type = MUR1;
            }
            else //(x%2 == y%2)
            {
                recommencer=1;
            }
        }
    }
}

void placeObjetsRandoms(Jeu jeu[33][33], Objet robots[4])
{
    int i;
    int x, y;
    int continuer;
    for (i=0; i<5; i++)
    {
        continuer=1;
        while (continuer)
        {
            x = Random(3,29);
            y = Random(3,29);
            if (
                jeu[x][y].type == VIDE
                && (x%2 == 1 && y%2 == 1)
                )  // Case libre et on ne veut pas que ce soit une case à côté d'un bord de tableau
            {
                if (i!= 4)
                {
                    jeu[x][y].type = ROBOT;
                    robots[i].x = x;
                    robots[i].y = y;
                    robots[i].amovible=1;
                }
                else
                {
                    jeu[x][y].type = OBJECTIF;
                }
                continuer=0;
            }
        }
    }
}

int testMap(Jeu jeu[33][33], Objet robots[4], Parametres *ParametresDuJeu)
{
    //On copie le jeu et les robots pour effectuer le test sans affecter la map
    int i, j;
    Jeu copieJeu[33][33];
    for(i=0; i<33; i++)
        for(j=0; j<33; j++)
            copieJeu[i][j]=jeu[i][j];

    Objet copieRobots[4];
    for  (i=0; i<4; i++)
        copieRobots[i]=robots[i];

    ParametresDuJeu->nombrePoints=0;


    Parametres copieParametresDuJeu;
    copieParametresDuJeu=*ParametresDuJeu;

    int direction, numRobot;
    i=0;
    while (copieParametresDuJeu.nombrePoints<4 && i<2000)
    {
        i++;
        numRobot=Random(0,4);
        direction=Random(0,4);
        switch (direction)
        {
            case 0:
                deplacementBasRand(copieJeu, &copieRobots[numRobot], &copieParametresDuJeu);
                break;

            case 1:
                deplacementHautRand(copieJeu, &copieRobots[numRobot], &copieParametresDuJeu);
                break;

            case 2:
                deplacementGaucheRand(copieJeu, &copieRobots[numRobot], &copieParametresDuJeu);
                break;

            case 3:
                deplacementDroiteRand(copieJeu, &copieRobots[numRobot], &copieParametresDuJeu);
                break;
        }
    }
    if (copieParametresDuJeu.nombrePoints == 4) return 0;
    else return 1;
}

void deplacementDroiteRand(Jeu jeu[33][33], Objet *robot, Parametres *ParametresDuJeu)
{
    while(jeu[robot->x+1][robot->y].type != MUR1
          && jeu[robot->x+2][robot->y].type != ROBOT
          && robot->x+2 < 33
          && robot->amovible)
    {
        if(jeu[robot->x+2][robot->y].type == OBJECTIF) // SI il y à un objectif
        {
            jeu[robot->x][robot->y].type = VIDE;
            robot->amovible=0;
            (ParametresDuJeu->nombrePoints)++;
        }
        else // Sinon il n'y a que du vide
        {
            jeu[robot->x][robot->y].type = VIDE;
            (robot->x)+=2;
            jeu[robot->x][robot->y].type = ROBOT;
        }
    }
}

void deplacementGaucheRand(Jeu jeu[33][33], Objet *robot, Parametres *ParametresDuJeu)
{
    while(jeu[robot->x-1][robot->y].type != MUR1
          && jeu[robot->x-2][robot->y].type != ROBOT
          && robot->x-2 > 0
          && robot->amovible)
    {
        if(jeu[robot->x-2][robot->y].type == OBJECTIF) // SI il y à un objectif
        {
            jeu[robot->x][robot->y].type = VIDE;
            robot->amovible=0;
            (ParametresDuJeu->nombrePoints)++;
        }
        else // Sinon il n'y a que du vide
        {
            jeu[robot->x][robot->y].type = VIDE;
            (robot->x)-=2;
            jeu[robot->x][robot->y].type = ROBOT;
        }
    }
}

void deplacementHautRand(Jeu jeu[33][33], Objet *robot, Parametres *ParametresDuJeu)
{
    while(jeu[robot->x][robot->y-1].type != MUR1
          && jeu[robot->x][robot->y-2].type != ROBOT
          && robot->y-2 > 0
          && robot->amovible)
    {
        if(jeu[robot->x][robot->y-2].type == OBJECTIF) // SI il y à un objectif
        {
            jeu[robot->x][robot->y].type = VIDE;
            robot->amovible=0;
            (ParametresDuJeu->nombrePoints)++;
        }
        else // Sinon il n'y a que du vide
        {
            jeu[robot->x][robot->y].type = VIDE;
            (robot->y)-=2;
            jeu[robot->x][robot->y].type = ROBOT;
        }
    }
}

void deplacementBasRand(Jeu jeu[33][33], Objet *robot, Parametres *ParametresDuJeu)
{
    while(jeu[robot->x][robot->y+1].type != MUR1
          && jeu[robot->x][robot->y+2].type != ROBOT
          && robot->y+2 < 33
          && robot->amovible)
    {
        if(jeu[robot->x][robot->y+2].type == OBJECTIF) // SI il y à un objectif
        {
            jeu[robot->x][robot->y].type = VIDE;
            robot->amovible=0;
            (ParametresDuJeu->nombrePoints)++;
        }
        else // Sinon il n'y a que du vide
        {
            jeu[robot->x][robot->y].type = VIDE;
            (robot->y)+=2;
            jeu[robot->x][robot->y].type = ROBOT;
        }
    }
}

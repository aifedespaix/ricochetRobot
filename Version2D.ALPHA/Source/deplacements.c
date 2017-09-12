#include "include.h"

char returnEventDeplacement()
{
    SDL_Event event;
    int keepA=1;
    while(keepA)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                keepA=0;
                return '0';
                break;

            case SDLK_ESCAPE:
                keepA=0;
                return '0';
                break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    keepA=0;
                    return '0';
                    break;

                case SDLK_UP:
                    keepA=0;
                    return 'u';
                    break;

                case SDLK_DOWN:
                    keepA=0;
                    return 'd';
                    break;

                case SDLK_RIGHT:
                    keepA=0;
                    return 'r';
                    break;

                case SDLK_LEFT:
                    keepA=0;
                    return 'l';
                    break;

                case SDLK_SPACE:
                    keepA=0;
                    return 'c'; //c = change robot
                    break;

                default:
                    break;
            }
        }
    }
    return '0';
}

void jouer(Composantes *composantes, SDL_Surface *screen, Jeu jeu[33][33], Parametres *ParametresDuJeu)
{
    ParametresDuJeu->nombrePoints = 0;
    ParametresDuJeu->nombreDeplacements = 0;

    composantes->blanc.images = SDL_LoadBMP("images/robots/blanc.bmp");

    composantes->plateau.images = SDL_LoadBMP("images/plateaux/plateauJeu.bmp");

    SDL_Event event;

    int keepA;

    creerMap(composantes, screen, jeu, ParametresDuJeu);

    int i;

    afficherJeu(screen, composantes, jeu);


    Objet robotUse; // Prépare le robot actuel (robot joué à chauque instant)
    robotUse.images = composantes->robots[0].images;
    robotUse.position.x=945;
    robotUse.position.y=121;
    placeImage(&robotUse, screen);


    int nR=0;
    char sensDeplacement='a';

    while(sensDeplacement != '0')
    {
        afficheScore(ParametresDuJeu->nombreDeplacements, 830, 300, screen);

        if (ParametresDuJeu->nombrePoints == 4)
        {
            composantes->plateau.images = SDL_LoadBMP("images/plateaux/plateauVictoire.bmp");
            placeImage(&composantes->plateau, screen);

            keepA=1;
            while(keepA)
            {
                SDL_WaitEvent(&event);
                if (event.key.keysym.sym == SDLK_SPACE)
                    keepA=0;
            }
            break;
        }

        if (sensDeplacement != 'c')
        {
            sensDeplacement = returnEventDeplacement();
        }

        if (sensDeplacement == 'c')
        {
            do
            {
                if(nR == 3) nR = 0;

                else nR++;
            } while(!composantes->robots[nR].amovible);
            robotUse.images=composantes->robots[nR].images;
            placeImage(&robotUse, screen);
            sensDeplacement = returnEventDeplacement();
        }


        if(sensDeplacement == 'r')
        {
            while(jeu[composantes->robots[nR].x+1][composantes->robots[nR].y].type != MUR1
                  && jeu[composantes->robots[nR].x+2][composantes->robots[nR].y].type != ROBOT
                  && composantes->robots[nR].amovible)
            {
                if(composantes->robots[nR].x+2 >= 0
                   && jeu[composantes->robots[nR].x+2][composantes->robots[nR].y].type == OBJECTIF
                   && jeu[composantes->robots[nR].x+1][composantes->robots[nR].y].type != MUR1)
                {
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = VIDE;
                    composantes->robots[nR].amovible=0;
                    (ParametresDuJeu->nombrePoints)++;
                    composantes->robots[nR].images = SDL_LoadBMP("images/robots/blanc.bmp");
                    placeRobot(&composantes->robots[nR], screen, composantes, 0, 0);
                    sensDeplacement = 'c';
                }
                else
                {
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = VIDE;
                    composantes->robots[nR].x+=2;
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = ROBOT;
                    for (i=0; i<37; i++)
                    {
                        placeRobot(&composantes->robots[nR], screen, composantes, 1, 0);
                        wait();
                    }
                }
            }
            (ParametresDuJeu->nombreDeplacements)++;
        }

        if(sensDeplacement == 'd')
        {
            while(jeu[composantes->robots[nR].x][composantes->robots[nR].y+1].type != MUR2
                  && jeu[composantes->robots[nR].x][composantes->robots[nR].y+2].type != ROBOT
                  && composantes->robots[nR].amovible)
            {
                if(composantes->robots[nR].y+2 <= 33
                   && jeu[composantes->robots[nR].x][composantes->robots[nR].y+2].type == OBJECTIF
                   && jeu[composantes->robots[nR].x][composantes->robots[nR].y+1].type != MUR2)
                {
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = VIDE;
                    composantes->robots[nR].amovible=0;
                    (ParametresDuJeu->nombrePoints)++;
                    composantes->robots[nR].images = SDL_LoadBMP("images/robots/blanc.bmp");
                    placeRobot(&composantes->robots[nR], screen, composantes, 0, 0);
                    sensDeplacement = 'c';
                }
                else
                {
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = VIDE;
                    composantes->robots[nR].y+=2;
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = ROBOT;
                    for (i=0; i<37; i++)
                    {
                        placeRobot(&composantes->robots[nR], screen, composantes, 0, 1);
                        wait();
                    }
                }
            }
            (ParametresDuJeu->nombreDeplacements)++;
        }

        if(sensDeplacement == 'l')
        {
            while(jeu[composantes->robots[nR].x-1][composantes->robots[nR].y].type != MUR1
                  && jeu[composantes->robots[nR].x-2][composantes->robots[nR].y].type != ROBOT
                  && composantes->robots[nR].amovible)
            {
                if(composantes->robots[nR].x-2 >= 0
                   && jeu[composantes->robots[nR].x-2][composantes->robots[nR].y].type == OBJECTIF
                   && jeu[composantes->robots[nR].x-1][composantes->robots[nR].y].type != MUR1)
                {
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = VIDE;
                    composantes->robots[nR].amovible=0;
                    (ParametresDuJeu->nombrePoints)++;
                    composantes->robots[nR].images = SDL_LoadBMP("images/robots/blanc.bmp");
                    placeRobot(&composantes->robots[nR], screen, composantes, 0, 0);
                    sensDeplacement = 'c';
                }
                else
                {
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = VIDE;
                    composantes->robots[nR].x-=2;
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = ROBOT;
                    for (i=0; i<37; i++)
                    {
                        placeRobot(&composantes->robots[nR], screen, composantes, -1, 0);
                        wait();
                    }
                }
            }
            (ParametresDuJeu->nombreDeplacements)++;
        }

        if(sensDeplacement == 'u')
        {
            while(jeu[composantes->robots[nR].x][composantes->robots[nR].y-1].type != MUR2
                  && jeu[composantes->robots[nR].x][composantes->robots[nR].y-2].type != ROBOT
                  && composantes->robots[nR].amovible)
            {
                if(composantes->robots[nR].y-2 <= 33
                   && jeu[composantes->robots[nR].x][composantes->robots[nR].y-2].type == OBJECTIF
                   && jeu[composantes->robots[nR].x][composantes->robots[nR].y-1].type != MUR2)
                {
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = VIDE;
                    composantes->robots[nR].amovible=0;
                    composantes->robots[nR].images = SDL_LoadBMP("images/robots/blanc.bmp");
                    placeRobot(&composantes->robots[nR], screen, composantes, 0, 0);
                    (ParametresDuJeu->nombrePoints)++;
                    sensDeplacement = 'c';
                }
                else
                {
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = VIDE;
                    composantes->robots[nR].y-=2;
                    jeu[composantes->robots[nR].x][composantes->robots[nR].y].type = ROBOT;
                    for (i=0; i<37; i++)
                    {
                        placeRobot(&composantes->robots[nR], screen, composantes, 0, -1);
                        wait();
                    }
                }
            }
            (ParametresDuJeu->nombreDeplacements)++;
        }
    }
}

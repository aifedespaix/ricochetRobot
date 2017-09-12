#include "include.h"

void placeRobot(Objet *image, SDL_Surface *screen, Composantes *composantes, int x, int y)
{
    composantes->blanc.images = SDL_LoadBMP("images/robots/blanc.bmp");
    SDL_SetColorKey(composantes->blanc.images, SDL_SRCCOLORKEY, SDL_MapRGB(composantes->blanc.images->format , 0, 255, 255));
    SDL_BlitSurface(composantes->blanc.images, NULL, screen, &image->position);

    image->position.x = (image->position.x)+x;
    image->position.y = (image->position.y)+y;
    SDL_SetColorKey(image->images, SDL_SRCCOLORKEY, SDL_MapRGB(image->images->format, 0, 255, 255));
    SDL_BlitSurface(image->images, NULL, screen, &image->position);

    SDL_Flip(screen);
}

void placeImage(Objet *image, SDL_Surface *screen)
{
    SDL_SetColorKey(image->images, SDL_SRCCOLORKEY, SDL_MapRGB(image->images->format, 0, 255, 255));
    SDL_BlitSurface(image->images, NULL, screen, &image->position);
    SDL_Flip(screen);
}

void releaseImage(Objet image)
{
    SDL_FreeSurface(image.images);
}

void placeMurs(SDL_Surface *screen, Jeu jeu[33][33])
{
    Objet wall;
    int i, j;
    for (i=0; i<33; i++)
        for (j=0; j<33; j++)
        {
            if (jeu[i][j].type == MUR1 || jeu[i][j].type == MUR2)
            {
                wall.position.x = (i/2)*37+3;
                wall.position.y = (j/2)*37+3+ORDONNEE;
                if (jeu[i][j].type == MUR1)
                    wall.images = SDL_LoadBMP("images/murs/mur1.bmp");
                else
                    wall.images = SDL_LoadBMP("images/murs/mur2.bmp");

                SDL_BlitSurface(wall.images, NULL, screen, &wall.position);
            }
        }
}

void afficherJeu(SDL_Surface *screen, Composantes *composantes, Jeu jeu[33][33])
{
    placeImage(&composantes->plateau, screen);

    int i;
    for (i=0; i<4; i++)
        placeRobot(&composantes->robots[i], screen, composantes, 0, 0);

    placeMurs(screen, jeu);

    Objet bouttonRobotActuel;
    bouttonRobotActuel.images = SDL_LoadBMP("images/plateaux/robotActuel.bmp");
    bouttonRobotActuel.position.x = 750;
    bouttonRobotActuel.position.y = 100;
    placeImage(&bouttonRobotActuel, screen);

    Objet nombreDeplacements;
    nombreDeplacements.images = SDL_LoadBMP("images/plateaux/nombreDeDeplacements.bmp");
    nombreDeplacements.position.x = 750;
    nombreDeplacements.position.y = 200;
    placeImage(&nombreDeplacements, screen);

    placeImage(&composantes->objectif, screen);

}


void afficherEdition(SDL_Surface *screen, Composantes *composantes, Jeu jeu[33][33])
{
    //placeImage(&composantes->plateau, screen);

    int i;
    for (i=0; i<4; i++)
        placeRobot(&composantes->robots[i], screen, composantes, 0, 0);

    placeMurs(screen, jeu);

    placeImage(&composantes->objectif, screen);


    Objet enAttente[9];

    enAttente[0].images = SDL_LoadBMP("images/objectif.bmp");
    enAttente[1].images = SDL_LoadBMP("images/robots/red.bmp");
    enAttente[2].images = SDL_LoadBMP("images/robots/blue.bmp");
    enAttente[3].images = SDL_LoadBMP("images/robots/green.bmp");
    enAttente[4].images = SDL_LoadBMP("images/robots/yellow.bmp");
    enAttente[5].images = SDL_LoadBMP("images/murs/mur1.bmp");
    enAttente[6].images = SDL_LoadBMP("images/murs/mur2.bmp");
    enAttente[7].images = SDL_LoadBMP("images/editeur/bombe.bmp");

    for (i=0; i<5; i++)
    {
        enAttente[i].position.x = 750+(i*100);
        enAttente[i].position.y = 100;
        placeImage(&enAttente[i], screen);
    }
    for (i=5; i<8; i++)
    {
        enAttente[i].position.x = 750+((i-5)*100);
        enAttente[i].position.y = 200;
        placeImage(&enAttente[i], screen);
    }

}

void remplaceRobot(Objet *robot, SDL_Surface *screen, Jeu jeu[33][33])
{
    Objet remplacementCase;
    remplacementCase.images = ("images/robots/replaceCase.bmp");
    remplacementCase.x=robot->x;
    remplacementCase.x=robot->y;
    placeImage(&remplacementCase, screen);

    placeMurs(screen, jeu);
}

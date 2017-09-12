#include "include.h"

int main(int argc, char ** argv)
{
    srand (time (NULL));

    SDL_Surface *screen = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    screen=SDL_SetVideoMode(1280, 710, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
    if (screen == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Creer une couleur
    Uint32 roseSympa = SDL_MapRGB(screen->format, 22, 22, 22);
    // Applique la couleur à la surface ecran
    SDL_FillRect(screen, NULL, roseSympa);

    // Titre fenêtre
    SDL_WM_SetCaption("Ce jeu me parait plutot nul 8=D", NULL);

    /* JEU */
    Jeu jeu[33][33];

    creerMapBase(jeu);
    /* JEU */

/* PARAMETRES DU JEU */
    Parametres ParametresDuJeu;

    Composantes composantes;

/* BLANC */
    composantes.blanc.type = VIDE;
    composantes.blanc.images = SDL_LoadBMP("images/robots/blanc.bmp");
/* BLANC */

/* PLATEAU */
    composantes.plateau.position.x = 0;
    composantes.plateau.position.y = 0;
/* PLATEAU */

/* ROBOTS */

 int i;
 for (i=0; i<4; i++){
    composantes.robots[i].type = ROBOT;
    composantes.robots[i].position.x=-50; // Position dehors de l'écran
    composantes.robots[i].position.y=-50; // Position dehors de l'écran
 }

/* OBJECTIF */
    composantes.objectif.type = OBJECTIF;
    composantes.objectif.images = SDL_LoadBMP("images/objectif.bmp");
/* OBJETIF */

//    creerMapRandom(jeu, robots, &ParametresDuJeu);



    menuPrincipal(&composantes, screen, jeu, &ParametresDuJeu);

    releaseImage(composantes.blanc);
    releaseImage(composantes.objectif);
    releaseImage(composantes.plateau);

    for(i=0; i<4; i++)
        releaseImage(composantes.robots[i]);


    SDL_Quit();
    return EXIT_SUCCESS;
}

#include "include.h"

void menuPrincipal(Composantes *composantes, SDL_Surface *screen, Jeu jeu[33][33], Parametres *ParametresDuJeu)
{
    char choix = 'P';
    while (choix != '0')
    {

        composantes->plateau.images = SDL_LoadBMP("images/plateaux/plateauMenu.bmp");
        placeImage(&composantes->plateau, screen);

        Objet unJoueur;
        unJoueur.images = SDL_LoadBMP("images/menus/menuPrincipal/unJoueur.bmp");
        unJoueur.position.x = 100;
        unJoueur.position.y = 100;
        placeImage(&unJoueur, screen);

        Objet  multijoueur;
        multijoueur.images = SDL_LoadBMP("images/menus/menuPrincipal/multijoueur.bmp");
        multijoueur.position.x = 100;
        multijoueur.position.y = 200;
        placeImage(&multijoueur, screen);

        Objet  editeur;
        editeur.images = SDL_LoadBMP("images/menus/menuPrincipal/editeur.bmp");
        editeur.position.x = 100;
        editeur.position.y = 300;
        placeImage(&editeur, screen);


        choix = returnEventMenu();
        switch (choix)
        {
            case '1':
                menuUnJoueur(composantes, screen, jeu, ParametresDuJeu);
                break;

            case '2':
                menuUnJoueur(composantes, screen, jeu, ParametresDuJeu);
                break;

            case '3':
                editeurMap(composantes, screen, jeu, ParametresDuJeu);
                break;
        }
    }
}


char returnEventMenu()
{
    SDL_Event event;
    int keepA=1;
    while(keepA)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                return '0';
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    return '0';
                break;

            case SDL_MOUSEBUTTONUP:
                if( (event.button.x > 100) && (event.button.x < 100+226) && (event.button.y > 100) && (event.button.y < 100+77) )
                    return '1';

                if( (event.button.x > 100) && (event.button.x < 100+226) && (event.button.y > 200) && (event.button.y < 200+77) )
                    return '2';

                if( (event.button.x > 100) && (event.button.x < 100+226) && (event.button.y > 300) && (event.button.y < 300+77) )
                    return '3';

                if( (event.button.x > 100) && (event.button.x < 100+226) && (event.button.y > 400) && (event.button.y < 400+77) )
                    return  '4';
                break;
        }
    }
    return 'N';
}

void menuUnJoueur(Composantes *composantes, SDL_Surface *screen, Jeu jeu[33][33], Parametres *ParametresDuJeu)
{
    Objet facile;
    facile.images = SDL_LoadBMP("images/menus/menuUnJoueur/easy.bmp");
    facile.position.x = 100;
    facile.position.y = 100;
    placeImage(&facile, screen);

    Objet medium;
    medium.images = SDL_LoadBMP("images/menus/menuUnJoueur/medium.bmp");
    medium.position.x = 100;
    medium.position.y = 200;
    placeImage(&medium, screen);

    Objet hard;
    hard.images = SDL_LoadBMP("images/menus/menuUnJoueur/hard.bmp");
    hard.position.x = 100;
    hard.position.y = 300;
    placeImage(&hard, screen);

    Objet random;
    random.images = SDL_LoadBMP("images/menus/menuUnJoueur/random.bmp");
    random.position.x = 100;
    random.position.y = 400;
    placeImage(&random, screen);

    char choix = returnEventMenu();
    switch (choix)
    {
        case '1':
            sprintf(ParametresDuJeu->fichierMap, "map/facile.map");
            jouer(composantes, screen, jeu, ParametresDuJeu);
            break;
        case '2':
            sprintf(ParametresDuJeu->fichierMap, "map/moyen.map");
            jouer(composantes, screen, jeu, ParametresDuJeu);
            break;
        case '3':
            sprintf(ParametresDuJeu->fichierMap, "map/difficile.map");
            jouer(composantes, screen, jeu, ParametresDuJeu);
            break;
        case '4':
            sprintf(ParametresDuJeu->fichierMap, "map/random.map");
            creerMapRandom(jeu, composantes->robots, ParametresDuJeu);
            jouer(composantes, screen, jeu, ParametresDuJeu);
            break;
    }
}
